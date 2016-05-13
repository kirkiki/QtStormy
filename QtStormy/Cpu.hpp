#ifndef CPU_H
#define CPU_H

#include <iostream>
#include <vector>
#include <string>

class Cpu
{
public:
    Cpu();

    int t;
    int corenum;
    void parseData(std::string rawdata);
    void calculPercentage();
    double getPercentage();

private:
    int nbCore;
    std::vector <std::vector <long>> data;
    std::vector <std::vector <long>> lastData;
};

#endif // CPU_H
