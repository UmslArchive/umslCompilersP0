//Author:   Colby Ackerman
//Class:    Program Translations (CS4280)
//Assign:   Project 0
//Date:     September 22, 2019

#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <vector>
#include <set>

#include "Arguments.hpp"

struct Node {
    Node();
    Node(int _key, std::string datum, Node* _left, Node* _right, Node* _parent);

    const int key;
    std::set<std::string> data;
    Node* left;
    Node* right;
    Node* parent;
};

class BinarySearchTree {
private:
    Node* root;

    int outputState;
    std::string outFileName;

public:
    BinarySearchTree();
    BinarySearchTree(int outputState, std::string fileName);
    ~BinarySearchTree();

    void buildTree(const std::vector<std::string>& data);
    Node* insert(Node* node, const int key, std::string datum);
    void remove(const int key);
    Node* search(const int key);
    int successor(const int key);
    int predecessor(const int key);
    void printInorder(Node* node, int level = 0);
    void printPreorder(Node* node, int level = 0);
    void printPostOrder(Node* node, int level = 0);
    int stringToKey(std::string str);

    Node* getRoot() const { return root; }
};

#endif