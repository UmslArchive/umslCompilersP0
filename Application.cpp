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

    //Remove already existing files.
    remove("tree.inorder");
    remove("tree.preorder");
    remove("tree.postorder");
    std::string file = arguments.getInfileName() + ".inorder";
    remove(file.c_str());
    file = arguments.getInfileName() + ".preorder";
    remove(file.c_str());
    file = arguments.getInfileName() + ".postorder";
    remove(file.c_str());

    //Build the tree.
    bst = new BinarySearchTree(arguments.getState(), arguments.getInfileName());
    bst->buildTree(arguments.getTokens());

    //Output.
    std::cout << "Preorder:\n";
    bst->printPreorder(bst->getRoot());

    std::cout << "\nInorder:\n";
    bst->printInorder(bst->getRoot());

    std::cout << "\nPostorder:\n";
    bst->printPostOrder(bst->getRoot());

    return;
}