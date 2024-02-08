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

    index = programm.indexOf("\n",pos);
    while(index != -1){
        drawCommand com;
        com.setPenDiameter(penDiameter);
#if QT_VERSION > 0x051300
        QString tmp = programm.sliced(pos, index - pos);
#else
        QString tmp = programm.mid(pos, index - pos);
#endif
        pos = index + 1;
        if(!parseFrame(tmp, &com)){
            return false;
        }
        drawProgramm->append(com);
        index = programm.indexOf("\n", pos);
    }
    return true;
}
///////////////////////////////////////////////////////////////////////////////
bool parserGCode::isStringCorrect(QString string){
    int index = string.indexOf("\n", 0);
    if(index != -1){
        drawCommand command;
        return parseFrame(string, &command);
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
    int tmp = 0;
    frame.append(" ");//добавляем в конец пробел для поиска
    if(frame.left(1) == "N"){// если первый символ N, то читаем номер
        bool ok = false;
        tmp=frame.indexOf(" ");
#if QT_VERSION > 0x051300
        QString num = frame.sliced(1, tmp);
#else
        QString num = frame.mid(1, tmp);
#endif
        tmp=num.toInt(&ok);
        if(!ok){
            return false;
        }
        command->setNumber(tmp);
        frame.remove(0, tmp+1);
    }
    if(frame.left(1) == "M"){

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
    bool ok = false;
    int spacePos = frame.indexOf(" ");

#if QT_VERSION > 0x051300
    int com = frame.sliced(0, spacePos).toInt(&ok);
#else
    int com = frame.mid(0, spacePos).toInt(&ok);
#endif

    if(!ok){
        return false;
    }
    command->setCurrentX(currentX);
    command->setCurrentY(currentY);
    command->setCurrentZ(currentZ);

    switch(com){
        case(0):{//холостой ход
            command->setType(COMMAND_MOVE);
            return parseParameters(frame, command);
        }
        case(1):{//линейное перемещение
            command->setType(COMMAND_LINE);
            return parseParameters(frame, command);
        }
        case(2):{//круговая интерполяция по часовой
            command->setType(COMMAND_ARC_FCW);
            return parseParameters(frame, command);
        }
        case(3):{//круговая интерполяция против часовой
            command->setType(COMMAND_ARC_RCW);
            return parseParameters(frame, command);
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

#if QT_VERSION > 0x051300
    QString tmp=frame.sliced(index1+1,index2-index1);
#else
    QString tmp=frame.mid(index1+1,index2-index1);
#endif

    *rez=tmp.toFloat(&ok);
    if(!ok){
        return false;
    }
    return true;
}
///////////////////////////////////////////////////////////////////////////////////////////
bool parserGCode::parseParameters(QString frame, drawCommand *command){
    int tmp1 = frame.indexOf(" ");
    float tmpFloat = 0;

    if(findParam("X", frame, &tmpFloat)){
        if(relativeCoordinates){
            command->setMoveX(currentX + tmpFloat);
            currentX += tmpFloat;
        }
        else{
            command->setMoveX(tmpFloat);
            currentX = tmpFloat;
        }
        tmp1 ++;
    }
    if(findParam("Y", frame, &tmpFloat)){
        if(relativeCoordinates){
            command->setMoveY(currentY + tmpFloat);
            currentY += tmpFloat;
        }
        else{
            command->setMoveY(tmpFloat);
            currentY = tmpFloat;
        }
        tmp1 ++;
    }
    if(findParam("Z", frame, &tmpFloat)){
        if(relativeCoordinates){
            command->setMoveZ(currentZ + tmpFloat);
            currentZ += tmpFloat;
        }
        else{
            command->setMoveZ(tmpFloat);
            currentZ = tmpFloat;
        }
        tmp1 ++;
    }
    if(tmp1 == 0){
        return false;//если ни одного параметра не нашли, то это ошибка и можно дальше не читать
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
