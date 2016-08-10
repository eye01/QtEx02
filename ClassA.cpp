#include "ClassA.h"
#include "ui_ClassA.h"

ClassA::ClassA(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClassA)
{
    ui->setupUi(this);

    // QString sPath="/Users/chenchaowei/work/qt_project/eye/EyeEx02/res/king/714.png";   //QApplication::applicationDirPath();
    //  ui->wImage0->setStyleSheet("image:url("+sPath+")");



    if (m_pixArray.size() == 0)
    {

        QStringList stringFilter;
        stringFilter<<"*.png";
        QString path=QApplication::applicationDirPath();
        QDir dir("/Users/chenchaowei/work/qt_project/eye/EyeEx02/res/king/");
        QStringList fileList = dir.entryList(stringFilter);
        qDebug()<<"ii1  "<<fileList.count();
        for(int i=0;i<fileList.count();i++)
        {

            m_pixArray.push_back(new QPixmap("/Users/chenchaowei/work/qt_project/eye/EyeEx02/res/king/"+ fileList[i]));
        }

    }


    connect(&m_timer, SIGNAL(timeout()), this, SLOT(animation()));

}

ClassA::~ClassA()
{
    delete ui;
}

void ClassA::animation()
{
    if(m_pixArray.count()<1)
        return;
    ui->lb->setPixmap(m_pixArray[k]->scaled(ui->lb->size()));
    k = (k+1)%(m_pixArray.size());
}

void ClassA::showEvent(QShowEvent *)
{
    m_timer.stop();
    k=0;
    m_timer.start(100);
}

void ClassA::hideEvent(QHideEvent *)
{
      m_timer.stop();
}



