#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "shape2property.h"

class Ellipse : public Shape2Property
{
public:
    Ellipse(int width, QColor pColor, QColor fColor, int prop1, int prop2);
    void draw(QPainter* painter);
    QStringList toQStringList();
};

#endif // ELLIPSE_H
