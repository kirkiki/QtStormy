#include "ConnectionWidget.hpp"
#include "Api/Packet.hpp"
#include <QUdpSocket>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QHostAddress>
#include <QTimer>
#include "MainFenetre.hpp"

ConnectionWidget::ConnectionWidget(mainfenetre * master):
    master(master),
    receiveSocket(new QUdpSocket(this)),
    container(new QHBoxLayout(this)),
    ipInputField(new QLineEdit()),
    connectionButton(new QPushButton("Connexion", this)),
    timerIsAlive(new QTimer())
{   
    dataWidgets = master->Data();

    ipInputField->setInputMask("000.000.000.000; ");
    ipInputField->setMaximumWidth(100);
    ipInputField->setMaximumHeight(50);

    connectionButton->setMaximumWidth(100);
    connectionButton->setMaximumHeight(50);

    receiveSocket->bind(8000);



    container->addWidget(ipInputField);
    container->addWidget(connectionButton);

    setLayout(container);
    //container->killTimer();

    /*slider = new QSlider(Qt::Horizontal);
    tick1= new QLabel("1",this);
    tick2= new QLabel("2",this);
    tick3= new QLabel("3",this);
    tick4= new QLabel("4",this);
    tick5= new QLabel("5",this);
    second=new QLabel("temps de rafraichissement (en seconde)",this);*/

    //Init slot
    connect(receiveSocket, SIGNAL(readyRead()), this, SLOT(onReceive()));
    connect(connectionButton,SIGNAL(clicked()),this, SLOT(onConnexion()));
    connect(timerIsAlive,SIGNAL(timeout()),this, SLOT(onTimeAliveOver()));
}

void ConnectionWidget::onTimeAliveOver(){
    add=new QHostAddress(ipInputField->text());
    Packet packet;
    std::string cmd = "alive";
    std::string id = "Tonton JMFN";
    packet << cmd << id;

    char * data = (char*)packet.getData();
    receiveSocket->writeDatagram(data,packet.getDataSize(),*add, 8003);
}

void ConnectionWidget::onReceive(){
    QByteArray datagram;
    do {
           datagram.resize(receiveSocket->pendingDatagramSize());
           receiveSocket->readDatagram(datagram.data(), datagram.size());
       } while (receiveSocket->hasPendingDatagrams());

   QDataStream in(&datagram, QIODevice::ReadOnly);
   // int firstValue;
   dataWidgets->parseDatas(in);


   /*temp=atoi(ch);
   Cpu cpu (ch);

    //temp=40;
    for(int i=9;i>0;i--){
        values[i]=values[i-1];
        values2[i]=values2[i-1];
        values3[i]=values3[i-1];
        values4[i]=values4[i-1];
        valuesRam[i]=valuesRam[i-1];
    }
    values[0]=prctCoeur1;
    //values[0]= cpu.getInfo(0);
    values2[0]=prctCoeur2;
    //values2[0]= cpu.getInfo(1);
    values3[0]=prctCoeur3;
    //values3[0]= cpu.getInfo(2);
    values4[0]=prctCoeur4;
    //values'[0]= cpu.getInfo(3);
    valuesRam[0]=prctRam;*/
}


void ConnectionWidget::onConnexion(){
    add=new QHostAddress(ipInputField->text());
    timerIsAlive->start(5000);

    Packet packet;
    std::string cmd = "hello";
    std::string id = "Tonton JMFN";
    packet << cmd << id;

    char * data = (char*)packet.getData();
    receiveSocket->writeDatagram(data, packet.getDataSize() ,*add, 8003);
}
