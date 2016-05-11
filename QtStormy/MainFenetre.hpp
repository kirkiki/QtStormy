#ifndef MAINFENETRE_H
#define MAINFENETRE_H
#include <iostream>
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QMessageBox>
#include <QLineEdit>
#include <QGridLayout>
#include <QMainWindow>
#include <QProgressBar>
#include <QTimer>
#include <QTabWidget>
#include <QHBoxLayout>
#include <QUdpSocket>
#include <QByteArray>
#include <QHostAddress>
#include <string>
#include <QDataStream>
#include <QtCharts>
#include <QPalette>
#include <QSlider>

using namespace QtCharts;
class mainfenetre: public QMainWindow
{
    Q_OBJECT

    public:
    mainfenetre();
    void miseEnPlace();
    void page1Init();
    void page2Init();
    void page3Init();
    QString color();
    void colorCore(QProgressBar *bar, uint32_t prct);

public slots:
    void onTimeOut();
    void onConnexion();
    void receive();
    void isAlive();
    void sliderChange();


private:
    QWidget *fenetre;

    QTabWidget *onglets;
    QWidget *page1;
    QWidget *page2;
    QWidget *page3;

    QGridLayout *grille;
    QProgressBar *core1;
    QProgressBar *core2;
    QProgressBar *core3;
    QProgressBar *core4;

    QGridLayout *box;
    QLineEdit *ipadd;
    QPushButton *seConnecter;
    QChart *chart;
    QLineSeries *series;
    QLineSeries *series2;
    QLineSeries *series3;
    QLineSeries *series4;
    QChartView *view;
    QTimer *timer;
    QCategoryAxis *axisX;
    QCategoryAxis *axisY;
    QGridLayout *grid;

    QSlider *slider;
    QLabel *tick1;
    QLabel *tick2;
    QLabel *tick3;
    QLabel *tick4;
    QLabel *tick5;
    QLabel *second;


    QLineSeries *ram;
    QChart *chartRam;
    QChartView *viewRam;
    QCategoryAxis *ramGo;
    QCategoryAxis *time;
    QProgressBar *temperature;

    QUdpSocket *sendSocket;
    QUdpSocket *receiveSocket;
    QHostAddress *add;
    QByteArray *datagram;
    std::string *s;
    QTimer *timerIsAlive;

    std::uint32_t prctCoeur1;
    std::uint32_t prctCoeur2;
    std::uint32_t prctCoeur3;
    std::uint32_t prctCoeur4;
    std::uint32_t temp;
    int values [10];
    int values2 [10];
    int values3 [10];
    int values4 [10];
    int nbrRam;
    int prctRam;
    int valuesRam [10];
    std::string coeur;


};

    #endif // MAINFENETRE_H

