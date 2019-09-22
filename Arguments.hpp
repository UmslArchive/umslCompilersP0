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
#include <fstream>

class Arguments {
private:
    std::string cliInput;
    std::string fileContents;
    std::vector<std::string> tokens;

    bool parseArgs(int argc, char* argv[]);
    void handleFileRedirOrKeyboardSim();
    void tokenize(std::string str);
    bool readFromFile(const std::string path);

public:
    Arguments();

    bool handleArguments(int argc, char* argv[]);

    const std::vector<std::string>& getTokens() const { return tokens; }
};

#endif