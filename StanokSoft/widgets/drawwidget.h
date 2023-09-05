#ifndef DRAWWIDGET_H
#define DRAWWIDGET_H

#include <QWidget>
#include "gerberconverter.h"

namespace Ui {
class drawWidget;
}

class drawWidget : public QWidget
{
    Q_OBJECT

public:
    explicit drawWidget(QWidget *parent = nullptr);
    void setGerberFile(QFile *file);
    ~drawWidget();



protected:
    gerberConverter *Gconverter;

protected slots:
    void openFileSlot();
    void forceChangeSlot(double value);
    void penChangeSlot(double value);
    void zChangeSlot(double value);
    void moveChangeSlot(double value);
    void reParseSlot();
    void startSlot();

signals:
    void openFileSignal(QString fileType);
    void messageSignal(QString message);
    void startProgrammSignal(QStringList *program);


private:
    Ui::drawWidget *ui;
};

#endif // DRAWWIDGET_H
