#ifndef CPU_H
#define CPU_H

#include <iostream>
#include <vector>
#include <string>

class Cpu
{
public:
    Cpu();

    int corenum;

    void parseData(std::string rawdata);
    void calculPercentage();

    int getNbCore();
    int getTemperature();
    double getPrct(int coreIndex);


private:

    std::vector <double> actualprc;
    int nbCore;
    int temperature;

    std::vector <std::vector <long>> data;
    std::vector <std::vector <long>> lastData;

};

#endif // CPU_H
