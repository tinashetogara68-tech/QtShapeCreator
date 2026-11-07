 #include "shapereader.h"

ShapeReader::ShapeReader(ShapeContainer *container, ShapeFactory* fact)
{
    contain = container;
    currentShape = nullptr;
    QDomDocument doc;
    QString filePath = QString(SOURCE_DIR) + "/ShapeList.xml";
    QFile ShapeFile(filePath);

    if(!ShapeFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open file containing shapes" ;
    }
    else
    {
        if(!doc.setContent(&ShapeFile))
        {
            qDebug() << "Failed to set document contents";
        }
        ShapeFile.close();
    }

    QDomElement root = doc.firstChildElement();
    processElements(root, "shape", fact);

}

void ShapeReader::processElements(QDomElement r, QString tName, ShapeFactory *fact)
{
    QDomNodeList elementList = r.elementsByTagName(tName);

    for(int i = 0; i < elementList.count(); i++)
    {
        QDomNode elementNode = elementList.at(i);

        if(elementNode.isElement())
        {
            QDomElement currentEle = elementNode.toElement();
            QString type = currentEle.attribute("type");
            int p1 = currentEle.attribute("p1").toInt();
            int p2 = currentEle.attribute("p2").toInt();
            int pW = currentEle.attribute("pw").toInt();
            QColor pC = QColor::fromString(currentEle.attribute("pc"));
            QColor fC = QColor::fromString(currentEle.attribute("fc"));

            currentShape = fact->factoryCreateShape(type, pW, pC, fC, p1, p2);
            if(currentShape)
                contain->addToList(currentShape);


        }
    }
}
