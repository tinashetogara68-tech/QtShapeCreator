#ifndef MEMENTO_H
#define MEMENTO_H
#include "shape.h"


class Memento
{
public:
    friend class ShapeContainer;
private:
    Memento();
    QList<QStringList> dataList;
    QList<QStringList> getState();
    void setState(QList<QStringList> list);
};

#endif // MEMENTO_H
