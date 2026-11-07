#ifndef SHAPEREADER_H
#define SHAPEREADER_H
#include <QCoreApplication>
#include <QtXml/QDomDocument>
#include <QFile>
#include <QDebug>
#include "shapefactory.h"
#include "shapecontainer.h"
#include "shapefactory.h"




class ShapeReader
{
public:
    ShapeReader(ShapeContainer *container, ShapeFactory* fact);
    void processElements(QDomElement r, QString tName, ShapeFactory* fact);
private:
    Shape* currentShape;
    ShapeContainer *contain;
};

#endif // SHAPEREADER_H
