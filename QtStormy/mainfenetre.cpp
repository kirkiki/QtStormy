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


    //page 1
    box=new QHBoxLayout;
    ipadd = new QLineEdit();
    seConnecter= new QPushButton("se connecter", this);
    sendSocket=new QUdpSocket(this);
    receiveSocket = new QUdpSocket(this);
    datagram=new QByteArray;
    ipadd->setInputMask("000.000.000.000;_");
    ipadd->setMaximumWidth(100);

    receiveSocket->bind(8000);
    connect(seConnecter,SIGNAL(clicked()),this, SLOT(onConnexion()));
    connect(receiveSocket, SIGNAL(readyRead()), this, SLOT(receive()));


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
    core1->setValue(prctCoeur1);
    core2->setValue(prctCoeur2);
    core3->setValue(prctCoeur3);
    core4->setValue(prctCoeur4);
}

void mainfenetre::onConnexion(){
    //add=new QHostAddress(ipadd->text());
    add=new QHostAddress(QHostAddress::LocalHost); // a enlever, pour le test
    QByteArray datagram;
    QDataStream out(&datagram, QIODevice::WriteOnly);
    out<< "hello alexis";
    sendSocket->writeDatagram(datagram, *add, 8000);
}

void mainfenetre::receive(){
    QByteArray datagram;
    do {
           datagram.resize(receiveSocket->pendingDatagramSize());
           receiveSocket->readDatagram(datagram.data(), datagram.size());
       } while (receiveSocket->hasPendingDatagrams());

    QDataStream in(&datagram, QIODevice::ReadOnly);
    in >> prctCoeur1>>prctCoeur2>>prctCoeur3>>prctCoeur4;
    //qDebug()<<prctCoeur1;
    /*qDebug()<<prctCoeur2;
    qDebug()<<prctCoeur3;
    qDebug()<<prctCoeur4;*/

}
