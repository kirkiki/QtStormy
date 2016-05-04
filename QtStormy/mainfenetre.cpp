#include "mainfenetre.h"

#include <typeinfo>
mainfenetre::mainfenetre()
{
    fenetre = new QWidget();

    onglets = new QTabWidget(fenetre);
    onglets->setGeometry(30, 20, 240, 160);

    page1 = new QWidget;
    page2 = new QWidget;
    page3 = new QWidget;

    grille=new QGridLayout();
    core1 = new QProgressBar();
    core2 = new QProgressBar();
    core3 = new QProgressBar();
    core4 = new QProgressBar();

    soc=new QUdpSocket(this);
    datagram=new QByteArray;

    //connect(soc,SIGNAL(readyRead()),this,SLOT(deb()));

    //page 1
    box=new QHBoxLayout;
    ipadd = new QLineEdit();
    seConnecter= new QPushButton("se connecter", this);
    connect(seConnecter,SIGNAL(clicked()),this, SLOT(onConnexion()));
    ipadd->setInputMask("000.000.000.000;_");
    ipadd->setMaximumWidth(100);

    box->addWidget(ipadd);
    box->addWidget(seConnecter);
    page2->setLayout(box);

    //page 2
    QTimer *timer=new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(onTimeOut()));
    timer->start(1000);

    grille->addWidget(core1,0,5);
    grille->addWidget(core2,1,5);
    grille->addWidget(core3,2,5);
    grille->addWidget(core4,3,5);

    page1->setLayout(grille);


    onglets->addTab(page2, "connexion");
    onglets->addTab(page1,"cpu");

    fenetre->show();

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

void mainfenetre::onConnexion(){
    add=new QHostAddress(ipadd->text());
    qDebug()<<*add;
    QByteArray datagram;
    QDataStream out(&datagram, QIODevice::WriteOnly);
    out<< "hello alexis";
    soc->writeDatagram(datagram, *add, 8000);
}
void mainfenetre::deb(){
    qDebug()<<"ok";
}
