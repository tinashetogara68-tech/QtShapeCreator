#include "displaywindow.h"

DisplayWindow::DisplayWindow(QWidget *parent) : QWidget(parent)
{
    shape = nullptr;
    //resize(400, 300);
    setStyleSheet("background-color: white;");
}

void DisplayWindow::setShape(Shape *shapetoPaint)
{
    shape = shapetoPaint;
}

void DisplayWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    if(shape == nullptr)
        return;
    shape->draw(&painter);
}
