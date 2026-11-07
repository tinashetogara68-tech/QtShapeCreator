#include "square.h"

Square::Square(int width, QColor pColor, QColor fColor, int prop1) : Shape1Property(width, pColor, fColor, prop1)
{
}

void Square::draw(QPainter* painter)
{
    QPen pen(penColor);
    pen.setWidth(penWidth);
    painter->setPen(pen);
    painter->setBrush(fillColor);
    QRectF squa(150, 150, property1, property1);
    painter->drawRect(squa);
}

QStringList Square::toQStringList()
{
    QStringList data;
    QString stringWidth = QString::number(penWidth);
    QString stringPenCol = penColor.name();
    QString stringFillCol = fillColor.name();
    QString stringProp1 = QString::number(property1);

    data << "Square" << stringWidth << stringPenCol << stringFillCol << stringProp1 << "0";
    return data;
}
