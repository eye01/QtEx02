#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    initUi();

    init();

}

Widget::~Widget()
{
    delete ui;
}

void Widget::init()
{
    m_iPageIdx=0;

    m_ani.setTargetObject(m_wContent);

    m_ani.setPropertyName("pos");

    m_ani.setDuration(200);

}

void Widget::initUi()
{
    m_wContent=new QWidget(this);

    m_wPage1=new ClassA(m_wContent);

    m_wPage2=new ClassB(m_wContent);



}

void Widget::doAni(bool bToNext)
{

    if(bToNext)
        m_iPageIdx=1;
    else
        m_iPageIdx=0;

    QPoint pStart(m_wContent->pos());

    QPoint pEnd(0,0);

    if(bToNext)
        pEnd.setX(-width());

    m_ani.setStartValue(pStart);

    m_ani.setEndValue(pEnd);

    m_ani.start();

}

void Widget::mousePressEvent(QMouseEvent *event)
{
    m_pPress=event->pos();

    m_pOldContent=m_wContent->pos();
}

void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    bool bToNext= m_pPress.x()-event->pos().x()>0 && m_wContent->x()<-width()/2;
    doAni(bToNext);
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    int iDiffX=event->pos().x()-m_pPress.x();

    m_wContent->move(m_pOldContent.x()+iDiffX,0);
}

void Widget::resizeEvent(QResizeEvent *)
{
    m_wContent->resize(width()*2,height());

    m_wPage1->resize(size());

    m_wPage1->move(0,0);

    m_wPage2->resize(size());

    m_wPage2->move(width(),0);

    if(m_iPageIdx==0)
        m_wContent->move(0,0);
    else
        m_wContent->move(-m_wPage1->width(),0);
}
