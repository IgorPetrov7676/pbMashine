#ifndef GPUSHBUTTON_H
#define GPUSHBUTTON_H

#include <QPushButton>

class GPushButton : public QPushButton
{
    Q_OBJECT
public:
    GPushButton(QWidget *parent);
    void setGCode(QString code);
    QStringList getGCode();

signals:
    void clickedSignal(GPushButton *pointer);

protected slots:
    void clickedSlot(bool);


protected:
    QStringList gCode;

};

#endif // GPUSHBUTTON_H
