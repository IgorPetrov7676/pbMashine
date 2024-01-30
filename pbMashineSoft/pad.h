#ifndef PAD_H
#define PAD_H

#include <QString>
#include <QStringList>
#include <cmath>
#include "apperture.h"


class pad
{
public:
    pad();

    void setX(float value);
    void setY(float value);
    void setApp(apperture *value);
    QStringList *calcGCode(float penDiameter, float force, float moveSpeed, float zOffset);
    float getX() const;
    float getY() const;

protected:
    float X;//позиция пада на плате
    float Y;
    apperture *app;
    QStringList *calcGCodeCycle(float penDiameter, float force, float moveSpeed, float zOffset);
    QStringList *calcGCodeVertOval(float penDiameter, float force, float moveSpeed, float zOffset);
    QStringList *calcGCodeHorOval(float penDiameter, float force, float moveSpeed, float zOffset);
    QStringList *calcGCodeVertRect(float penDiameter, float force, float moveSpeed, float zOffset);
    QStringList *calcGCodeHorRect(float penDiameter, float force, float moveSpeed, float zOffset);


};

#endif // PAD_H
