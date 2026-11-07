#ifndef SQUARE_H
#define SQUARE_H

#include "shape1property.h"

class Square : public Shape1Property
{
public:
    Square(int width, QColor pColor, QColor fColor, int prop1);
    void draw(QPainter* painter);
    QStringList toQStringList();
};

#endif // SQUARE_H
