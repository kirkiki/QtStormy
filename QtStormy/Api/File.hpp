//
// Created by hexa on 5/9/16.
//

#ifndef IOTOBSERVER_FILE_H
#define IOTOBSERVER_FILE_H

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>

class File {
public:
    File(std::string name);
    std::vector <std::string> content;
    void getContent();
    void debugContent();

private:
    std::string fname;
};


#endif //IOTOBSERVER_FILE_H
