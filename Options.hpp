//Author:   Colby Ackerman
//Class:    Program Translations (CS4280)
//Assign:   Project 0
//Date:     September 22, 2019

#ifndef OPTIONS_H
#define OPTIONS_H

#include <iostream>
#include <string>

enum class ProgramInvokeState {
    FILE_PASS,
    FILE_REDIRECT,
    KEYBOARD
};

class Options {
private:
    ProgramInvokeState pInvokeState;

    void setInvokeState(const int argc, const char* argv[]);

public:
    
};


#endif