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
    std::vector <double> actualprc;
    void parseData(std::string rawdata);
    void calculPercentage();

private:
    std::vector <std::vector <long>> data;
    std::vector <std::vector <long>> lastData;

};

#endif // CPU_H
