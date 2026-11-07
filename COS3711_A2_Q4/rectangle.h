#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape2property.h"

class Rectangle : public Shape2Property
{
public:
    Rectangle(int width, QColor pColor, QColor fColor, int prop1, int prop2);
    void draw(QPainter* painter);
    QStringList toQStringList();
};

#endif // RECTANGLE_H
