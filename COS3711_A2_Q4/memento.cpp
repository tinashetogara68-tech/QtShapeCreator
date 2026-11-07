#include "memento.h"

Memento::Memento()
{

}

QList<QStringList> Memento::getState()
{
    return dataList;
}

void Memento::setState(QList<QStringList> list)
{
    dataList = list;
}
