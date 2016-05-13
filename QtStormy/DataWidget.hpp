#ifndef DATAWIDGET_H
#define DATAWIDGET_H
#include <QWidget>
#include <QGridLayout>
#include <QTabWidget>
#include <QMainWindow>
#include "Api/Packet.hpp"

#include "CpuWidget.hpp"
class mainfenetre;
class DataWidget : public QWidget
{
public:
    DataWidget(mainfenetre * master);

    void parseDatas(QDataStream & packet);


private:

    bool firstTime;
    mainfenetre * master;

    CpuWidget cpusWidget;
    //Ram* ramWidget;
    QTabWidget*  tabs;
    QWidget* ramPage;
    QGridLayout * container;

};

#endif // DATAWIDGET_H
