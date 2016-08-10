#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include <QPropertyAnimation>
#include <QMouseEvent>
#include <QResizeEvent>
#include "ClassA.h"
#include "ClassB.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    void mousePressEvent(QMouseEvent *event);

    void mouseReleaseEvent(QMouseEvent *event);

    void mouseMoveEvent(QMouseEvent *event);

    void resizeEvent(QResizeEvent *);

private:
    Ui::Widget *ui;

    int m_iPageIdx;

    QWidget *m_wContent;

    ClassA *m_wPage1;

    ClassB *m_wPage2;

    QPoint m_pPress;

    QPoint m_pOldContent;

    QPropertyAnimation m_ani;

    void init();

    void initUi();

    void doAni(bool bToNext=true);

};

#endif // WIDGET_H
