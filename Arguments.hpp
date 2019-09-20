//Author:   Colby Ackerman
//Class:    Program Translations (CS4280)
//Assign:   Project 0
//Date:     September 22, 2019

#ifndef ARGUMENTS_H
#define ARGUMENTS_H

#include <iostream>
#include <string>

class Arguments {
private:

public:    
    void parseArgs(int argc, char* argv[]);

    void handleFileRedirection();
};


#endif