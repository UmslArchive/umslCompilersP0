//Author:   Colby Ackerman
//Class:    Program Translations (CS4280)
//Assign:   Project 0
//Date:     September 22, 2019

#ifndef APPLICATION_H
#define APPLICATION_H

#include "Options.hpp"
#include "BinarySearchTree.hpp"
#include "FileManager.hpp"

class Application {
public:
    void run();

private:
    void getArgs();
    Options options;
    BinarySearchTree bst;
};

#endif