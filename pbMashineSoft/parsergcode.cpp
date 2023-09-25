#include "parsergcode.h"

parserGCode::parserGCode(){
    drawProgramm = new QVector<drawCommand>;
    currentX = 0;
    currentY = 0;
    currentZ = 0;
    currentForce = 0;
    penDiameter = 0;
    relativeCoordinates = 1;//по умолчанию относительные координаты как в машине
}
////////////////////////////////////////////////////////////////////////////
parserGCode::~parserGCode(){
    delete drawProgramm;
}
////////////////////////////////////////////////////////////////////////////
bool parserGCode::readProgramm(QString programm){
    int index = 0;
    int pos = 0;

    index=programm.indexOf("\n",pos);
    while(index != -1){
        drawCommand com;
        com.setPenDiameter(penDiameter);
        QString tmp=programm.mid(pos,index-pos);
        pos=index+1;
        if(!parseFrame(tmp,&com)){
            return false;
        }
        drawProgramm->append(com);
        index=programm.indexOf("\n",pos);
    }
    return true;
}
///////////////////////////////////////////////////////////////////////////////
bool parserGCode::isStringCorrect(QString string){
    int index=string.indexOf("\n",0);
    if(index!=-1){
        drawCommand command;
        return parseFrame(string,&command);
    }
    return false;
}
///////////////////////////////////////////////////////////////////////////////
QVector<drawCommand> *parserGCode::getPainterProgramm(){
    return drawProgramm;
}
////////////////////////////////////////////////////////////////////////////////
void parserGCode::setPenDiameter(float diameter){
    penDiameter=diameter;
}
///////////////////////////////////////////////////////////////////////////////
void parserGCode::reset(){
    currentX=0;
    currentY=0;
    currentZ=0;
    drawProgramm->clear();
}
////////////////////////////////////////////////////////////////////////////////
void parserGCode::shineDrawCommand(int index){
    int size=drawProgramm->size();
    if(size!=0){
        if((index>=0)&&(index<size)){
            for(int n=0;n!=size;n++){
                drawProgramm->operator [](n).setShine(false);
            }
            drawProgramm->operator [](index).setShine(true);
        }
    }
}
/////////////////////////////////////////////////////////////////////////////
bool parserGCode::parseFrame(QString frame, drawCommand *command){
    int tmp=0;
    frame.append(" ");//добавляем в конец пробел для поиска
    if(frame.left(1)=="N"){// если первый символ N, то читаем номер
        bool ok=false;
        tmp=frame.indexOf(" ");
        QString num=frame.mid(1,tmp);
        tmp=num.toInt(&ok);
        if(!ok){
            return false;
        }
        command->setNumber(tmp);
        frame.remove(0,tmp+1);
    }
    if(frame.left(1)=="M"){

    }
    else if(frame.left(1)=="G"){
        return parseGcommand(frame.mid(1),command);
    }
    else if(frame.left(1)=="O"){

    }
    else if(frame.left(1)=="("){
        int index=frame.indexOf(")");
        if(index<0){
            return false;
        }
    }
    else if(frame.left(1)=="%"){

    }
    else {
        return false;
    }
    return true;
}
///////////////////////////////////////////////////////////////////////////////////
bool parserGCode::parseGcommand(QString frame, drawCommand *command){
    int tmp1 = frame.indexOf(" ");
    float tmpFloat = 0;
    bool ok = false;

    int com = frame.mid(0,tmp1 + 1).toInt(&ok);
    if(!ok){
        return false;
    }
    command->setCurrentX(currentX);
    command->setCurrentY(currentY);
    command->setCurrentZ(currentZ);

    switch(com){
        case(0):{//холостой ход
            tmp1 = 0;//для проверки на наличие хоть одной координаты
            command->setType(COMMAND_MOVE);
            if(findParam("X", frame, &tmpFloat)){
                if(relativeCoordinates){
                    command->setMoveX(tmpFloat);
                    currentX += tmpFloat;
                }
                else{
                    command->setMoveX(tmpFloat);
                    currentX = tmpFloat;
                }
                tmp1 ++;
            }
            if(findParam("Y", frame, &tmpFloat)){
                command->setMoveY(tmpFloat);
                setCurrentY(tmpFloat);
                tmp1 ++;
            }
            if(findParam("Z", frame, &tmpFloat)){
                command->setMoveZ(tmpFloat);
                setCurrentZ(tmpFloat);
                tmp1 ++;
            }
            if(tmp1 == 0){
                return false;//если ни одного параметра не нашли, то это ошибка
            }
            break;
        }
        case(1):{//линейное перемещение
            tmp1 = 0;//для проверки на наличие хоть одной координаты
            command->setType(COMMAND_LINE);

            if(findParam("X", frame, &tmpFloat)){
                command->setMoveX(tmpFloat);
                setCurrentX(tmpFloat);
                tmp1 ++;
            }
            if(findParam("Y", frame, &tmpFloat)){
                command->setMoveY(tmpFloat);
                setCurrentY(tmpFloat);
                tmp1 ++;
            }
            if(findParam("Z", frame, &tmpFloat)){
                command->setMoveZ(tmpFloat);
                setCurrentZ(tmpFloat);
                command->setType(COMMAND_MOVE);//если ось Z меняется и не равна 0 то это перемещение, а не рисование
                tmp1 ++;
            }
            if(findParam("F", frame, &tmpFloat)){
                currentForce=tmpFloat;
            }
            command->setForce(currentForce);//подачу присваиваем в любом случае или текущую или новую
            if(tmp1==0){
                return false;//если ни одного параметра не нашли, то это ошибка
            }
            break;
        }
        case(2):{//круговая интерполяция по часовой
            command->setType(COMMAND_ARC_FCW);
            return parseCicleInterpolation(frame, command);
        }
        case(3):{//круговая интерполяция против часовой
            command->setType(COMMAND_ARC_RCW);
            return parseCicleInterpolation(frame, command);
        }
        case(90):{//абсолютные координаты
            relativeCoordinates = false;
            break;
        }
        case(91):{//относительные координаты
            relativeCoordinates = true;
            break;
        }
    }
    return true;
}
///////////////////////////////////////////////////////////////////////////////
bool parserGCode::findParam(QString param, QString frame, float *rez){
    int index1=frame.indexOf(param);
    int index2=0;
    bool ok=false;
    if(index1==-1){
        return false;
    }
    index2=frame.indexOf(" ",index1);
    if(index2==-1){
        return false;
    }
    QString tmp=frame.mid(index1+1,index2-index1);
    *rez=tmp.toFloat(&ok);
    if(!ok){
        return false;
    }
    return true;
}
////////////////////////////////////////////////////////////////////////////////////////
void parserGCode::setCurrentX(float value){
    if(relativeCoordinates){
        currentX += value;
    }
    else{
        currentX = value;
    }
}
////////////////////////////////////////////////////////////////////////////////////////
void parserGCode::setCurrentY(float value){
    if(relativeCoordinates){
        currentY += value;
    }
    else{
        currentY = value;
    }
}
///////////////////////////////////////////////////////////////////////////////////////
void parserGCode::setCurrentZ(float value){
    if(relativeCoordinates){
        currentZ += value;
    }
    else{
        currentZ = value;
    }
}
///////////////////////////////////////////////////////////////////////////////////////
bool parserGCode::parseCicleInterpolation(QString frame, drawCommand *command){
        int tmp1 = frame.indexOf(" ");
        float tmpFloat = 0;

    if(findParam("X", frame, &tmpFloat)){
        command->setMoveX(tmpFloat);
        setCurrentX(tmpFloat);
        tmp1 ++;
    }
    if(findParam("Y", frame, &tmpFloat)){
        command->setMoveY(tmpFloat);
        setCurrentY(tmpFloat);
        tmp1 ++;
    }
    if(findParam("Z", frame, &tmpFloat)){
        command->setMoveZ(tmpFloat);
        setCurrentZ(tmpFloat);
        tmp1 ++;
    }
    if(findParam("R", frame, &tmpFloat)){
        command->setR(tmpFloat);
    }
    else{
        if(findParam("I", frame, &tmpFloat)){
            command->setI(tmpFloat);
        }
        if(findParam("J", frame, &tmpFloat)){
            command->setJ(tmpFloat);
        }
        if(findParam("K", frame, &tmpFloat)){
            command->setK(tmpFloat);
        }
    }
    if(findParam("F", frame, &tmpFloat)){
        currentForce = tmpFloat;
    }
    command->setForce(currentForce);
    return true;
}
/////////////////////////////////////////////////////////////////////////////////
