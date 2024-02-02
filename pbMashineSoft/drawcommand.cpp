#include "drawcommand.h"

drawCommand::drawCommand(){
    type=COMMAND_NO_TYPE;
    currentX=0;
    currentY=0;
    currentZ=0;
    moveX=0;
    moveY=0;
    moveZ=0;
    penDiameter=0;
    I=0;
    J=0;
    K=0;
    R=0;
    number=0;
    multiplier=10;
    isNumber=false;
    isMX=false;
    isMY=false;
    isMZ=false;
    isI=false;
    isJ=false;
    isK=false;
    isR=false;
    shine=false;
}
//////////////////////////////////////////////////////////////////////////////
commandType drawCommand::getType() const{
    return type;
}
////////////////////////////////////////////////////////////////////////////////
void drawCommand::setType(const commandType &value){
    type = value;
}
/////////////////////////////////////////////////////////////////////////////////
void drawCommand::setCurrentX(float value){
    int tmp=static_cast<int>(round(value*10));
    if(!isMX){//если кордината Х перемещения не задана, то она равна начальной позиции. возможно будет задана позже
        moveX=tmp;
    }
    currentX = tmp;
}
/////////////////////////////////////////////////////////////////////////////////
void drawCommand::setCurrentY(float value){
    int tmp=static_cast<int>(round(value*10));
    if(!isMY){//если кордината Y перемещения не задана, то она равна начальной позиции. возможно будет задана позже
        moveY=tmp;
    }
    currentY = tmp;
}
/////////////////////////////////////////////////////////////////////////////////
void drawCommand::setCurrentZ(float value){
    int tmp=static_cast<int>(round(value*10));
    if(!isMZ){//если кордината Z перемещения не задана, то она равна начальной позиции. возможно будет задана позже
        moveZ=tmp;
    }
    currentZ = tmp;
}
////////////////////////////////////////////////////////////////////////////////
int drawCommand::getNumber() const{
    return number;
}
//////////////////////////////////////////////////////////////////////////////////
float drawCommand::getForce() const{
    return force;
}
/////////////////////////////////////////////////////////////////////////////////
void drawCommand::setI(float value){
    I = value*10;
    isI=true;
    isR=false;
}
///////////////////////////////////////////////////////////////////////////////////
void drawCommand::setJ(float value){
    J = value*10;
    isJ=true;
    isR=false;
}
///////////////////////////////////////////////////////////////////////////////////
void drawCommand::setK(float value){
    K = value*10;
    isK=true;
    isR=false;
}
///////////////////////////////////////////////////////////////////////////////////
void drawCommand::setR(float value){
    R = value*10;
    isR=true;
    isI=false;
    isJ=false;
    isK=false;
}
/////////////////////////////////////////////////////////////////////////////////
void drawCommand::draw(QPainter *painter){
    QPen pen;
    //checkCommand();
    switch(type){
        case(COMMAND_MOVE):{
//            pen.setColor(QColor(0,0,250));
//            pen.setWidth(1);
//            painter->setPen(pen);
//            painter->drawLine(currentX,currentY,moveX,moveY);
            break;
        }
        case(COMMAND_LINE):{
            if(shine){
                pen.setColor(QColor(Qt::red));
                pen.setWidth(3);
            }
            else{
                pen.setColor(QColor(Qt::black));
                pen.setWidth(penDiameter);
            }
            painter->setPen(pen);
            painter->drawLine(currentX,currentY,moveX,moveY);
            break;
        }
        case(COMMAND_ARC_RCW):{
            if(shine){
                pen.setColor(QColor(Qt::red));
                pen.setWidth(penDiameter*10);
            }
            else{
                pen.setColor(QColor(Qt::black));
                pen.setWidth(penDiameter);
            }
            painter->setPen(pen);
            drawArc(painter);
            break;
        }
        case(COMMAND_ARC_FCW):{
            if(shine){
                pen.setColor(QColor(Qt::red));
                pen.setWidth(penDiameter*10);
            }
            else{
                pen.setColor(QColor(Qt::black));
                pen.setWidth(penDiameter);
            }
            painter->setPen(pen);
            drawArc(painter);
            break;
        }
        default:{
            return;
        }
    }
}
////////////////////////////////////////////////////////////////////////////////
void drawCommand::setPenDiameter(float value){
    int tmp=static_cast<int>(round(value));
    penDiameter = tmp;
}
////////////////////////////////////////////////////////////////////////////////
void drawCommand::setShine(bool s){
    shine=s;
}
/////////////////////////////////////////////////////////////////////////////////
QRect drawCommand::calcArcRect(){
    float centerX = currentX + I;
    float centerY = currentY + J;
    float radius = sqrt((I * I) + (J * J));
    float ltX = centerX - radius;
    float ltY = centerY - radius;
    float wigth = 2 * radius;
    float heigth = 2 * radius;
    QRect rect(static_cast<int>(round(ltX)), static_cast<int>(round(ltY)), static_cast<int>(round(wigth)), static_cast<int>(round(heigth)));
    return rect;
}
/////////////////////////////////////////////////////////////////////////////////
void drawCommand::drawArc(QPainter *painter){
    QRect rect = calcArcRect();
//    QPoint pointStart(currentX, currentY);
//    QPoint center(currentX + I, currentY + J);
//    QPoint pointEnd(currentX + moveX, currentY + moveY);
//    QVector2D vector1(center - pointStart);
//    vector1.normalize();
//    QVector2D vector2(center - pointEnd);
//    vector2.normalize();
//    QVector2D vector3(QPoint(1, 0));//вектор на 3 часа
//    float angle1 = acos(QVector2D::dotProduct(vector1, vector3)) * (180 / 3.141592653589793);
//    float angle2 = acos(QVector2D::dotProduct(vector2, vector3)) * (180 / 3.141592653589793);
    //painter->drawArc(rect,0 - (16 * angle1),16 * (360 - (angle1 - angle2)));

    painter->drawArc(rect,(16 * 0),16 * (270));


}
//////////////////////////////////////////////////////////////////////////////////////////////
void drawCommand::checkCommand(){
    if(!isMX){//если конечный Х явно не указан, то он равен предыдущему
        moveX=currentX;
    }
    if(!isMY){//если конечный Y явно не указан, то он равен предыдущему
        moveY=currentY;
    }
    if(!isMZ){//если конечный Х явно не указан, то он равен предыдущему
        moveZ=currentZ;
    }
}
////////////////////////////////////////////////////////////////////////////////
void drawCommand::setNumber(int value){
    isNumber=true;
    number = value;
}
///////////////////////////////////////////////////////////////////////////////
void drawCommand::setMoveX(float value){
    int tmp=static_cast<int>(round(value*10));
    isMX=true;
    moveX = tmp;
}
////////////////////////////////////////////////////////////////////////////////
void drawCommand::setMoveY(float value){
    int tmp=static_cast<int>(round(value*10));
    isMY=true;
    moveY = tmp;
}
///////////////////////////////////////////////////////////////////////////////
void drawCommand::setMoveZ(float value){
    int tmp=static_cast<int>(round(value*10));
    isMZ=true;
    moveZ = tmp;
}
/////////////////////////////////////////////////////////////////////////////
void drawCommand::setForce(float value){
    force = value;
}
