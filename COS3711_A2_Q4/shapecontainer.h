#ifndef SHAPECONTAINER_H
#define SHAPECONTAINER_H
#include <QList>
#include <QListIterator>
#include "shape.h"
#include "shapefactory.h"
#include "memento.h"


class ShapeContainer
{
public:
    static ShapeContainer* getInstance();
    void addToList(Shape *s);
    int getListSize();
    Shape* getCurrentShape();
    void movePreviousShape();
    void moveNextShape();
    Shape* getFirstShape();
    void setMemento(Memento* m, ShapeFactory* fact);
    Memento* createMemento();
private:
    ShapeContainer();
    static ShapeContainer* onlyInstance;
    QList<Shape*> list;
    QList<Shape*>::iterator currentPosition;

};

#endif // SHAPECONTAINER_H


