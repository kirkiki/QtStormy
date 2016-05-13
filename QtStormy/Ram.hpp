#ifndef RAM_H
#define RAM_H

#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

class Ram
{
public:
    Ram();
    void parseData(std::string);
    int raminfo[3];
private:
    std::string rawdata;
};

#endif // RAM_H
