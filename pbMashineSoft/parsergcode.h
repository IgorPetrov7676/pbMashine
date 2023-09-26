#ifndef PARSERGCODE_H
#define PARSERGCODE_H

#include <QString>
#include <QVector>
#include "drawcommand.h"
#include "defines.h"

//парсит текст G кода в программу для видового виджета

class parserGCode
{
public:
    parserGCode();
    ~parserGCode();
    bool readProgramm(QString programm);
    bool isStringCorrect(QString string);
    QVector<drawCommand> *getPainterProgramm();
    void setPenDiameter(float diameter);
    void reset();
    void shineDrawCommand(int index);

protected:
    bool parseFrame(QString frame, drawCommand *command);
    bool parseGcommand(QString frame, drawCommand *command);
    bool findParam(QString param, QString frame, float *rez);
    bool parseCicleInterpolation(QString frame, drawCommand *command);
    bool parseParameters(QString frame, drawCommand *command);

    QVector<drawCommand> *drawProgramm;
    bool relativeCoordinates;//флаг использования относительных/абсолюных координат
    float currentX;
    float currentY;
    float currentZ;
    float currentForce;
    float penDiameter;



};



#endif // PARSERGCODE_H
