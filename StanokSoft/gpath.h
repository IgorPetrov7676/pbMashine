#ifndef GPATH_H
#define GPATH_H

#include <QVector>
#include <QPointF>
#include <QStringList>
#include <QVector2D>
#include <cmath>
#include "apperture.h"

class GPath //путь - это траектория, состоящия из точек,
        //которые проходятся непрерывно одна за другой и
        //при проходжении которой перо всегда опущено
{
public:
    GPath();
    ~GPath();
    void setApp(apperture *value);
    void addPoint(QPointF *point);
    void addPath(GPath *path);
    QPointF *startPoint();
    QPointF *endtPoint();
    int getPointsCount();
    QStringList calcGCode(float penDiameter, float force, float moveSpeed, float zOffset);
    bool isValide();
    bool isApperture();
    float appertureSize();
    QPointF *getPoint(int index);
    void convertCoordinates(float zeroX, float zeroY);
    float getMinY();//возвращает максимальную координату Y из всех точек пути
    float getMinX();//возвращает минимальную координату Х из всех точек пути

protected:
    apperture *currentApperture;
    QVector<QPointF*> *pointsArray;
    bool valide;
    QPointF perOffset(QPointF *point1, QPointF *point2, float distance);
    QPointF parLengthOffset(QPointF startPoint, QPoint parPoint1, QPointF parPoint2);


};

#endif // GPATH_H
