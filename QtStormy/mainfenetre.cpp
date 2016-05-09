#include "mainfenetre.h"

#include <typeinfo>
using namespace QtCharts;
mainfenetre::mainfenetre()
{
    miseEnPlace();
    page1Init();
    page2Init();

    connect(seConnecter,SIGNAL(clicked()),this, SLOT(onConnexion()));
    connect(receiveSocket, SIGNAL(readyRead()), this, SLOT(receive()));
    connect(timer, SIGNAL(timeout()),this,SLOT(onTimeOut()));


    fenetre->show();

}
void mainfenetre::miseEnPlace(){
    fenetre = new QWidget();

    onglets = new QTabWidget(fenetre);
    onglets->setGeometry(0, 0, 1300, 700);

    page1 = new QWidget;
    page2 = new QWidget;
    page3 = new QWidget;

    box=new QHBoxLayout;
    ipadd = new QLineEdit();
    seConnecter= new QPushButton("se connecter", this);
    sendSocket=new QUdpSocket(this);
    receiveSocket = new QUdpSocket(this);
    datagram=new QByteArray;


    grille=new QGridLayout();
    core1 = new QProgressBar();
    core2 = new QProgressBar();
    core3 = new QProgressBar();
    core4 = new QProgressBar();

    series = new QLineSeries;
    series2=new QLineSeries;
    series3 = new QLineSeries;
    chart = new QChart;
    series4 = new QLineSeries;
    view = new QChartView(chart);
    timer=new QTimer(this);
    axisX= new QCategoryAxis;
    axisY = new QCategoryAxis;


    onglets->addTab(page1, "connexion");
    onglets->addTab(page2,"cpu");


}

void mainfenetre::page1Init(){

    ipadd->setInputMask("000.000.000.000;_");
    ipadd->setMaximumWidth(100);

    receiveSocket->bind(8000);



    box->addWidget(ipadd);
    box->addWidget(seConnecter);
    page1->setLayout(box);
}

void mainfenetre::page2Init(){

    axisY->append("low",33);
    axisY->append("middle",66);
    axisY->append("high",100);
    axisY->setRange(0,100);
    axisY->setRange(0,100);
    axisY->setGridLineVisible(true);
    axisX->setGridLineVisible(true);
    for(int i=0;i<10;i++){
        values[i]=0;
        values2[i]=0;
    }

    timer->start(100);

    //core1
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

    //core2
    series2->append(0,0);
    series2->append(10,50);
    series2->append(20,50);
    series2->append(30,50);
    series2->append(40,50);
    series2->append(50,50);
    series2->append(60,50);
    series2->append(70,50);
    series2->append(80,50);
    series2->append(90,100);
    //core3
    series3->append(0,0);
    series3->append(10,50);
    series3->append(20,50);
    series3->append(30,50);
    series3->append(40,50);
    series3->append(50,50);
    series3->append(60,50);
    series3->append(70,50);
    series3->append(80,50);
    series3->append(90,100);
    //Core4
    series4->append(0,0);
    series4->append(10,50);
    series4->append(20,50);
    series4->append(30,50);
    series4->append(40,50);
    series4->append(50,50);
    series4->append(60,50);
    series4->append(70,50);
    series4->append(80,50);
    series4->append(90,100);

    chart->legend()->hide();
    chart->addSeries(series);
    chart->addSeries(series2);
    chart->addSeries(series3);
    chart->addSeries(series4);

    chart->setTitle("CPU pourcentage");
    axisY->setTickCount(100);
    axisX->setTickCount(100);
    chart->addAxis(axisX, Qt::AlignBottom);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisX);
    series->attachAxis(axisY);

    view->setRenderHint(QPainter::Antialiasing);

    grille->addWidget(core1,0,5);
    grille->addWidget(core2,1,5);
    grille->addWidget(core3,2,5);
    grille->addWidget(core4,3,5);
    grille->addWidget(view,4,5);
    page2->setLayout(grille);


}

void mainfenetre::onTimeOut(){
    core1->setValue(prctCoeur1);
    core2->setValue(prctCoeur2);
    core3->setValue(prctCoeur3);
    core4->setValue(prctCoeur4);

    for(int i=0;i<10;i++){
         series->replace(i,i*10,values[i]);
         series2->replace(i,i*10,values2[i]);
         series3->replace(i,i*10,values3[i]);
         series4->replace(i,i*10,values4[i]);

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
        values2[i]=values2[i-1];
        values3[i]=values3[i-1];
        values4[i]=values4[i-1];

    }
    values[0]=prctCoeur1;
    values2[0]=prctCoeur2;
    values3[0]=prctCoeur3;
    values4[0]=prctCoeur4;


    /*qDebug()<<prctCoeur1;
    qDebug()<<prctCoeur2;
    qDebug()<<prctCoeur3;
    qDebug()<<prctCoeur4;*/

}
