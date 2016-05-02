#include "mainfenetre.h"

mainfenetre::mainfenetre()
{
    qw=new QWidget();
    core1=new QProgressBar();
    core2=new QProgressBar();
    core3=new QProgressBar();
    core4=new QProgressBar();
    core1->setValue(30);

    QTimer *timer=new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(onTimeOut()));
    timer->start(1000);

    grille=new QGridLayout;

    grille->addWidget(core1,0,0);
    grille->addWidget(core2,1,0);
    grille->addWidget(core3,2,0);
    grille->addWidget(core4,3,0);

    qw->setLayout(grille);
    qw->show();

}
void mainfenetre::onTimeOut(){
    int value1=rand()%100+1;
    int value2=rand()%100+1;
    int value3=rand()%100+1;
    int value4=rand()%100+1;
    core1->setValue(value1);
    core2->setValue(value2);
    core3->setValue(value3);
    core4->setValue(value4);
}
