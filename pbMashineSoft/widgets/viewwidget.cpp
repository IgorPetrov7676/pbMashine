#include "viewwidget.h"
#include "ui_viewwidget.h"

viewWidget::viewWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::viewWidget)
{
    ui->setupUi(this);
    converterPointer = nullptr;
    scaleX = 1;
    scaleY = 1;
    translateX = 0;
    translateY = 0;
    mousePosX = 0;
    mousePosY = 0;
    currentPositionX = 0;
    currentPositionY = 0;
    currentPositionZ = 0;
    relativeCoordinates = 1;//по умолчанию относительные координаты, как в машине
    setMouseTracking(true);
}
//////////////////////////////////////////////////////////////////////////////////
void viewWidget::drawRawData(gerberConverter *converter){
    converterPointer = converter;
    update();
}
//////////////////////////////////////////////////////////////////////
viewWidget::~viewWidget()
{
    delete ui;
}
////////////////////////////////////////////////////////////////////////////////
bool viewWidget::parseCommand(QString *command){
//    switch(&command->data()[0]){
//        case(71):{//команда G
//            parseGCode(command);
//            break;
//        }
//        case(77):{//команда М
//            parseMCode(command);
//            break;
//        }
//        default:{
//            return false;
//        }
//    }
}
////////////////////////////////////////////////////////////////////////////////
bool viewWidget::parseGCode(QString *command){

//    //читаем номер команды
//    int tmp = (int)(array[0]);
//    if(isdigit(tmp)!=0){//первый символ в массиве должен быть числом. Символ G отстрелили в вызывающей функции
//        command.GCode = atoi(array);
//    }
//    else{//иначе ошибка. todo потом добавить фиксацию ошибки
//        return;
//    }

//    //читаем координату Х
//    int symbol = 'X';
//    char *pos = strchr(array, symbol);
//    if(pos != 0){
//        command.posX = (int)(atof(pos + 1) * 10);
//        command.reliability |= (1 << 0);
//    }

//    //читаем координату Y
//    symbol = 'Y';
//    pos = strchr(array, symbol);
//    if(pos != 0){
//        command.posY = (int)(atof(pos + 1) * 10);
//        command.reliability |= (1 << 1);
//    }

//    //читаем координату Z
//    symbol = 'Z';
//    pos = strchr(array,symbol);
//    if(pos != NULL){
//        command.posZ = (int)(atof(pos + 1) * 10);
//        command.reliability |= (1 << 2);
//    }

//    //читаем параметр F
//    symbol = 'F';
//    pos = strchr(array,symbol);
//    if(pos != 0){
//        command.F = (int)(atof(pos + 1) * 10);
//        command.reliability |= (1 << 3);
//    }

//    //читаем параметр R
//    symbol = 'R';
//    pos = strchr(array, symbol);
//    if(pos != 0){
//        command.R = (int)(atof(pos + 1) * 10);
//        command.reliability |= (1 << 4);
//    }

//    //читаем параметр I
//    symbol = 'I';
//    pos = strchr(array, symbol);
//    if(pos != 0){
//        command.I = (float)(atof(pos + 1) * 10);
//        command.reliability |= (1 << 5);
//    }

//    //читаем параметр J
//    symbol = 'J';
//    pos = strchr(array, symbol);
//    if(pos != 0){
//        command.J = (float)(atof(pos + 1) * 10);
//        command.reliability |= (1 << 6);
//    }
}
///////////////////////////////////////////////////////////////////////////
bool viewWidget::parseMCode(QString *command){

}
///////////////////////////////////////////////////////////////////////////
void viewWidget::paintEvent(QPaintEvent*){
    QPainter painter(this);
    QPen pen;
    //рисуем рамку
    pen.setColor(QColor(0,0,0));
    pen.setWidth(1);
    painter.setPen(pen);
    painter.drawLine(1,1,this->width()-1,1);
    painter.drawLine(this->width()-1,1,this->width()-1,this->height()-1);
    painter.drawLine(this->width()-1,this->height()-1,1,this->height()-1);
    painter.drawLine(1,this->height()-1,1,1);
    painter.drawText(100,10,"scaleX= "+QString::number(scaleX));
    painter.drawText(100,20,"scaleY= "+QString::number(scaleY));
    painter.drawText(100,30,"translateX= "+QString::number(translateX));
    painter.drawText(100,40,"translateY= "+QString::number(translateY));

    painter.scale(scaleX,scaleY);
    painter.translate(translateX,translateY);
    painter.setPen(pen);

    //для отрисовки сырых данных
//    if(converterPointer!=nullptr){
//        QVector<pad*> *padsArray = converterPointer->getPadsArray();
//        QVector<GPath*> *pathsArray=converterPointer->getPathsArray();

//        int pathsSize=pathsArray->size();

//        for(int n=0;n!=pathsSize;n++){
//            GPath *path=pathsArray->at(n);
//            QVector<QPointF> *pointsArray=path->getPointsArray();
//            int lines=path->getPointsCount()-1;
//            for(int m=0;m!=lines;m++){
//                painter.drawLine(pointsArray->at(m)*scaleX,pointsArray->at(m+1)*scaleX);
//            }
//        }
//    }

}
///////////////////////////////////////////////////////////////////////////
void viewWidget::wheelEvent(QWheelEvent *event){
    QPoint s=event->angleDelta();
    if(s.y()>0){
        scaleX+=0.1;
        scaleY+=0.1;
    }
    else if(s.y()<0){
        scaleX-=0.1;
        scaleY-=0.1;
    }
    update();
}
////////////////////////////////////////////////////////////////////////////////
void viewWidget::mouseMoveEvent(QMouseEvent *event){
    if(event->buttons() == Qt::LeftButton){

#if QT_VERSION >= 0x060000
        int x = event->position().x() - mousePosX;
        int y = event->position().y() - mousePosY;
#else
        int x = event->x() - mousePosX;
        int y = event->y() - mousePosY;
#endif

        if(x > 0){
            translateX += 5;
        }
        else{
            translateX -= 5;
        }
        if(y > 0){
            translateY += 5;
        }
        else{
            translateY -= 5;
        }

        update();
    }
#if QT_VERSION >= 0x060000
    mousePosX = event->position().x();
    mousePosY = event->position().y();
#else
    mousePosX = event->x();
    mousePosY = event->y();
#endif
}
///////////////////////////////////////////////////////////////////////////////////
void viewWidget::mousePressEvent(QMouseEvent *event){

}
//////////////////////////////////////////////////////////////////////////////////
void viewWidget::clearAll(){
    converterPointer = nullptr;
    scaleX = 1;
    scaleY = 1;
    translateX = 0;
    translateY = 0;
}
//////////////////////////////////////////////////////////////////////////
void viewWidget::executeNextCommand(QString *command){
    //парсим команду




}
//////////////////////////////////////////////////////////////////////////////
void viewWidget::showDrawing(QStringList *gProgramm){
    int size = gProgramm->size();

    for(int n = 0; n != size; n++){
        //executeNextCommand(QString *y);
    }
}
