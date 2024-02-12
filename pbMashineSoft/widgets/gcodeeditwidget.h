#ifndef GCODEEDITWIDGET_H
#define GCODEEDITWIDGET_H

#include <QTextEdit>
#include <QTextBlock>
#include "parsergcode.h"

class gCodeEditWidget : public QTextEdit
{
    Q_OBJECT
public:
    gCodeEditWidget(QWidget *parent);
    void setCurrentString(int number);
    void setPenDiameter(float diameter);
    void reset();
    QStringList *getProgramm();

protected:
    int currentString;
    parserGCode parser;
    bool checkSyntaxis();


protected slots:
    void cursorPosChangedSlot();
    void textChangedSlot();


signals:
    void updateViewSignal();


};

#endif // GCODEEDITWIDGET_H
