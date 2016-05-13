#ifndef CPUWIDGET_H
#define CPUWIDGET_H

#include <QWidget>
#include <QProgressBar>
#include <QLineSeries>
#include <QVBoxLayout>
#include <QChartView>
#include <QChart>
#include <QCategoryAxis>
#include <QTimer>
#include <iostream>
#include <vector>
#include <string>


using namespace QtCharts;
class Cpu;
class CpuWidget : public QWidget
{
public:
    CpuWidget();

    void parseData(std::string datas);

    QString color();
    void colorCore(QProgressBar *bar,uint32_t prct);

private:
    Cpu * data;
    bool firstTime;

    QGridLayout * container;
    QProgressBar * temperature;
    std::vector<QProgressBar*> progressBars;
    std::vector<std::vector<double>> chartsValues;
    std::vector<QLineSeries*> series;
    QChart * chart;
    QChartView * chartView;
    QCategoryAxis * xAxis;
    QCategoryAxis * yAxis;
    QTimer* timer;
};

#endif // CPUWIDGET_H
