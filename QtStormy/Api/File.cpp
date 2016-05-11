//
// Created by hexa on 5/9/16.
//

#include "File.hpp"

FILE * f;

File::File(std::string name){

    fname = name;

}

void File::getContent(){

    f = fopen(fname.c_str(),"r");
    char buffer[100];

    if(f != NULL){
        while(fgets(buffer,100,f) != NULL){
            content.push_back(buffer);
        }
    }
    else {
        printf("[!] Can't open %s \n",fname.c_str());
    }
    rewind(f);

}

void File::debugContent(){
    for (int i = 0;i < content.size();i++){
        std::cout << content[i];
    }
}