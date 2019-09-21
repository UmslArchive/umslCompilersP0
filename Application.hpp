//Author:   Colby Ackerman
//Class:    Program Translations (CS4280)
//Assign:   Project 0
//Date:     September 22, 2019

#ifndef APPLICATION_H
#define APPLICATION_H

#include "Arguments.hpp"
#include "BinarySearchTree.hpp"
#include "FileManager.hpp"

class Application {
public:
    Application();
    
    void run(int argc, char* argv[]);

private:
    BinarySearchTree bst;
    Arguments arguments;
    FileManager* fileManager;
};

#endif