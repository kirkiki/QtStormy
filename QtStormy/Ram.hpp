#ifndef RAM_H
#define RAM_H

#include <iostream>
#include <string>

class Ram
{
public:
    Ram();
    void parseData(std::string);
private:
    std::string rawdata;
};

#endif // RAM_H
