#ifndef SHAPE1PROPERTY_H
#define SHAPE1PROPERTY_H
#include "shape.h"


class Shape1Property : public Shape
{
public:
    Shape1Property(int width, QColor pColor, QColor fColor, int prop1);
    virtual void draw(QPainter* painter) = 0;
    virtual QStringList toQStringList() = 0;
protected:
    int property1;
};

#endif // SHAPE1PROPERTY_H
