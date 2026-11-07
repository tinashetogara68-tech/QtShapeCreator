#ifndef DISPLAYWINDOW_H
#define DISPLAYWINDOW_H

#include <QWidget>
#include <QPalette>
#include "shape.h"


class DisplayWindow : public QWidget
{
public:
    DisplayWindow(QWidget *parent = nullptr);
    void setShape(Shape *shapetoPaint);

protected:
    void paintEvent(QPaintEvent *event);
private:
    Shape *shape;
};

#endif // DISPLAYWINDOW_H
