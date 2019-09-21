//Author:   Colby Ackerman
//Class:    Program Translations (CS4280)
//Assign:   Project 0
//Date:     September 22, 2019

#ifndef APPLICATION_H
#define APPLICATION_H

#include "Arguments.hpp"
#include "BinarySearchTree.hpp"

class Application {
public:
    void run(int argc, char* argv[]);

private:
    BinarySearchTree bst;
    Arguments arguments;
};

#endif