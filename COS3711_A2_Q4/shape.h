#ifndef SHAPE_H
#define SHAPE_H
#include <QColor>
#include <QPainter>
#include <QDebug>

class Shape
{
public:
    Shape(int width, QColor pColor, QColor fColor);
    virtual void draw(QPainter* painter) = 0;
    virtual QStringList toQStringList() = 0;

protected:
    int penWidth;
    QColor penColor;
    QColor fillColor;
};

#endif // SHAPE_H
