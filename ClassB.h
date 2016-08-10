#ifndef CLASSB_H
#define CLASSB_H

#include <QWidget>
#include <QShowEvent>
#include <QHideEvent>
#include <QDir>
#include <QTimer>
#include <QResizeEvent>
namespace Ui {
class ClassB;
}

class ClassB : public QWidget
{
    Q_OBJECT

public:
    explicit ClassB(QWidget *parent = 0);
    ~ClassB();

private:
    Ui::ClassB *ui;


};

#endif // CLASSB_H
