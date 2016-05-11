#include "Cpu.hpp"

Cpu::Cpu(char * rawdata)
{
    parseData((std::string)rawdata);
}

void Cpu::parseData(std::string rawdata){
    const std::string lf = "\n";
    const std::string space = " ";
    std::vector <std::string> tabinfo;
    std::vector <std::string> treatedinfo;
    std::string::size_type l2 = rawdata.find(lf);

    int i = 0;
    while (l2 != std::string::npos){
        tabinfo.push_back(rawdata.substr(0,l2));
        std::cout << tabinfo[i] << std::endl;
        rawdata = rawdata.substr(l2 + 1);
        l2 = rawdata.find(lf);

        int j = 0;
        std::string::size_type l1 = tabinfo[i].find(space);
        while(l1 != std::string::npos){
            treatedinfo.push_back(tabinfo[i].substr(0,l1));


            tabinfo[i] = tabinfo[i].substr(l1 + 1);
            l1 = tabinfo[i].find(space);
            j++;
        }
        i++;
    }
    //cputab.empty()
}
