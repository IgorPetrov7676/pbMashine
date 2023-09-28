#include "usbconnection.h"

usbConnection::usbConnection(QWidget *parent){
    parentWidget = parent;
    currentPort = nullptr;
    programPointer = nullptr;
    runing = false;
    programCounter = 0;
    requestPeriod = 1000;

    connect(&statusTimer,SIGNAL(timeout()),this,SLOT(requestTime()));
    connect(&waitTimer,SIGNAL(timeout()),this,SLOT(waitTimeSlot()));

}
/////////////////////////////////////////////////////////////////////////
usbConnection::~usbConnection(){
    deleteCurrentPort();
}
////////////////////////////////////////////////////////////////////////
bool usbConnection::selectPort(){

    if(openPortFromFile()){
        return true;
    }
    else{
        serialPortsDialog SPDialog(parentWidget);

        QSerialPortInfo info;
        QList<QSerialPortInfo> portsList=info.availablePorts();
        if(portsList.size()!=0){
            SPDialog.setPortsList(&portsList);
            if(SPDialog.exec()==QDialog::Accepted){
                deleteCurrentPort();
                currentPort=SPDialog.getPort();
                connect(currentPort,SIGNAL(errorOccurred(QSerialPort::SerialPortError)),this,SLOT(portError(QSerialPort::SerialPortError)));
                connect(currentPort,SIGNAL(readyRead()),this,SLOT(dataReadyRead()));
                return true;
            }
            return false;
        }
        deleteCurrentPort();
        message(tr("В системе не обнаружено СОМ портов."));
        return false;
    }
}
////////////////////////////////////////////////////////////////////////////
bool usbConnection::connectPort(){
    if(currentPort==nullptr){
        if(selectPort()){
            if(currentPort->open(QIODevice::ReadWrite)){
                statusTimer.start(requestPeriod);
                return true;
            }
            else{
                QString error = currentPort->errorString();
                message(tr("Невозможно открыть порт")+currentPort->portName()+"\n"+
                        currentPort->errorString());
            }
        }
    }
    return false;
}
///////////////////////////////////////////////////////////////////////////////////////
void usbConnection::disconnectPort(){
    deleteCurrentPort();
    statusTimer.stop();
    waitTimer.stop();
}
////////////////////////////////////////////////////////////////////////////////////////////////
QString usbConnection::getCurrentPortName(){
    if(currentPort!=nullptr){
        return currentPort->portName();
    }
    return tr("Нет активного порта");
}
////////////////////////////////////////////////////////////////////////////////////
void usbConnection::sendGCode(QString gCode){
    if(currentPort!=nullptr){
        if(currentPort->isOpen()){
            statusTimer.stop();
            QByteArray outArray(2,0);
            outArray[1]=MESSAGE_COMMAND;
            QByteArray stringArray = gCode.toLatin1();
            outArray.append(stringArray);
            writeArray(&outArray);
            return;
        }
    }
    emit disconnectedSignal();
}
/////////////////////////////////////////////////////////////////////////////////////////////
void usbConnection::writeArray(QByteArray *array){
    array->data()[0]=static_cast<char>(array->size()+2);//здесь считаем и устанавливаем размер пакета
    quint16 crc=Crc16(array->data(),array->size());
    array->append((char)0);//добавляем 2 лишних байта в конец штатным способом
    array->append((char)0);
    memcpy(array->data()+(array->size()-2),&crc,2);
    currentPort->write(*array);
}
///////////////////////////////////////////////////////////////////////////////////////
bool usbConnection::isConnected(){
    if(currentPort!=nullptr){
        return true;
    }
    return false;
}
///////////////////////////////////////////////////////////////////////////////////////
void usbConnection::runProgram(QStringList *program){
    int size = program->size();
    programPointer = new QStringList();
    for(int n = 0; n != size; n++){
        programPointer->operator <<(program->at(n));
    }
    runing = true;
    sendNextComand();
}
//////////////////////////////////////////////////////////////////////////////////
void usbConnection::stopProgram(){
    runing = false;
    if(programPointer != nullptr){
        delete programPointer;
        programPointer = nullptr;
    }
    programCounter = 0;
    sendStopSlot();
}
//////////////////////////////////////////////////////////////////////////////////////
void usbConnection::pauseProgram(){
    runing = false;
}
////////////////////////////////////////////////////////////////////////////////////
void usbConnection::decodeStatus(int offset){
    plotterStatus status;

    qint16 tmp=0;
    memcpy(&tmp, inputBuffer.data() + offset + 2, 2);
    status.posX = static_cast<float>(tmp) / 10;//приводим Int к float
    memcpy(&tmp,inputBuffer.data() + offset + 4, 2);
    status.posY = static_cast<float>(tmp) / 10;//приводим Int к float
    memcpy(&tmp,inputBuffer.data() + offset + 6, 2);
    status.posZ = static_cast<float>(tmp) / 10;//приводим Int к float
    memcpy(&tmp,inputBuffer.data() + offset + 8, 2);
    status.Force = static_cast<float>(tmp) / 10;//приводим Int к float

    if(inputBuffer.at(offset + 10) == 1){
        status.swX = true;
    }
    else{
        status.swX = false;
    }
    if(inputBuffer.at(offset + 11) == 1){
        status.swY = true;
    }
    else{
        status.swY = false;
    }
    if(inputBuffer.at(offset + 12) == 1){
        status.swZ = true;
    }
    else{
        status.swZ = false;
    }

    memcpy(&tmp,inputBuffer.data() + offset + 13, 2);
    status.endPosX = static_cast<float>(tmp) / 10;//приводим Int к float

    memcpy(&tmp,inputBuffer.data() + offset + 15, 2);
    status.endPosY = static_cast<float>(tmp) / 10;//приводим Int к float

    memcpy(&tmp,inputBuffer.data() + offset + 17, 2);
    status.endPosZ = static_cast<float>(tmp) / 10;//приводим Int к float

    tmp = 0;
    memcpy(&tmp,inputBuffer.data() + offset + 19, 1);
    status.plotterError = static_cast<error>(tmp);//приводим Int к error

    emit statusSignal(status);
}
//////////////////////////////////////////////////////////////////////////////
void usbConnection::sendStopSlot(){
    if(currentPort!=nullptr){
        if(currentPort->isOpen()){
            QByteArray statusRequest(2, 0);
            statusRequest[0] = 2;
            statusRequest[1] = MESSAGE_STOP;
            writeArray(&statusRequest);
            return;
        }
    }
    emit disconnectedSignal();
}
/////////////////////////////////////////////////////////////////////////////////
void usbConnection::deleteCurrentPort(){
    if(currentPort!=nullptr){
        if(currentPort->isOpen()){
            currentPort->close();
        }
        delete currentPort;
        currentPort=nullptr;
    }
}
//////////////////////////////////////////////////////////////////////////////////
void usbConnection::message(QString text){
    QMessageBox box;
    box.setWindowTitle(tr("Внимание!"));
    box.setIcon(QMessageBox::Critical);
    box.setText(text);
    box.setStandardButtons(QMessageBox::Ok);
    box.exec();
}
///////////////////////////////////////////////////////////////////////////////////////////
quint16 usbConnection::Crc16(char *pcBlock, unsigned short len)
{
    quint16 crc = 0xFFFF;
    unsigned char i;

    while (len--)
    {
        crc ^= *pcBlock++ << 8;

        for (i = 0; i < 8; i++)
            crc = crc & 0x8000 ? (crc << 1) ^ 0x1021 : crc << 1;
    }
    return crc;
}
/////////////////////////////////////////////////////////////////////////////////////////////////
void usbConnection::decodePacket(){
    int offset = 0;
    int size = 0;

    while(offset < inputBuffer.size()){
        size = inputBuffer[offset];
        quint16 crc1 = Crc16(inputBuffer.data() + offset, static_cast<unsigned short>(size-2));
        quint16 crc2 = 0;
        memcpy(&crc2,inputBuffer.data() + offset + size - 2,sizeof(quint16));
        if(crc1 == crc2){
            decodeMessage(offset);
        }
        else{
            emit messageSignal(tr("Ошибка контрольной суммы на стороне приложения."));
            inputBuffer.clear();
        }
        offset += size;
    }
    inputBuffer.clear();
    statusTimer.start(requestPeriod);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
void usbConnection::decodeMessage(int offset){
    switch(inputBuffer.at(offset + 1)){
        case(MESSAGE_COMPLETE):{//после завершения выполнения команды стартуем запрос статуса
            sendNextComand();
            emit messageSignal("Завершение команды.");
            break;
        }
        case(MESSAGE_STATUS):{
            decodeStatus(offset);
            break;
        }
        case(MESSAGE_ACKNOWLEDGE):{
            emit messageSignal(tr("Команда подтверждена контроллером."));
            break;
        }
        case(MESSAGE_BISY):{
            emit messageSignal(tr("Команда не принята. Контроллер занят."));
            break;
        }
        case(MESSAGE_STOP):{
            emit messageSignal(tr("Экстренный останов!"));
            break;
        }
        default:{
            emit messageSignal(tr("Неизвестное сообщение от контроллера."));
            break;
        }
    }
}
////////////////////////////////////////////////////////////////////////////////////////////
bool usbConnection::openPortFromFile(){
    QFile file(QApplication::applicationDirPath());
    file.setFileName("comPort.conf");
    if(file.open(QIODevice::ReadOnly)){

        return true;
    }
    return false;
}
/////////////////////////////////////////////////////////////////////////////
bool usbConnection::writeCurrentPortInFile(){
    //todo
}
//////////////////////////////////////////////////////////////////////////////////
void usbConnection::sendNextComand(){
    if(runing){
        if(programCounter < programPointer->size()){
            sendGCode(programPointer->at(programCounter));
            programCounter++;
        }
        else{
            programCounter = 0;
            runing = false;
            if(programPointer != nullptr){
                delete programPointer;
                programPointer = nullptr;
            }
        }
    }
}
////////////////////////////////////////////////////////////////////////////////////
void usbConnection::portError(QSerialPort::SerialPortError error){
    if(error!=QSerialPort::NoError){
        emit messageSignal(tr("Ошибка порта ")+currentPort->portName()+"\n"+
                currentPort->errorString());
        emit disconnectedSignal();
    }
}
///////////////////////////////////////////////////////////////////////////////
void usbConnection::requestTime(){
    if(currentPort!=nullptr){
        if(currentPort->isOpen()){
            QByteArray statusRequest(2, 0);
            statusRequest[0] = 2;
            statusRequest[1] = MESSAGE_STATUS;
            writeArray(&statusRequest);
            return;
        }
    }
    emit disconnectedSignal();
}
////////////////////////////////////////////////////////////////////////////////////
void usbConnection::dataReadyRead(){
    statusTimer.stop();
    waitTimer.stop();
    char inputArray[50];
    qint64 inputCount = currentPort->read(inputArray, 50);
    inputBuffer.append(inputArray, inputCount);
    if(static_cast<quint64>(inputArray[0]) > inputCount){//если пакет пришел не полностью
        emit messageSignal(tr("Пакет пришел не полностью."));
        return;
    }
    else{
        decodePacket();
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////
void usbConnection::waitTimeSlot(){
    waitTimer.stop();
    statusTimer.stop();
    programCounter = 0;
    runing = false;
    message(tr("Превышен интервал ожидания ответа от устройства. \n"
               "USB соединение в порядке, но устройство не отвечает."));
    emit disconnectedSignal();

    //deleteCurrentPort();//для отладки. потом раскоментировать
}
//////////////////////////////////////////////////////////////////////////////////////
