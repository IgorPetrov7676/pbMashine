 #include "directmanagewidget.h"
#include "ui_directmanagewidget.h"

directManageWidget::directManageWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::directManageWidget)
{
    ui->setupUi(this);

    ui->Xm01Button->setGCode("G00 X-0.1");
    ui->Xm1Button->setGCode("G00 X-1");
    ui->Xm10Button->setGCode("G00 X-10");
    ui->Xp01Button->setGCode("G00 X0.1");
    ui->Xp1Button->setGCode("G00 X1");
    ui->Xp10Button->setGCode("G00 X10");

    ui->Ym01Button->setGCode("G00 Y-0.1");
    ui->Ym1Button->setGCode("G00 Y-1");
    ui->Ym10Button->setGCode("G00 Y-10");
    ui->Yp01Button->setGCode("G00 Y0.1");
    ui->Yp1Button->setGCode("G00 Y1");
    ui->Yp10Button->setGCode("G00 Y10");

    ui->Zm01Button->setGCode("G00 Z-0.1");
    ui->Zm1Button->setGCode("G00 Z-1");
    ui->Zm10Button->setGCode("G00 Z-10");
    ui->Zp01Button->setGCode("G00 Z0.1");
    ui->Zp1Button->setGCode("G00 Z1");
    ui->Zp10Button->setGCode("G00 Z10");

    ui->zeroAllButton->setGCode("G92 X0 Y0 Z0");
    ui->zeroXButton->setGCode("G92 X0");
    ui->zeroYButton->setGCode("G92 Y0");
    ui->zeroZButton->setGCode("G92 Z0");

    ui->speedSpinBox->setValue(4);

    connect(ui->refPosButton,SIGNAL(clicked(bool)),this,SLOT(moveRefSlot()));
    connect(ui->zeroPosButton,SIGNAL(clicked(bool)),this, SLOT(moveZeroSlot()));
    connect(ui->zeroAllButton,SIGNAL(clickedSignal(GPushButton*)),this,SLOT(setZeroSlot(GPushButton*)));
    connect(ui->zeroXButton,SIGNAL(clickedSignal(GPushButton*)),this,SLOT(setZeroSlot(GPushButton*)));
    connect(ui->zeroYButton,SIGNAL(clickedSignal(GPushButton*)),this,SLOT(setZeroSlot(GPushButton*)));
    connect(ui->zeroZButton,SIGNAL(clickedSignal(GPushButton*)),this,SLOT(setZeroSlot(GPushButton*)));
    connect(ui->disSteppersButton,SIGNAL(clicked(bool)),this,SLOT(diableSteppersSlot()));
    connect(ui->sendGCode,SIGNAL(clicked(bool)),this,SLOT(sendGCodeSlot()));
    connect(ui->stopButton,SIGNAL(clicked(bool)),this,SLOT(emegencyStopSlot()));
    connect(ui->setEndPosButton,SIGNAL(clicked(bool)),this,SLOT(setEndPosSlot()));
    connect(ui->drawWorkZoneButton,SIGNAL(clicked(bool)),this,SLOT(drawWorkZoneSlot()));
    connect(ui->resetWorkZoneButton,SIGNAL(clicked(bool)),this,SLOT(resetWorkZoneSlot()));

    connect(ui->Xm01Button,SIGNAL(clickedSignal(GPushButton*)),this,SLOT(directMoveButtonSlot(GPushButton*)));
    connect(ui->Xm1Button,SIGNAL(clickedSignal(GPushButton*)),this,SLOT(directMoveButtonSlot(GPushButton*)));
    connect(ui->Xm10Button,SIGNAL(clickedSignal(GPushButton*)),this,SLOT(directMoveButtonSlot(GPushButton*)));
    connect(ui->Xp01Button,SIGNAL(clickedSignal(GPushButton*)),this,SLOT(directMoveButtonSlot(GPushButton*)));
    connect(ui->Xp1Button,SIGNAL(clickedSignal(GPushButton*)),this,SLOT(directMoveButtonSlot(GPushButton*)));
    connect(ui->Xp10Button,SIGNAL(clickedSignal(GPushButton*)),this,SLOT(directMoveButtonSlot(GPushButton*)));

    connect(ui->Ym01Button,SIGNAL(clickedSignal(GPushButton*)),this,SLOT(directMoveButtonSlot(GPushButton*)));
    connect(ui->Ym1Button,SIGNAL(clickedSignal(GPushButton*)),this,SLOT(directMoveButtonSlot(GPushButton*)));
    connect(ui->Ym10Button,SIGNAL(clickedSignal(GPushButton*)),this,SLOT(directMoveButtonSlot(GPushButton*)));
    connect(ui->Yp01Button,SIGNAL(clickedSignal(GPushButton*)),this,SLOT(directMoveButtonSlot(GPushButton*)));
    connect(ui->Yp1Button,SIGNAL(clickedSignal(GPushButton*)),this,SLOT(directMoveButtonSlot(GPushButton*)));
    connect(ui->Yp10Button,SIGNAL(clickedSignal(GPushButton*)),this,SLOT(directMoveButtonSlot(GPushButton*)));

    connect(ui->Zm01Button,SIGNAL(clickedSignal(GPushButton*)),this,SLOT(directMoveButtonSlot(GPushButton*)));
    connect(ui->Zm1Button,SIGNAL(clickedSignal(GPushButton*)),this,SLOT(directMoveButtonSlot(GPushButton*)));
    connect(ui->Zm10Button,SIGNAL(clickedSignal(GPushButton*)),this,SLOT(directMoveButtonSlot(GPushButton*)));
    connect(ui->Zp01Button,SIGNAL(clickedSignal(GPushButton*)),this,SLOT(directMoveButtonSlot(GPushButton*)));
    connect(ui->Zp1Button,SIGNAL(clickedSignal(GPushButton*)),this,SLOT(directMoveButtonSlot(GPushButton*)));
    connect(ui->Zp10Button,SIGNAL(clickedSignal(GPushButton*)),this,SLOT(directMoveButtonSlot(GPushButton*)));

    error = false;
}
///////////////////////////////////////////////////////////////////////////
directManageWidget::~directManageWidget(){
    delete ui;
}
/////////////////////////////////////////////////////////////////////////////
void directManageWidget::setPlotterStatus(plotterStatus status){
    ui->posXLable->setText(QString::number(status.posX));
    ui->posYLable->setText(QString::number(status.posY));
    ui->posZLable->setText(QString::number(status.posZ));
    ui->endPosXLable->setText((QString::number(status.endPosX)));
    ui->endPosYLable->setText((QString::number(status.endPosY)));
    ui->endPosZLable->setText((QString::number(status.endPosZ)));
    ui->speedLable->setText((QString::number(status.Force)));
}
////////////////////////////////////////////////////////////////////////////////////
void directManageWidget::setSwitchStatus(bool X, bool Y, bool Z){
    if(X){
        ui->swXLable->setText("Замкнут");
    }
    else{
        ui->swXLable->setText("Разомкнут");
    }

    if(Y){
        ui->swYLable->setText("Замкнут");
    }
    else{
        ui->swYLable->setText("Разомкнут");
    }

    if(Z){
        ui->swZLable->setText("Замкнут");
    }
    else{
        ui->swZLable->setText("Разомкнут");
    }
}
//////////////////////////////////////////////////////////////////////////////////
void directManageWidget::setWorkRect(QRectF rect){



}
///////////////////////////////////////////////////////////////////////////////////
bool directManageWidget::checkG01FromGLine(){
    bool ok = checkXYZFromGLine();
    if(!ok){
        emit errorSignal("Для команд G00 и G01 дожен быть хотябы один параметр X, Y или Z.");
    }
    return ok;
}
/////////////////////////////////////////////////////////////////////////////
bool directManageWidget::checkG0203FromGLine(){
    bool ok = false;
    int IJOk = 0;
    bool ROk = false;

    ok = checkXYZFromGLine();//X Y Z может не быть, но проверить на правильность все равно надо
    if(checkParameterFromGLine("I")){
        IJOk++;
    }
    if(checkParameterFromGLine("J")){
        IJOk++;
    }
    ROk = checkParameterFromGLine("R");

    if((IJOk > 0) || ROk){//если присутствуют или IJ или R
        return true;
    }
    error = true;
    errorSignal("В командах G02 и G03 должны быть или значения IJ или R.");
    return false;
}
//////////////////////////////////////////////////////////////////////////////
bool directManageWidget::checkXYZFromGLine(){
    int tmp=0;

    if(checkParameterFromGLine("X")){
        tmp++;
    }
    if(checkParameterFromGLine("Y")){
        tmp++;
    }
    if(checkParameterFromGLine("Z")){
        tmp++;
    }

    if(tmp > 0){
        return true;
    }
    return false;//поиск и проверка хотябы одной координаты должны выставить ok в значение true
}
//////////////////////////////////////////////////////////////////////////////////
bool directManageWidget::checkParameterFromGLine(QString parameter){
    bool ok = false;
    int bIndex = 0;
    int eIndex = 0;
    bIndex = ui->GlineEdit->text().indexOf(parameter,0);//ищем координату X
    if(bIndex != -1){//если нашли
        eIndex = ui->GlineEdit->text().indexOf(" ",bIndex);//то ищем пробел
        if(eIndex == -1){//если пробела не нашли
            eIndex = ui->GlineEdit->text().size()-1;//то ищем до конца строки
        }
        QString coord = ui->GlineEdit->text().mid(bIndex+1,eIndex-bIndex);
        coord.toFloat(&ok);
        if(!ok){
            emit errorSignal("Ошибка в значении " + parameter + ". Символы не являются числом.");
            error = true;
        }
        return ok;
    }
    return false;
}
/////////////////////////////////////////////////////////////////////////////
void directManageWidget::moveRefSlot(){
    QString tmp = "G28 F" + QString::number(ui->speedSpinBox->value() * 10);
    emit sendGCode(tmp);
}
///////////////////////////////////////////////////////////////////////////////
void directManageWidget::moveZeroSlot(){
    QStringList program;
    program << "G90";
    QString tmp = "G0 X0 Y0 Z0 F" + QString::number(ui->speedSpinBox->value() * 10);
    program << tmp << "G91";
    emit sendProgram(&program);
}
/////////////////////////////////////////////////////////////////////////////
void directManageWidget::setZeroSlot(GPushButton* button){
    emit sendGCode(button->getGCode().at(1));
}
///////////////////////////////////////////////////////////////////////////////////
void directManageWidget::diableSteppersSlot(){
    emit sendGCode("M18");
}
//////////////////////////////////////////////////////////////////////////////////////
void directManageWidget::sendGCodeSlot(){
    //error = false;
    //проверка на допустимые символы
    int pos = ui->GlineEdit->text().indexOf(QRegularExpression("[^GMXYZ0-9.IJREF -]"),0);
    if(pos != -1){
        emit errorSignal("Символ " + ui->GlineEdit->text().mid(pos,1) + " недопустим.");
        return;
    }

    if(ui->GlineEdit->text().at(0) == 'G'){
        QString tmp = ui->GlineEdit->text().mid(1,2);
        bool ok = false;
        int command = tmp.toInt(&ok);
        if(ok){
            ok = false;
            switch(command){
                case(0):{
                    ok = checkG01FromGLine();
                    break;
                }
                case(1):{
                    ok = checkG01FromGLine();
                    break;
                }
                case(2):{
                    ok = checkG0203FromGLine();
                    break;
                }
                case(3):{
                    ok = checkG0203FromGLine();
                    break;
                }
                case(91):{
                    ok = true;
                    break;
                }
                case(90):{
                    ok = true;
                    break;
                }
                default:{
                    emit errorSignal("Команда G" + ui->GlineEdit->text().mid(1,2) + " не поддерживается!");
                }
            }
            if(ok){
                if(!error){
                    if(!checkParameterFromGLine("F")){//если в строке нет параметра F
                        ui->GlineEdit->setText(ui->GlineEdit->text()+" F"+QString::number(ui->speedSpinBox->value()));//то добавляем
                    }
                    emit sendGCode(ui->GlineEdit->text());
                }
            }
        }
        else{
            emit errorSignal("Символы " + ui->GlineEdit->text().mid(1,2) + " не являются числом!");
        }
    }
    else if(ui->GlineEdit->text().at(0) == 'M'){
        QString tmp = ui->GlineEdit->text().mid(1,2);
        bool ok = false;
        int command = tmp.toInt(&ok);
        if(command == 18){
            emit sendGCode(ui->GlineEdit->text());
        }
    }
    else{
        emit errorSignal("Символ " + ui->GlineEdit->text().mid(0,1) + " не является командой!");
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void directManageWidget::directMoveButtonSlot(GPushButton *pointer){
    QStringList code = pointer->getGCode();
    code[1] = code.at(1) + " F" + QString::number(ui->speedSpinBox->value() * 10);
    emit sendProgram(&code);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void directManageWidget::rectMoveButtonSlot(GPushButton *pointer){
    QStringList code = pointer->getGCode();
    emit sendGCode(code.at(1));//запускаем только среднюю строку без команд перевода системы координат
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void directManageWidget::emegencyStopSlot(){
    emit sendStop();
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void directManageWidget::setEndPosSlot(){
    emit sendGCode("M50");
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void directManageWidget::drawWorkZoneSlot(){
    QMessageBox box(this);
    box.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    box.setIcon(QMessageBox::Question);
    box.setWindowTitle(tr("Отрисовка периметра рабочей зоны."));
    box.setText(tr("Начать отрисовку периматра рабочей зоны?"));
    if(box.exec() == QMessageBox::Ok){
        emit sendGCode("G79 F" + QString::number(ui->speedSpinBox->value() * 10));
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void directManageWidget::resetWorkZoneSlot(){
    emit sendGCode("M51");
}
///////////////////////////////////////////////////////////////////////////////


