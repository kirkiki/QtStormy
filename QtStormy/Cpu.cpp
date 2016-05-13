#include "Cpu.hpp"

Cpu::Cpu()
{

}

void Cpu::calculPercentage(){
    data[0].erase(data[0].begin());

    if (lastData.empty()){
        std::cout << "[!] No previous Data !" << std::endl;
        lastData = data;
        data.clear();
    }

    else {
        int i = 0;
        for (i;i < data.size() -1;i++){
           long d1 = data[i][0] - lastData[i][0];
           long d2 = data[i][1] - lastData[i][1];
           long d3 = data[i][2] - lastData[i][2];
           long d4 = data[i][3] - lastData[i][3];

           /*std::cout << d1 << "  "<<data[i][0] << "  "<< lastData[i][0] << std::endl;
           std::cout << d2 << "  "<<data[i][1] << "  "<< lastData[i][1]<< std::endl;
           std::cout << d3 << "  "<<data[i][2] <<"  " << lastData[i][2]<< std::endl;
           std::cout << d4 <<"  "<<data[i][3] << "  " << lastData[i][3]<< std::endl;
           */

           double res = (double)((d1+d2+d3) * 100L) / (double)(d1+d2+d3+d4);
           actualprc.push_back(res); // A modifier !
           std::cout << "CPU[" << i << "]="<< res << std::endl;
       }
        t = data[i][data.size()-1];
        lastData = data;
        data.clear();
    }
}

void Cpu::parseData(std::string rawdata){
    const std::string lf = "\n";
    const std::string space = " ";
    std::vector <std::string> tabinfo;
    std::vector <long> treatedinfo;
    std::string::size_type l2 = rawdata.find(lf);

    int i = 0;
    while (l2 != std::string::npos){
        tabinfo.push_back(rawdata.substr(0,l2));
        rawdata = rawdata.substr(l2 + 1);
        l2 = rawdata.find(lf);

        std::string::size_type l1 = tabinfo[i].find(space);

        int j = 0;
        while(l1 != std::string::npos){
            treatedinfo.push_back(atoi((tabinfo[i].substr(0,l1)).c_str()));
            tabinfo[i] = tabinfo[i].substr(l1 + 1);
            l1 = tabinfo[i].find(space);
            j++;
        }

        if (l1 = std::string::npos){
            treatedinfo.push_back(atoi((tabinfo[i].substr(0,l1)).c_str()));
        }

        data.push_back(treatedinfo);
        if (data[i][0] == 0) data[i].erase(data[i].begin());

        treatedinfo.clear();
        i++;
    }    
    tabinfo.clear();
}
