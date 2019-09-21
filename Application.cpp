//Author:   Colby Ackerman
//Class:    Program Translations (CS4280)
//Assign:   Project 0
//Date:     September 22, 2019

#include "Application.hpp"

Application::Application() : fileManager(NULL) {
    fileManager = new FileManager();
}

void Application::run(int argc, char* argv[]) {
    if(!arguments.doAll(argc, argv, fileManager)) {
        std::cerr << "Error: Arguments could not be handled." << std::endl;
    }

    delete fileManager;
    fileManager = NULL;
}