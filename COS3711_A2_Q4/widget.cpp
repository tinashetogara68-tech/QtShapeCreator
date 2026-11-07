#include "widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent)
{
    resize(800, 500);
    QPalette palette = QPalette();
    palette.setColor(QPalette::Window, Qt::gray);
    setPalette(palette);
    setWindowTitle("Shape Creator");

    currentShape = nullptr;
    hasBackup = false;
    QStringList colourList;
    colourList << "white" << "black" << "cyan" << "darkCyan" << "red" << "darkRed" << "magenta" << "darkMagenta" << "Green" << "darkGreen" << "yellow" << "darkYellow" << "blue" << "darkBlue" << "gray" << "darkGray";
    QStringList shapes;
    shapes << "Square" << "Rectangle" << "Ellipse" << "Circle";

    createGUI();

    shapeList->addItems(shapes);
    penColor->addItems(colourList);
    fillColor->addItems(colourList);

    container = ShapeContainer::getInstance();
    factory = new ShapeFactory;
    Reader = new ShapeReader(container, factory);

    display.setShape(container->getFirstShape());
    display.update();

    connect(shapeCreation, &QPushButton::clicked, this, &Widget::createClicked);
    connect(previousButton, &QPushButton::clicked, this, &Widget::showPrevious);
    connect(nextButton, &QPushButton::clicked, this, &Widget::showNext);
    connect(backupButton, &QPushButton::clicked, this, &Widget::makeBackup);
    connect(restoreButton, &QPushButton::clicked, this, &Widget::setRestore);
}

Widget::~Widget()
{
}

void Widget::createGUI()
{
    QLabel *shapeLabel = new QLabel("Shape");
    shapeList = new QComboBox();

    QLabel *penWidthLabel = new QLabel("Pen Width");
    penWidth = new QSpinBox();
    penWidth->setMaximum(10);

    QLabel *penColorLabel = new QLabel("Pen Colour");
    penColor = new QComboBox();

    QLabel *fillColorLabel = new QLabel("Fill Colour");
    fillColor = new QComboBox();

    QLabel *prop1Label = new QLabel("Width");
    prop1 = new QSpinBox();
    prop1->setMinimum(50);
    prop1->setMaximum(350);

    QLabel *prop2Label = new QLabel("Height");
    prop2 = new QSpinBox();
    prop2->setMinimum(50);
    prop2->setMaximum(350);

    shapeCreation = new QPushButton("Create Shape");
    previousButton = new QPushButton("Previous");
    nextButton = new QPushButton("Next");
    backupButton = new QPushButton("Backup");
    restoreButton = new QPushButton("Restore");

    QVBoxLayout *fullWindow = new QVBoxLayout();
    QGridLayout *grid = new QGridLayout();

    grid->addWidget(shapeLabel, 0, 0);
    grid->addWidget(shapeList, 0, 1);
    grid->addWidget(prop1Label, 0, 2);
    grid->addWidget(prop1, 0, 3);
    grid->addWidget(penWidthLabel, 1, 0);
    grid->addWidget(penWidth, 1, 1);
    grid->addWidget(prop2Label, 1, 2);
    grid->addWidget(prop2, 1, 3);
    grid->addWidget(penColorLabel, 2, 0);
    grid->addWidget(penColor, 2, 1);
    grid->addWidget(fillColorLabel, 3, 0);
    grid->addWidget(fillColor, 3, 1);
    grid->addWidget(shapeCreation, 2, 2, 2, 2);
    grid->addWidget(&display, 4, 0, 1, 4);
    grid->addWidget(previousButton, 5, 0);
    grid->addWidget(nextButton, 5, 3);
    grid->addWidget(backupButton, 6, 0);
    grid->addWidget(restoreButton, 6, 3);

    fullWindow->addLayout(grid);

    setLayout(fullWindow);
}

void Widget::createClicked()
{
    int pWidth = penWidth->value();
    QColor pColor = QColor::fromString(penColor->currentText());
    QColor fColor = QColor::fromString(fillColor->currentText());
    int firstDimension = prop1->value();
    int secondDimension = prop2->value();

    currentShape = factory->factoryCreateShape(shapeList->currentText(), pWidth, pColor, fColor, firstDimension, secondDimension);
    if(currentShape)
        container->addToList(currentShape);

    display.setShape(currentShape);
    display.update();
    qDebug() << "Number of shapes: " << container->getListSize();

}

void Widget::showPrevious()
{
    if(!(container->getCurrentShape() == NULL))
    {
        container->movePreviousShape();
        display.setShape(container->getCurrentShape());
        display.update();
    }
}

void Widget::showNext()
{

    if(!(container->getCurrentShape() == NULL))
    {
        container->moveNextShape();
        display.setShape(container->getCurrentShape());
        display.update();
    }
}

void Widget::makeBackup()
{
    caretaker = container->createMemento();
    hasBackup = true;
}

void Widget::setRestore()
{
    if(hasBackup == true)
    {
        container->setMemento(caretaker, factory);
        display.setShape(container->getFirstShape());
        display.update();
    }
    else
        return;
    qDebug() << "Number of shapes: " << container->getListSize();
}
