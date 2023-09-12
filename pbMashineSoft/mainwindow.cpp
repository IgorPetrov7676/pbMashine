#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    USBPort = new usbConnection(this);
    conIndicator = new connectionIndicator(tr("Plotter"));
    conIndicator->setMinimumSize(30,10);

    portName = new QLabel;
    portName->setText(tr("Порт не подключен."));

    statusBar()->addPermanentWidget(portName,1);
    statusBar()->addPermanentWidget(conIndicator,0);
    statusBar()->setSizeGripEnabled(true);

    penDiametersArray.append(1);

    connect(ui->conntcnAction,SIGNAL(triggered(bool)),this,SLOT(connectSlot()));
    connect(USBPort,SIGNAL(statusSignal(plotterStatus)),this,SLOT(statusSlot(plotterStatus)));
    connect(USBPort,SIGNAL(disconnectedSignal()),this,SLOT(disconnectedSlot()));
    connect(USBPort,SIGNAL(messageSignal(QString)),this,SLOT(messageSlot(QString)));
    connect(ui->DMWidget,SIGNAL(sendGCode(QString)),this,SLOT(sendGCode(QString)));
    connect(ui->DMWidget,SIGNAL(errorSignal(QString)),this,SLOT(errorSlot(QString)));
    connect(ui->DMWidget,SIGNAL(sendProgram(QStringList*)),this,SLOT(sendProgrammSlot(QStringList*)));
    connect(ui->DMWidget,SIGNAL(sendStop()),USBPort,SLOT(sendStopSlot()));
    connect(ui->dWidget,SIGNAL(openFileSignal(QString)),this,SLOT(openSlot(QString)));
    connect(ui->dWidget,SIGNAL(messageSignal(QString)),this,SLOT(messageSlot(QString)));
    connect(ui->dWidget, SIGNAL(startProgrammSignal(QStringList*)), this, SLOT(sendProgrammSlot(QStringList*)));

    distribForms();
}
////////////////////////////////////////////////////////////////////////////////////
MainWindow::~MainWindow()
{
    delete portName;
    delete conIndicator;
    delete ui;
}
////////////////////////////////////////////////////////////////////////////////////
void MainWindow::connectSlot(){
    if(USBPort->isConnected()){
        USBPort->disconnectPort();
        ui->conntcnAction->setText("Подключиться");
    }
    else{
        if(USBPort->connectPort()){
            ui->consoleWidget->addString("Подключение");
            ui->conntcnAction->setText("Отключиться");
        }
    }
}
/////////////////////////////////////////////////////////////////////////////////////////
void MainWindow::statusSlot(plotterStatus status){
    conIndicator->setState(true);
    ui->DMWidget->setPlotterStatus(status);
    portName->setText(USBPort->getCurrentPortName());
    ui->DMWidget->setSwitchStatus(status.swX,status.swY,status.swZ);
    if(status.plotterError != 0){
        ui->consoleWidget->addString(tr("Ошибка контроллера: ") + errorClass::getErrorString(status.plotterError));
    }
}
///////////////////////////////////////////////////////////////////////////////////////
void MainWindow::disconnectedSlot(){
    conIndicator->setState(false);
    ui->consoleWidget->addString("Отключение");
}
///////////////////////////////////////////////////////////////////////////////////////////
void MainWindow::sendGCode(QString gCode){
    USBPort->sendGCode(gCode);
    ui->consoleWidget->addString("Код " + gCode + " отправлен в контроллер.");
}
////////////////////////////////////////////////////////////////////////////////////////////
void MainWindow::sendProgrammSlot(QStringList *program){
    USBPort->runProgram(program);
    ui->consoleWidget->addString("Программа отправлена в контроллер");
}
//////////////////////////////////////////////////////////////////////////////////////////////
void MainWindow::openSlot(QString fileType){
    QFileDialog dialog(this);
    dialog.setViewMode(QFileDialog::Detail);
    dialog.setNameFilter(fileType);
    QString lastPath = readConfigParameter("lastPath");
    dialog.setDirectory(lastPath);//получаем последний использованный путь из .conf файла
    if(dialog.exec() == QDialog::Accepted){
        QString fileName=dialog.selectedFiles().at(0);
        if(!fileName.isEmpty()){
            writeConfigParameter("lastPath", dialog.directory().absolutePath() + "/");//сохраняем путь, чтобы в дальнейшем не искать
            QFile file(fileName);
            if(!file.open(QIODevice::ReadOnly)){
                errorSlot(file.errorString(),tr("Ошибка открытия файла ")+file.fileName());
                return;
            }
            ui->consoleWidget->addString("Файл " + fileName + " открыт.");
            ui->dWidget->setGerberFile(&file);
            file.close();
        }
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////
void MainWindow::updateViewSlot(){

}
//////////////////////////////////////////////////////////////////////////////////////////////
void MainWindow::errorSlot(QString error, QString title){
    QMessageBox box(this);
    box.setIcon(QMessageBox::Critical);
    if(title != nullptr){
        box.setWindowTitle(title);
    }
    else{
        box.setWindowTitle("Ошибка");
    }
    box.setStandardButtons(QMessageBox::Ok);
    box.setText(error);
    box.exec();
    ui->consoleWidget->addString(error);
}
//////////////////////////////////////////////////////////////////////////////////////////////
void MainWindow::stopSlot(){
    USBPort->stopProgram();
    ui->consoleWidget->addString("Останов программы");
}
/////////////////////////////////////////////////////////////////////////////////////////////
void MainWindow::pauseSlot(){
    USBPort->pauseProgram();
    ui->consoleWidget->addString("Пауза");
}
/////////////////////////////////////////////////////////////////////////////////////////////
void MainWindow::messageSlot(QString message){
    ui->consoleWidget->addString(message);
}
///////////////////////////////////////////////////////////////////////////////////////////////
void MainWindow::distribForms(){
    ui->penDSpinBox->setValue(1);
    ui->ZSpinBox->setValue(-10);
    ui->FSpinBox->setValue(0.5);
    ui->FMSpinBox->setValue(2);
}
///////////////////////////////////////////////////////////////////////////////////////////////
void MainWindow::writeConfigParameter(QString parameter, QString value){
    QString path = QApplication::applicationDirPath();
    QFile file(path + "/config.cfg");
    if(file.open(QIODevice::ReadWrite)){
        QByteArray array = file.readAll();
        QString str(array.data());
        int pos = str.indexOf(parameter);
        if(pos != -1){
            int endLine = str.indexOf("\n",pos);
            str.remove(pos, endLine - pos + 1);
        }
        else{
            pos = str.size();
        }
        str.insert(pos, parameter + " " + value + "\r\n");
        file.seek(0);
        array = str.toLatin1();
        file.resize(array.size());
        file.write(array);
        file.close();
    }
    else{
        QMessageBox box(this);
        box.setDefaultButton(QMessageBox::Ok);
        box.setText(tr("Невозможно открыть файл конфигурации \n") + file.fileName());
        box.setIcon(QMessageBox::Warning);
        ui->consoleWidget->addString(box.text());
        box.exec();
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////
QString MainWindow::readConfigParameter(QString parameter){
    QString path = QApplication::applicationDirPath();
    QFile file(path + "/config.cfg");
    if(file.open(QIODevice::ReadWrite)){
        QByteArray array = file.readAll();
        QString str(array.data());
        int pos = str.indexOf(parameter);
        int endLine = str.indexOf("\r",pos);
        int spacePos = str.indexOf(" ",pos);
        QString value = str.mid(spacePos + 1, endLine - spacePos);
        return value;
    }
    else{
        QMessageBox box(this);
        box.setDefaultButton(QMessageBox::Ok);
        box.setText(tr("Невозможно открыть файл конфигурации \n") + file.fileName());
        box.setIcon(QMessageBox::Warning);
        ui->consoleWidget->addString(box.text());
        box.exec();
    }
    return QString();
}
