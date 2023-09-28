#include "pad.h"

pad::pad()
{

}
////////////////////////////////////////////////////////////
void pad::setX(float value){
    X = round(value*10)/10;
}
///////////////////////////////////////////////////////////////////
void pad::setY(float value){
    Y = round(value*10)/10;
}
///////////////////////////////////////////////////////////////////
void pad::setApp(apperture *value){
    app = value;
}
////////////////////////////////////////////////////////////////////
QStringList pad::calcGCode(float penDiameter, float force, float moveSpeed, float zOffset){
    QStringList tmpProg;
    float penRadius = round((penDiameter / 2) * 10) / 10;

    switch(app->getType()){
        case(APP_CYCLE):{
            int lines=(app->getXSize()/2)/(penDiameter/2);//количество целых линий
            float lastLineOffset=(app->getXSize()/2)-(penDiameter/2*lines);//смещение последней линии
            lastLineOffset = round(lastLineOffset * 10) / 10;
            //например, если размер Pad-а 2.2мм, а диаметр пера 1мм, то смещение последней линии будет 0.2мм
            tmpProg.append("G00 X"+QString::number(X)+" Y"+QString::number(Y)+" F"+QString::number(moveSpeed) + "\n");//смещаем инструмент в позицию
            tmpProg.append("G00 Z"+QString::number(zOffset)+" F"+QString::number(moveSpeed)+"\n");//опускаем в позицию рисования, делаем точку
            int n=1;
            float centerY=0;
            for(;n!=lines+1;n++){//рисуем концентрические окружности до заполнения PAD-а
                centerY += penDiameter / 2;//stt
                tmpProg.append("G01 Y"+QString::number(Y + centerY) + " F" + QString::number(force) + "\n");//смещаем по Y на величину диаметра
                tmpProg.append("G91\n");//временно переключаемся на относительные координаты
                tmpProg.append("G02 X0 Y0 I0 J" + QString::number(0 - centerY) + "\n");
                tmpProg.append("G90\n");//обратно на абсолютные координаты
            }
            if(lastLineOffset!=0){
                tmpProg.append("G01 Y"+QString::number(Y + centerY + lastLineOffset) + "\n");//смещаем по Y на величину диаметра
                tmpProg.append("G91\n");//временно переключаемся на относительные координаты
                tmpProg.append("G02 X0 Y0 I0 J" + QString::number(0 - (centerY + lastLineOffset))+"\n");
                tmpProg.append("G90\n");//обратно на абсолютные координаты
            }
            tmpProg.append("G00 Z"+QString::number(0)+" F"+QString::number(moveSpeed)+"\n");
            break;
        }
        case(APP_OVAL):{
            int lines = 0;
            float lastLineOffset = 0;
            float center1 = 0;//смещения центров дуг верхней/нижней или правой/левой
            float center2 = 0;
            float centerOffset = 0;
            //количество линий считаем по наименьшему размеру
            if(app->getXSize() > app->getYSize()){//горизонтальный овал
                lines = (app->getYSize() / 2)/(penDiameter/2);//количество целых линий
                lastLineOffset=(app->getYSize()/2)-(penDiameter/2*lines);//смещение последней линии
                lastLineOffset = round(lastLineOffset*10)/10;//округляем до одного знака после запятой
                //например, если размер Pad-а 2.2мм, а диаметр пера 1мм, то смещение последней линии будет 0.1мм
                float halfSize = app->getXSize() / 2;
                float step = 0;
                centerOffset = halfSize - ((lines*penRadius) + lastLineOffset);
                centerOffset = round(centerOffset * 10) / 10;
                center1 = X + centerOffset;
                center2 = X - centerOffset;
                tmpProg.append("G00 X"+QString::number(center1)+" Y"+QString::number(Y)+" F"+QString::number(moveSpeed)+"\n");//смещаем инструмент в позицию
                tmpProg.append("G00 Z"+QString::number(0)+" F"+QString::number(moveSpeed)+"\n");//опускаем в позицию рисования, делаем точку
                tmpProg.append("G91\n");//временно переключаемся на относительные координаты
                tmpProg.append("G01 X"+QString::number(center2)+" F"+QString::number(force) + "\n");//рисуем центральную линию
                for(int n = 1; n != lines + 1; n++){//рисуем овалы по количеству линий
                    step = penRadius * n;
                    tmpProg.append("G01 Y"+QString::number(Y+step)+"\n");//смещение на радиус пера по Y
                    tmpProg.append("G03 Y"+QString::number(Y-step)+" J"+QString::number(-step)+"\n");//дуга слева
                    tmpProg.append("G01 X"+QString::number(center1)+"\n");//верхняя линия
                    tmpProg.append("G02 Y"+QString::number(Y+step)+" J"+QString::number(step)+"\n");//дуга справа
                    tmpProg.append("G01 X"+QString::number(center2)+"\n");//нижняя линия
                }
                if(lastLineOffset!=0){
                    tmpProg.append("G01 Y"+QString::number(Y+step+lastLineOffset)+"\n");//смещение на радиус пера по Y
                    tmpProg.append("G03 Y"+QString::number(Y-step-lastLineOffset)+" J"+QString::number(-step-lastLineOffset)+"\n");//дуга слева
                    tmpProg.append("G01 X"+QString::number(center1)+"\n");//верхняя линия
                    tmpProg.append("G02 Y"+QString::number(Y+step+lastLineOffset)+" J"+QString::number(step+lastLineOffset)+"\n");//дуга справа
                    tmpProg.append("G01 X"+QString::number(center2)+"\n");//нижняя линия
                }
                tmpProg.append("G90\n");//переключаемся на абсолютные координаты
                tmpProg.append("G00 Z"+QString::number(zOffset)+" F"+QString::number(moveSpeed)+"\n");
            }
            else{//вертикальный овал
                lines = (app->getXSize() / 2) / penRadius;//количество целых линий
                lastLineOffset = (app->getXSize() / 2) - (penRadius * lines);//смещение последней линии
                lastLineOffset = round(lastLineOffset * 10) / 10;//округляем до одного знака после запятой
                //например, если размер Pad-а 2.2мм, а диаметр пера 1мм, то смещение последней линии будет 0.1мм
                float halfSize = app->getYSize() / 2;
                halfSize = round(halfSize * 10) / 10;//округляем до одного знака после запятой
                float step = 0;
                float radius = app->getXSize() / 2;
                centerOffset = halfSize - radius;
                center1 = Y + centerOffset;
                center2 = Y - centerOffset;
                tmpProg.append("G00 X" + QString::number(X) + " Y" + QString::number(center1) + " F" + QString::number(moveSpeed) + "\n");//смещаем инструмент в позицию первого центра
                tmpProg.append("G00 Z" + QString::number(zOffset) + " F" + QString::number(moveSpeed) + "\n");//опускаем в позицию рисования, делаем точку
                tmpProg.append("G91\n");//временно переключаемся на относительные координаты
                tmpProg.append("G01 Y" + QString::number(center2) + " F" + QString::number(force) + "\n");//рисуем центральную линию с низу в верх
                for(int n = 1; n != lines + 1; n++){//рисуем овалы по количеству линий
                    step = penRadius * n;
                    tmpProg.append("G01 X" + QString::number(step) + "\n");//смещение на радиус пера по X
                    tmpProg.append("G03 X" + QString::number(step) + " I" + QString::number(0 - step) + "\n");//дуга сверху
                    tmpProg.append("G01 Y" + QString::number(centerOffset) + "\n");//верхняя линия
                    tmpProg.append("G02 X" + QString::number(step) + " I" + QString::number(step) + "\n");//дуга снизу
                    tmpProg.append("G01 Y" + QString::number(0 - centerOffset) + "\n");//нижняя линия
                }
                if(lastLineOffset!=0){
                    tmpProg.append("G01 X"+QString::number(X+step+lastLineOffset)+"\n");//смещение на радиус пера по X
                    tmpProg.append("G03 X"+QString::number(X-step-lastLineOffset)+" I"+QString::number(-step-lastLineOffset)+"\n");//дуга слева
                    tmpProg.append("G01 Y"+QString::number(center1)+"\n");//верхняя линия
                    tmpProg.append("G02 X"+QString::number(X+step+lastLineOffset)+" I"+QString::number(step+lastLineOffset)+"\n");//дуга справа
                    tmpProg.append("G01 Y"+QString::number(center2)+"\n");//нижняя линия
                }
                tmpProg.append("G90\n");//переключаемся на абсолютные координаты
                tmpProg.append("G00 Z"+QString::number(zOffset)+" F"+QString::number(moveSpeed)+"\n");
            }
            break;
        }
        case(APP_RECT):{
            int lines = 0;
            float lastLineOffset = 0;

            if(app->getXSize() >= app->getYSize()){//горизонтальный прямоугольник
                lines = (app->getYSize() / 2) / penRadius;//количество целых линий по горизонтали
                //например, если размер Pad-а 2.2мм, а диаметр пера 1мм, то смещение последней линии будет 0.1мм
                float halfSize = app->getXSize() / 2;
                float offset = 0;
                tmpProg.append("G00 X" + QString::number(X - halfSize) + " Y" + QString::number(Y) + " F"+QString::number(moveSpeed)+"\n");//смещаем инструмент в позицию - половина размера по вертикали
                tmpProg.append("G00 Z" + QString::number(zOffset) + " F" + QString::number(moveSpeed) + "\n");//опускаем в позицию рисования, делаем точку
                tmpProg.append("G91\n");//временно переключаемся на относительные координаты
                tmpProg.append("G01 X" + QString::number(app->getXSize()) + " F" + QString::number(force) + "\n");//рисуем центральную линию с низу в верх
                for(int n = 0;n != lines; n ++){//рисуем по количеству линий
                    offset += penRadius;
                    tmpProg.append("G01 Y" + QString::number(offset) + "\n");//смещение на радиус пера по X
                    tmpProg.append("G01 X" + QString::number(0 - app->getXSize()) + "\n");//правая линия движение вниз
                    offset += penRadius;
                    tmpProg.append("G01 Y" + QString::number(0 - offset) + "\n");//смещение влево на два радиуса
                    tmpProg.append("G01 X"+QString::number(app->getXSize())+"\n");//левая линия движение вверх
                    lastLineOffset = (app->getYSize() / 2) - (penRadius * lines);//смещение последней линии
                }
                if(lastLineOffset != 0){
                    tmpProg.append("G01 Y" + QString::number(offset + lastLineOffset) + "\n");//смещение на радиус пера по X
                    tmpProg.append("G01 X" + QString::number(0 - app->getXSize()) + "\n");//правая линия движение вниз
                    tmpProg.append("G01 Y" + QString::number(0 - (offset + lastLineOffset * 2)) + "\n");//смещение влево на два радиуса
                    tmpProg.append("G01 X"+QString::number(app->getXSize()) + "\n");//левая линия движение вверх
                }
                tmpProg.append("G90\n");//переключаемся на абсолютные координаты
                tmpProg.append("G00 Z" + QString::number(0) + " F" + QString::number(moveSpeed) + "\n");
            }
            else{//вертикальный прямоугольник
                lines = (app->getXSize() / 2) / penRadius;//количество целых линий по горизонтали
                //например, если размер Pad-а 2.2мм, а диаметр пера 1мм, то смещение последней линии будет 0.1мм
                float halfSize = app->getYSize() / 2;
                float offset = 0;
                tmpProg.append("G00 X" + QString::number(X) + " Y" + QString::number(Y - halfSize) + " F"+QString::number(moveSpeed)+"\n");//смещаем инструмент в позицию - половина размера по вертикали
                tmpProg.append("G00 Z" + QString::number(zOffset) + " F" + QString::number(moveSpeed) + "\n");//опускаем в позицию рисования, делаем точку
                tmpProg.append("G91\n");//временно переключаемся на относительные координаты
                tmpProg.append("G01 Y" + QString::number(app->getYSize()) + " F" + QString::number(force) + "\n");//рисуем центральную линию с низу в верх
                for(int n = 0; n != lines; n ++){//рисуем по количеству линий
                    offset += penRadius;
                    tmpProg.append("G01 X" + QString::number(offset) + "\n");//смещение на радиус пера по X
                    tmpProg.append("G01 Y" + QString::number(0 - app->getYSize()) + "\n");//правая линия движение вниз
                    offset += penRadius;
                    tmpProg.append("G01 X" + QString::number(0 - offset) + "\n");//смещение влево на два радиуса
                    tmpProg.append("G01 Y"+QString::number(app->getYSize())+"\n");//левая линия движение вверх
                    lastLineOffset = (app->getXSize() / 2) - (penRadius * lines);//смещение последней линии.
                }
                if(lastLineOffset != 0){
                    tmpProg.append("G01 X" + QString::number(offset + lastLineOffset) + "\n");//смещение на радиус пера по X
                    tmpProg.append("G01 Y" + QString::number(0 - app->getYSize()) + "\n");//правая линия движение вниз
                    tmpProg.append("G01 X" + QString::number(0 - (offset + lastLineOffset * 2)) + "\n");//смещение влево на два радиуса
                    tmpProg.append("G01 Y"+QString::number(app->getYSize()) + "\n");//левая линия движение вверх
                }
                tmpProg.append("G90\n");//переключаемся на абсолютные координаты
                tmpProg.append("G00 Z" + QString::number(0) + " F" + QString::number(moveSpeed) + "\n");
            }
            break;
        }
        case(APP_UNDEFINED):{
            break;
        }
    }
    return tmpProg;
}
///////////////////////////////////////////////////////////////////////////////////////////////////
float pad::getX() const{
    return X;
}
//////////////////////////////////////////////////////////////////////////////////////////////
float pad::getY() const{
    return Y;
}
