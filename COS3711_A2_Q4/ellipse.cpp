#include "ellipse.h"

Ellipse::Ellipse(int width, QColor pColor, QColor fColor, int prop1, int prop2) : Shape2Property(width, pColor, fColor, prop1, prop2)
{

}

void Ellipse::draw(QPainter* painter)
{
    QPen pen(penColor);
    pen.setWidth(penWidth);
    painter->setPen(pen);
    painter->setBrush(fillColor);
    QRectF elli(150, 150, property1, property2);
    painter->drawEllipse(elli);
}

QStringList Ellipse::toQStringList()
{
    QStringList data;
    QString stringWidth = QString::number(penWidth);
    QString stringPenCol = penColor.name();
    QString stringFillCol = fillColor.name();
    QString stringProp1 = QString::number(property1);
    QString stringProp2 = QString::number(property2);

    data << "Ellipse" << stringWidth << stringPenCol << stringFillCol << stringProp1 << stringProp2;
    return data;
}
