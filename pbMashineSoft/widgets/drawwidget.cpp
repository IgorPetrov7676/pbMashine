#include "drawwidget.h"
#include "ui_drawwidget.h"

drawWidget::drawWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::drawWidget)
{
    ui->setupUi(this);
    connect(ui->openFileButton,SIGNAL(clicked(bool)), this, SLOT(openFileSlot()));
    Gconverter = new gerberConverter(this);
    Gconverter->setPenDiameter(ui->penSizeSpinBox->value());
    Gconverter->setForce(ui->forceSpinBox->value());
    Gconverter->setZOffset(ui->zPosSpinBox->value());
    Gconverter->setMoveSpeed(ui->moveSpinBox->value());

    connect(ui->penSizeSpinBox, SIGNAL(valueChanged(double)),this,SLOT(penChangeSlot(double)));
    connect(ui->forceSpinBox, SIGNAL(valueChanged(double)),this,SLOT(forceChangeSlot(double)));
    connect(ui->zPosSpinBox, SIGNAL(valueChanged(double)), this, SLOT(zChangeSlot(double)));
    connect(ui->moveSpinBox, SIGNAL(valueChanged(double)), this, SLOT(moveChangeSlot(double)));
    connect(ui->reParseButton, SIGNAL(clicked(bool)), this, SLOT(reParseSlot()));
    connect(ui->runButton, SIGNAL(clicked(bool)), this, SLOT(startSlot()));
    connect(ui->gCodeTextEdit, SIGNAL(updateViewSignal()), ui->vWidget, SLOT(update()));
}
///////////////////////////////////////////////////////////////////////////////////////
void drawWidget::setGerberFile(QFile *file){
    if(!Gconverter->convertGerberCode(file)){//преобразование Gerber файла в G-код
        emit messageSignal(Gconverter->getLastError());
    }
    ui->gCodeTextEdit->setPlainText(Gconverter->getGCode());
}
/////////////////////////////////////////////////////////
drawWidget::~drawWidget()
{
    delete Gconverter;
    delete ui;
}
////////////////////////////////////////////////////////////
void drawWidget::openFileSlot(){
    emit openFileSignal(tr("Gerber файлы (") + "*.gbr)");
}
/////////////////////////////////////////////////////////////
void drawWidget::forceChangeSlot(double value){
    Gconverter->setForce(value);
}
///////////////////////////////////////////////////////////////
void drawWidget::penChangeSlot(double value){
    Gconverter->setPenDiameter(value);
}
//////////////////////////////////////////////////////////////
void drawWidget::zChangeSlot(double value){
    Gconverter->setZOffset(value);
}
//////////////////////////////////////////////////////////////////
void drawWidget::moveChangeSlot(double value){
    Gconverter->setMoveSpeed(value);
}
//////////////////////////////////////////////////////////////////
void drawWidget::reParseSlot(){
    if(!Gconverter->reparseExistGerberCode()){
        emit messageSignal(Gconverter->getLastError());
    }
    else{
        ui->gCodeTextEdit->setPlainText(Gconverter->getGCode());
    }
}
//////////////////////////////////////////////////////////////////////////////
void drawWidget::startSlot(){
    if(ui->showRadioButton->isChecked()){
        if(ui->gCodeTextEdit->getProgramm() != nullptr){

        }
    }
    else if(ui->simulateRadioButton->isChecked()){

    }
    else{
        emit startProgrammSignal(Gconverter->getProgramm());
    }
}
//////////////////////////////////////////////////////////////////////////////
void drawWidget::stopSlot(){

}
/////////////////////////////////////////////////////////////
