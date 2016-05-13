#include "Ram.hpp"

Ram::Ram()
{

}

void Ram::parseData(std::string rawdata){

    char q[20];
    char w[20];
    char e[20];
    char r[20];
    char t[20];
    char y[20];
    char u[20];
    char i[20];
    char o[20];

    this-> rawdata = rawdata;
    std::cout << rawdata << std::endl;

    sscanf(rawdata.c_str(),"%s %s %s\n%s %s %s\n%s %s %s",q,w,e,r,t,y,u,i,o);

    raminfo[0] = atoi(w);
    raminfo[1] = atoi(t);
    raminfo[2] = atoi(i);

    std::cout << raminfo[0];

}
