#include "mainfenetre.h"

#include <typeinfo>
using namespace QtCharts;
mainfenetre::mainfenetre()
{
    fenetre = new QWidget();

    onglets = new QTabWidget(fenetre);
    onglets->setGeometry(0, 0, 1300, 700);

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
    chart = new QChart();
    QValueAxis *axisX = new QValueAxis;
    QValueAxis *axisY = new QValueAxis;
    for(int i=0;i<10;i++){
        values[i]=0;
    }

    connect(timer, SIGNAL(timeout()),this,SLOT(onTimeOut()));
    timer->start(100);
    series = new QLineSeries;
    series->append(0,0);
    series->append(10,50);
    series->append(20,50);
    series->append(30,50);
    series->append(40,50);
    series->append(50,50);
    series->append(60,50);
    series->append(70,50);
    series->append(80,50);
    series->append(90,100);

    chart->addSeries(series);
    chart->setTitle("CPU pourcentage");
    axisY->setTickCount(100);
    axisX->setTickCount(100);
    chart->addAxis(axisX, Qt::AlignBottom);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisX);
    series->attachAxis(axisY);

    QChartView *view = new QChartView(chart);
    view->setRenderHint(QPainter::Antialiasing);

    grille->addWidget(core1,0,5);
    grille->addWidget(core2,1,5);
    grille->addWidget(core3,2,5);
    grille->addWidget(core4,3,5);
    grille->addWidget(view,4,5);
    page1->setLayout(grille);


    onglets->addTab(page2, "connexion");
    onglets->addTab(page1,"cpu");
    onglets->addTab(page3,"grid");

    fenetre->show();

}
void mainfenetre::onTimeOut(){
    core1->setValue(prctCoeur1);
    core2->setValue(prctCoeur2);
    core3->setValue(prctCoeur3);
    core4->setValue(prctCoeur4);

    for(int i=0;i<10;i++){
    series->replace(i,i*10,values[i]);
}
}

void mainfenetre::onConnexion(){
    //add=new QHostAddress(ipadd->text()); //a rajouter pour le projet
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
   // int firstValue;
    in >> prctCoeur1>>prctCoeur2>>prctCoeur3>>prctCoeur4;
    for(int i=9;i>0;i--){
        values[i]=values[i-1];
        qDebug()<<values[i];
    }
    values[0]=prctCoeur1;

    /*qDebug()<<prctCoeur1;
    qDebug()<<prctCoeur2;
    qDebug()<<prctCoeur3;
    qDebug()<<prctCoeur4;*/

}
