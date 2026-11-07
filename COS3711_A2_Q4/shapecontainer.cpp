#include "shapecontainer.h"

ShapeContainer* ShapeContainer::onlyInstance = NULL;

ShapeContainer::ShapeContainer()
{
    currentPosition = list.begin();
}

ShapeContainer* ShapeContainer::getInstance()
{
    if(onlyInstance == NULL)
    {
        onlyInstance = new ShapeContainer();
    }
    return onlyInstance;
}

void ShapeContainer::addToList(Shape *s)
{
    list.append(s);
    currentPosition = list.end() - 1;
}

int ShapeContainer::getListSize()
{
    return list.size();
}

Shape *ShapeContainer::getCurrentShape()
{
    if(!list.isEmpty())
    {
        return *currentPosition;
    }
    else
        return NULL;
}

void ShapeContainer::movePreviousShape()
{
    if(currentPosition != list.begin())
    {
        --currentPosition;
    }
}

void ShapeContainer::moveNextShape()
{
    if(!(currentPosition == list.end() - 1))
    {
        ++currentPosition;
    }
}

Shape *ShapeContainer::getFirstShape()
{
    currentPosition = list.begin();
    return *currentPosition;
}

void ShapeContainer::setMemento(Memento* m, ShapeFactory* fact)
{
    QList<QStringList> tempList = m->getState();
    list.clear();
    for(int i = 0; i < tempList.size(); i++)
    {
        QStringList dataList = tempList.at(i);

        Shape* memShape;

        int width = dataList[1].toInt();
        QColor penColor = QColor::fromString(dataList[2]);
        QColor fillColor = QColor::fromString(dataList[3]);
        int p1 = dataList[4].toInt();
        int p2 = dataList[5].toInt();

        memShape = fact->factoryCreateShape(dataList[0], width, penColor, fillColor, p1, p2);
        if(memShape)
            addToList(memShape);
    }
}

Memento* ShapeContainer::createMemento()
{
    QList<QStringList> tempList;
    for(int i = 0; i < list.size(); i++)
    {
        tempList.append(list[i]->toQStringList());
    }
    Memento* mem = new Memento();
    mem->setState(tempList);
    return mem;

}
