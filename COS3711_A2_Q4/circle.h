#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape1property.h"

class Circle : public Shape1Property
{
public:
    Circle(int width, QColor pColor, QColor fColor, int prop1);
    void draw(QPainter* painter);
    QStringList toQStringList();
};

#endif // CIRCLE_H
