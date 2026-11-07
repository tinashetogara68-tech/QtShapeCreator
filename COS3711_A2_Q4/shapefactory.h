#ifndef SHAPEFACTORY_H
#define SHAPEFACTORY_H
#include "shape.h"
#include "square.h"
#include "rectangle.h"
#include "circle.h"
#include "ellipse.h"


class ShapeFactory
{
public:
    ShapeFactory();
    Shape* factoryCreateShape(QString shapeType, int pWidth, QColor pColor, QColor fColor, int firstDimension, int secondDimension);
};

#endif // SHAPEFACTORY_H
