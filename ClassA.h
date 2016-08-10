#ifndef CLASSA_H
#define CLASSA_H

#include <QWidget>
#include <QDebug>
#include <QDir>
#include <QApplication>
#include <QTimer>
#include <QShowEvent>
#include <QHideEvent>
#include <QTimerEvent>

namespace Ui {
class ClassA;
}

class ClassA : public QWidget
{
    Q_OBJECT

public:
    explicit ClassA(QWidget *parent = 0);
    ~ClassA();

private:
    Ui::ClassA *ui;

    int k;

    QVector<QPixmap*> m_pixArray;

    QTimer m_timer;

    void showEvent(QShowEvent *);

    void hideEvent(QHideEvent *);

private slots:
    void animation();

};

#endif // CLASSA_H
