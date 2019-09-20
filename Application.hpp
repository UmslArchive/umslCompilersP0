#ifndef APPLICATION_H
#define APPLICATION_H

#include "Options.hpp"
#include "BinarySearchTree.hpp"
#include "FileManager.hpp"

class Application {
public:
    void run();

private:
    Options options;
    BinarySearchTree bst;
    
};

#endif