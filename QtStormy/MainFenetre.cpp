#include "MainFenetre.hpp"
#include <iostream>
#include <typeinfo>
#include "Api/Packet.hpp"
#include "Cpu.hpp"

using namespace QtCharts;

mainfenetre::mainfenetre()
{
    miseEnPlace();
    page1Init();
    page2Init();
    page3Init();

    connect(seConnecter,SIGNAL(clicked()),this, SLOT(onConnexion()));
    connect(receiveSocket, SIGNAL(readyRead()), this, SLOT(receive()));
    connect(timer, SIGNAL(timeout()),this,SLOT(onTimeOut()));
    connect(timerIsAlive,SIGNAL(timeout()),this, SLOT(isAlive()));
    connect(slider,SIGNAL(valueChanged(int)),this,SLOT(sliderChange(int)));
    //temperature->setStyleSheet("selection-background-color: black;");

    fenetre->show();

}
void mainfenetre::miseEnPlace(){
    fenetre = new QWidget();

    onglets = new QTabWidget(fenetre);
    onglets->setGeometry(0, 0, 1300, 700);

    page1 = new QWidget;
    page2 = new QWidget;
    page3 = new QWidget;

    box=new QGridLayout;
    ipadd = new QLineEdit();
    seConnecter= new QPushButton("se connecter", this);
    sendSocket=new QUdpSocket(this);
    receiveSocket = new QUdpSocket(this);
    datagram=new QByteArray;
    nbrRam=8; //a changer pour avoir le nbr de ram max
    timerIsAlive=new QTimer(this);
    slider = new QSlider(Qt::Horizontal);
    tick1= new QLabel("1",this);
    tick2= new QLabel("2",this);
    tick3= new QLabel("3",this);
    tick4= new QLabel("4",this);
    tick5= new QLabel("5",this);
    second=new QLabel("temps de rafraichissement (en seconde)",this);

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
    temperature = new QProgressBar;

    ram=new QLineSeries;
    chartRam = new QChart;
    viewRam = new QChartView(chartRam);
    ramGo = new QCategoryAxis;
    time = new QCategoryAxis;
    grid = new QGridLayout;

    onglets->addTab(page1, "connexion");
    onglets->addTab(page2,"cpu");
    onglets->addTab(page3,"RAM");
}

void mainfenetre::page1Init(){

    ipadd->setInputMask("000.000.000.000;_");
    ipadd->setMaximumWidth(150);
    receiveSocket->bind(8000);
    box->addWidget(ipadd);
    box->addWidget(seConnecter);

    slider->setRange(0.5,5);
    slider->setSingleStep(1);

    box->addWidget(ipadd,2,3,1,1);
    box->addWidget(seConnecter,2,4,1,1);
    box->addWidget(slider,3,2,1,5);
    box->addWidget(tick1,3,3,1,1);
    box->addWidget(tick2,3,4,1,1);
    box->addWidget(tick3,3,5,1,1);
    box->addWidget(tick4,3,6,1,1);
    box->addWidget(tick5,3,7,1,1);
    box->addWidget(second,3,1);

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
    temperature->setOrientation(Qt::Vertical);
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
    core1->setTextVisible(true);
    core2->setTextVisible(true);
    core3->setTextVisible(true);
    core4->setTextVisible(true);



    core1->setAlignment(Qt::AlignCenter);
    core2->setAlignment(Qt::AlignCenter);
    core3->setAlignment(Qt::AlignCenter);
    core4->setAlignment(Qt::AlignCenter);

    grille->addWidget(core1,0,5);
    grille->addWidget(core2,1,5);
    grille->addWidget(core3,2,5);
    grille->addWidget(core4,3,5);
    grille->addWidget(view,4,5);
    grille->addWidget(temperature,4,6);
    page2->setLayout(grille);
}

void mainfenetre::page3Init(){
    chartRam->addSeries(ram);
    chartRam->addAxis(ramGo,Qt::AlignLeft);
    chartRam->addAxis(time,Qt::AlignBottom);
    ram->attachAxis(ramGo);
    ram->attachAxis(time);

    ramGo->append("low",2);
    ramGo->append("normal",6);
    ramGo->append("high",8);
    chartRam->setTitle("RAM pourcentage");
    ramGo->setGridLineVisible(true);

    ram->append(0,0);
    ram->append(10,1);
    ram->append(20,1);
    ram->append(30,1);
    ram->append(40,1);
    ram->append(50,1);
    ram->append(60,1);
    ram->append(70,1);
    ram->append(80,1);
    ram->append(90,1);
    ramGo->setRange(0,nbrRam);
    time->setRange(0,100);



    view->setRenderHint(QPainter::Antialiasing);
    grid->addWidget(viewRam,0,0);
    page3->setLayout(grid);
}

