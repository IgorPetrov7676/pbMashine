#ifndef USBCONNECTION_H
#define USBCONNECTION_H

#include <QWidget>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QTimer>
#include <QByteArray>
#include <QFile>
#include <QApplication>
#include "widgets/serialportsdialog.h"
#include "drawcommand.h"
#include "errorclass.h"


enum messageType{
    MESSAGE_STATUS,
    MESSAGE_COMMAND,
    MESSAGE_COMPLETE,
    MESSAGE_ACKNOWLEDGE,
    MESSAGE_BISY,
    MESSAGE_STOP
};


struct plotterStatus{
    float posX;
    float posY;
    float posZ;
    float Force;
    bool swX;
    bool swY;
    bool swZ;
    float endPosX;
    float endPosY;
    float endPosZ;
    error plotterError;
};


class usbConnection : public QObject
{
    Q_OBJECT

public:
    usbConnection(QWidget *parent);
    ~usbConnection();
    bool selectPort();
    bool connectPort();
    void disconnectPort();
    QString getCurrentPortName();
    void sendGCode(QString gCode);
    void writeArray(QByteArray *array);
    bool isConnected();
    void runProgram(QStringList *program);
    void stopProgram();
    void pauseProgram();
    void decodeStatus(int offset);


signals:
    void statusSignal(plotterStatus status);
    void disconnectedSignal();
    void messageSignal(QString message);

protected:
    QWidget *parentWidget;
    QSerialPort *currentPort;
    QTimer statusTimer;
    QTimer waitTimer;
    QByteArray inputBuffer;
    QStringList *programPointer;
    bool runing;
    int programCounter;
    int requestPeriod;

    void deleteCurrentPort();
    void message(QString text);
    quint16 Crc16(char *pcBlock, unsigned short len);
    void decodePacket();
    void decodeMessage(int offset);
    bool openPortFromFile();
    bool writeCurrentPortInFile();
    void sendNextComand();


protected slots:
    void portError(QSerialPort::SerialPortError error);
    void requestTime();
    void dataReadyRead();
    void waitTimeSlot();
    void sendStopSlot();


};

#endif // USBCONNECTION_H
