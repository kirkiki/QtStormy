#include "DataWidget.hpp"
#include "MainFenetre.hpp"
#include "CpuWidget.hpp"

DataWidget::DataWidget(mainfenetre * master):
    master(master),
    tabs(new QTabWidget),
    ramPage(new QWidget(this)),
    container(new QGridLayout)
{

    tabs->addTab(&cpusWidget, "CPU");
    tabs->addTab(ramPage, "RAM");
    container->addWidget(tabs);

    setLayout(container);
}


void DataWidget::parseDatas(QDataStream & packet){
    char* cpuDatas;
    //std::string ramDatas;
    //std::string diskDatas;

    packet>>cpuDatas;
    //packet>>ramDatas;
    //packet>>diskDatas;
    std::string str = cpuDatas;

    cpusWidget.parseData(str);
    //ramWidget->parseData(ramDatas);
    //diskWidget->parseData(diskDatas);
}
