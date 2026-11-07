#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QComboBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QSpinBox>
#include <QPalette>
#include "displaywindow.h"
#include "shapecontainer.h"
#include "shapereader.h"
#include "memento.h"
#include "shapefactory.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void createGUI();

private:
    QSpinBox *penWidth;
    QSpinBox *prop1;
    QSpinBox *prop2;
    QComboBox *shapeList;
    QComboBox *penColor;
    QComboBox *fillColor;
    QPushButton *shapeCreation;
    QPushButton *previousButton;
    QPushButton *nextButton;
    QPushButton *backupButton;
    QPushButton *restoreButton;
    Shape *currentShape;
    DisplayWindow display;
    ShapeContainer *container;
    ShapeReader *Reader;
    Memento *caretaker;
    ShapeFactory *factory;
    bool hasBackup;

private slots:
    void createClicked();
    void showPrevious();
    void showNext();
    void makeBackup();
    void setRestore();


};

#endif // WIDGET_H
