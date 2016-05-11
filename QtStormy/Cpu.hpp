#ifndef CPU_H
#define CPU_H

#include <iostream>
#include <vector>
#include <string>

class Cpu
{
public:
    Cpu(char * rawdata);
    void parseData(std::string rawdata);
private:
    std::vector <int> core;
    std::vector <std::string> rawcore;
};

#endif // CPU_H
