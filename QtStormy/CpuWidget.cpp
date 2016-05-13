#include "CpuWidget.hpp"
#include "Cpu.hpp"

CpuWidget::CpuWidget() :
    data(new Cpu()),
    firstTime(true),
    container(new QGridLayout),
    chart(new QChart()),
    chartView(new QChartView()),
    xAxis(new QCategoryAxis()),
    yAxis(new QCategoryAxis()),
    timer(new QTimer)

{
    yAxis->append("low",33);
    yAxis->append("middle",66);
    yAxis->append("high",100);
    yAxis->setRange(0,100);
    yAxis->setRange(0,100);
    yAxis->setGridLineVisible(true);
    xAxis->setGridLineVisible(true);

    timer->start(100);

    chart->legend()->hide();

    chart->setTitle("CPU pourcentage");
    yAxis->setTickCount(100);
    xAxis->setTickCount(100);
    chart->addAxis(xAxis, Qt::AlignBottom);
    chart->addAxis(yAxis, Qt::AlignLeft);

    chartView->setRenderHint(QPainter::Antialiasing);
    container->addWidget(chartView);
    setLayout(container);
}


void CpuWidget::parseData(std::string datas){
    data->parseData(datas);
        for(int i = 0; i < data->getNbCore(); i++){

            if(firstTime){
                QLineSeries * serie = new QLineSeries();
                chartsValues.push_back(std::vector<double>(10));
                for(int j = 0; j < 10; j++){
                    serie->append(j,4);
                    chartsValues[i][j] = 0;
                }
                chart->addSeries(serie);

                serie->attachAxis(xAxis);
                serie->attachAxis(yAxis);

                series.push_back(serie);

                QProgressBar * core = new QProgressBar();
                core->setTextVisible(true);
                core->setAlignment(Qt::AlignCenter);

                container->addWidget(core,i,5);

                progressBars.push_back(core);

                temperature = new QProgressBar();
                temperature->setOrientation(Qt::Vertical);

                container->addWidget(temperature,4,6);
            }
            else{
                for(int k=9;k>0;k++){
                     QLineSeries * se = series[i];

                     se->replace(k,k*10,  chartsValues[i][k-1]);
                }


                double prct = data->getPrct(i);
                series[i]->replace(0,0, prct);
                progressBars[i]->setValue(prct);
                temperature->setValue(data->getTemperature());

                progressBars[i]->setFormat(QStringLiteral("Core").arg(prct));
                colorCore(progressBars[i], prct);

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

            }
        }
        firstTime = false;
}


void CpuWidget::colorCore(QProgressBar *bar,uint32_t prct){
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
    bar->setStyleSheet(style_sheet);
}

QString CpuWidget::color(){
    int temp = data->getTemperature();
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



