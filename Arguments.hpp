//Author:   Colby Ackerman
//Class:    Program Translations (CS4280)
//Assign:   Project 0
//Date:     September 22, 2019

#ifndef ARGUMENTS_H
#define ARGUMENTS_H

#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <sstream>

#include "FileManager.hpp"

class Arguments {
private:
    std::string cliInput;
    std::vector<std::string> tokens;

    bool parseArgs(int argc, char* argv[]);
    void handleFileRedirection();
    void tokenize();
    bool readFromFile(const std::string path, FileManager* fm);

public:
    Arguments();
    bool doAll(int argc, char* argv[], FileManager* fm);
};

#endif