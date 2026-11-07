#include "shapefactory.h"

ShapeFactory::ShapeFactory()
{

}

//Not implementation of classic Factory. Requires a pure Abstract Superclass followed by dedicated subclasses that implement it depending on necessary shape
Shape *ShapeFactory::factoryCreateShape(QString shapeType, int pWidth, QColor pColor, QColor fColor, int firstDimension, int secondDimension)
{
    if(shapeType == "Circle")
    {
        Shape* currentShape = new Circle(pWidth, pColor, fColor, firstDimension);
        return currentShape;
    }
    else if(shapeType == "Square")
    {
        Shape* currentShape = new Square(pWidth, pColor, fColor, firstDimension);
        return currentShape;
    }
    else if(shapeType == "Rectangle")
    {
        Shape* currentShape = new Rectangle(pWidth, pColor, fColor, firstDimension, secondDimension);
        return currentShape;
    }
    else if(shapeType == "Ellipse")
    {
        Shape* currentShape = new Ellipse(pWidth, pColor, fColor, firstDimension, secondDimension);
        return currentShape;
    }
}
