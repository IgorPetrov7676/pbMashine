#ifndef VIEWWIDGET_H
#define VIEWWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPen>
#include <QWheelEvent>
#include <QVector>
#include "gerberconverter.h"
#include "drivercommand.h"

namespace Ui {
class viewWidget;
}


class viewWidget : public QWidget
{
    Q_OBJECT

public:
    explicit viewWidget(QWidget *parent = nullptr);
    void drawRawData(gerberConverter *converter);
    void clearAll();
    void executeNextCommand(QString *command);
    void showDrawing(QStringList *gProgramm);
    ~viewWidget();

protected:
    void executeCurrentCommand();
    bool parseCommand(QString *command);
    bool parseGCode(QString *command);
    bool parseMCode(QString *command);
    void paintEvent(QPaintEvent *);
    void wheelEvent(QWheelEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);

    driverCommand currentCommand;

    gerberConverter *converterPointer;

    float scaleX;
    float scaleY;
    float translateX;
    float translateY;
    int mousePosX;
    int mousePosY;
    float currentPositionX;
    float currentPositionY;
    float currentPositionZ;
    bool relativeCoordinates;

private:
    Ui::viewWidget *ui;
};

#endif // VIEWWIDGET_H
