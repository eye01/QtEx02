#include "ClassB.h"
#include "ui_ClassB.h"

ClassB::ClassB(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClassB)
{
    ui->setupUi(this);

}

ClassB::~ClassB()
{
    delete ui;
}