void mainfenetre::onTimeOut(){
    core1->setValue(prctCoeur1);
    core2->setValue(prctCoeur2);
    core3->setValue(prctCoeur3);
    core4->setValue(prctCoeur4);
    temperature->setValue(temp);


    core1->setFormat(QStringLiteral("Core1 : %1 %").arg(prctCoeur1));
    core2->setFormat(QStringLiteral("Core2 : %1 %").arg(prctCoeur2));
    core3->setFormat(QStringLiteral("Core3 : %1 %").arg(prctCoeur3));
    core4->setFormat(QStringLiteral("Core4 : %1 %").arg(prctCoeur4));

    colorCore(core1,prctCoeur1);
    colorCore(core2,prctCoeur2);
    colorCore(core3,prctCoeur3);
    colorCore(core4,prctCoeur4);


    QString style_sheet ;
    style_sheet +=  QString("QProgressBar {"
                                "%0"
                                "border: 2px solid grey;"
                                "border-radius: 5px;"
                                "text-align: center;"
                                "}").arg(color()) ;
    style_sheet +=  "QProgressBar::chunk {"
                                "background: transparent;"
                                "width: 10px;"
                                "margin: 0.5px;"
                                "}" ;
    temperature->setStyleSheet(style_sheet);

    for(int i=0;i<10;i++){
         series->replace(i,i*10,values[i]);
         series2->replace(i,i*10,values2[i]);
         series3->replace(i,i*10,values3[i]);
         series4->replace(i,i*10,values4[i]);
         ram->replace(i,i*10,valuesRam[i]);
    }
}

void mainfenetre::onConnexion(){
    //add=new QHostAddress(ipadd->text()); //a rajouter pour le projet
    add=new QHostAddress(QHostAddress::LocalHost); // a enlever, pour le test
    timerIsAlive->start(5000);

    Packet packet;
    std::string cmd = "hello";
    std::string id = "Tonton JMFN";
    packet << cmd << id;

    char * data = (char*)packet.getData();
    receiveSocket->writeDatagram(data, packet.getDataSize() ,*add, 8003);
}

void mainfenetre::receive(){
    QByteArray datagram;
    do {
           datagram.resize(receiveSocket->pendingDatagramSize());
           receiveSocket->readDatagram(datagram.data(), datagram.size());
       } while (receiveSocket->hasPendingDatagrams());

    QDataStream in(&datagram, QIODevice::ReadOnly);
   // int firstValue;
   char * ch;
   char * ch2;

   in >> ch;
   in >> ch2;

   Cpu lol(ch);

    //temp=40;
    for(int i=9;i>0;i--){
        values[i]=values[i-1];
        values2[i]=values2[i-1];
        values3[i]=values3[i-1];
        values4[i]=values4[i-1];
        valuesRam[i]=valuesRam[i-1];

    }
    values[0]=prctCoeur1;
    values2[0]=prctCoeur2;
    values3[0]=prctCoeur3;
    values4[0]=prctCoeur4;
    valuesRam[0]=prctRam;


    /*qDebug(LocalHost)<<prctCoeur1;
    qDebug()<<prctCoeur2;
    qDebug()<<prctCoeur3;
    qDebug()<<prctCoeur4;*/

}

QString mainfenetre::color(){
    QString low = QString("background: qlineargradient(x1: 1, y1: 0, x2: 1, y2: 1, stop: 1 blue, stop: %0 white, stop: 0 white);").arg(1-(temp/100.0)) ;
    QString middle = QString("background: qlineargradient(x1: 1, y1: 0, x2: 1, y2: 1, stop: 1 blue, stop: 0.66 orange, stop: %0 white, stop: 0 white);").arg(1-(temp/100.0));
    QString high = QString("background: qlineargradient(x1: 1, y1: 0, x2: 1, y2: 1, stop: 1 blue, stop: 0.55 orange, stop: 0.25 red, stop: %0 white, stop:0 white);").arg(1-(temp/100.0));
    QString full = QString("background: qlineargradient(x1: 1, y1: 0, x2: 1, y2: 1, stop: 1 blue, stop: 0.55 orange, stop: 0.25 red stop:0 red);");
    if(temp<33){
        return low;
    }
    else if(temp<75){
        return middle;
    }
    else if(temp==100) {
        return full;
    }
    else {
        return high;
    }
}

void mainfenetre::colorCore(QProgressBar *bar,uint32_t prct){
    QString updated_bg = QString("background: qlineargradient(x1: 0, y1: 0.5, x2: 1, y2: 0.5, stop: 0.0 black, stop: %0 white, stop: 1.0 white);").arg((prct/100.0)) ;
                QString style_sheet ;
                style_sheet +=  QString("QProgressBar {"
                                "%0"
                                "border: 2px solid grey;"
                                "border-radius: 5px;"
                                "text-align: center;"
                                "}").arg(updated_bg) ;
                style_sheet +=  "QProgressBar::chunk {"
                                "background: transparent;"
                                "width: 10px;"
                                "margin: 0.5px;"
                                "}" ;
                bar->setStyleSheet(style_sheet) ;
}

void mainfenetre::isAlive(){
    add=new QHostAddress(QHostAddress::LocalHost);
    QByteArray datagram;
    Packet packet;
    std::string cmd = "alive";
    std::string id = "Tonton JMFN";
    packet << cmd << id;

    char * data = (char*)packet.getData();
    receiveSocket->writeDatagram(data, 17 ,*add, 8003);
}

void mainfenetre::sliderChange(int *value){
    qDebug()<<value;
}
