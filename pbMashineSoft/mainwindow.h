#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QFileDialog>
#include "usbconnection.h"
#include "connectionindicator.h"
#include "errorclass.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected slots:
    void connectSlot();
    void statusSlot(plotterStatus status);
    void disconnectedSlot();
    void sendGCode(QString gCode);
    void sendProgrammSlot(QStringList *program);
    void openSlot(QString fileType);
    void updateViewSlot();
    void errorSlot(QString error, QString title = NULL);
    void stopSlot();
    void pauseSlot();
    void messageSlot(QString message);

protected:
    usbConnection *USBPort;
    connectionIndicator *conIndicator;
    QLabel *portName;
    QVector<float>penDiametersArray;

    void distribForms();
    void writeConfigParameter(QString parameter, QString value);
    QString readConfigParameter(QString parameter);


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
