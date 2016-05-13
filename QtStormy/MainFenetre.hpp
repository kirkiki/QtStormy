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

#include "ConnectionWidget.hpp"
#include "DataWidget.hpp"



using namespace QtCharts;
class mainfenetre: public QObject
{
    Q_OBJECT

    public:

public:
    mainfenetre();
    DataWidget* Data();
    void miseEnPlace();
    void page1Init();
    void page2Init();
    void page3Init();
    QString color();
    void colorCore(QProgressBar *bar, uint32_t prct);

public slots:
    void onTimeOut();
    void sliderChange();

private:
    QWidget* fenetre;

    ConnectionWidget *connecWidget;

    DataWidget* dataWidget;

    QVBoxLayout* containerLayout;

    /*

    QTabWidget *tabs;
    QWidget *cpuPage;
    QWidget *ramPage;

    QProgressBar *core1;
    QProgressBar *core2;
    QProgressBar *core3;
    QProgressBar *core4;

    QGridLayout *box;
    QChart *chart;
    QLineSeries *series;
    QLineSeries *series2;
    QLineSeries *series3;
    QLineSeries *series4;
    QChartView *view;
    QTimer *timer;
    QCategoryAxis *axisX;
    QCategoryAxis *axisY;


    QVBoxLayout * containerLayout;
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


    QByteArray *datagram;
    std::string *s;

    std::uint32_t prctCoeur1=0;
    std::uint32_t prctCoeur2=0;
    std::uint32_t prctCoeur3=0;
    std::uint32_t prctCoeur4=0;
    std::uint32_t temp=0;
    int values [10];
    int values2 [10];
    int values3 [10];
    int values4 [10];
    int nbrRam;
    int prctRam;
    int valuesRam [10];
    std::string coeur;

*/
};

    #endif // MAINFENETRE_H

