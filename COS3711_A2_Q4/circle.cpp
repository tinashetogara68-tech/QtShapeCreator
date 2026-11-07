#include "circle.h"

Circle::Circle(int width, QColor pColor, QColor fColor, int prop1) : Shape1Property(width, pColor, fColor, prop1)
{

}

void Circle::draw(QPainter* painter)
{
    QPen pen(penColor);
    pen.setWidth(penWidth);
    painter->setPen(pen);
    painter->setBrush(fillColor);
    QRectF circ(150, 150, property1, property1);
    painter->drawEllipse(circ);
}

QStringList Circle::toQStringList()
{
    QStringList data;
    QString stringWidth = QString::number(penWidth);
    QString stringPenCol = penColor.name();
    QString stringFillCol = fillColor.name();
    QString stringProp1 = QString::number(property1);

    data << "Circle" << stringWidth << stringPenCol << stringFillCol << stringProp1 << "0";
    return data;
}
