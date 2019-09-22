//Author:   Colby Ackerman
//Class:    Program Translations (CS4280)
//Assign:   Project 0
//Date:     September 22, 2019

#include "Application.hpp"

void Application::run(int argc, char* argv[]) {
    /*
    This code handles the possible states of cli arguments described in the P0
    spec (keyboard sim, filename as arg, and file redirection). The end result
    is a vector containing tokens parsed from a source.
    */
    if(!arguments.handleArguments(argc, argv)) {
        std::cerr << "Error: Arguments could not be handled." << std::endl;
    }

    
}