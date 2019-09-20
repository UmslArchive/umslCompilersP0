//Author:   Colby Ackerman
//Class:    Program Translations (CS4280)
//Assign:   Project 0
//Date:     September 22, 2019

#include "Arguments.hpp"

void Arguments::parseArgs(int argc, char* argv[]) {
    for(int i = 0; i < argc; ++i) {
        std::cout << argv[i] << std::endl;
    }
}

void Arguments::handleFileRedirection() {
    std::string fileString = "";
    char c = 0;

    //Read entire cin buffer.
    while(std::cin.get(c)) {
        fileString.push_back(c);
    }

    //DEBUG
    std::cout << fileString;

    //Clear the std::cin buffer.
    std::cin.ignore(std::numeric_limits<std::streamsize>::max());

    return;
}