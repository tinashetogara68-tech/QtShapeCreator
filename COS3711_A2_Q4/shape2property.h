#ifndef SHAPE2PROPERTY_H
#define SHAPE2PROPERTY_H

#include "shape1property.h"

class Shape2Property : public Shape1Property
{
public:
    Shape2Property(int width, QColor pColor, QColor fColor, int prop1, int prop2);
    virtual void draw(QPainter* painter) = 0;
    virtual QStringList toQStringList() = 0;
protected:
    int property2;
};

#endif // SHAPE2PROPERTY_H
