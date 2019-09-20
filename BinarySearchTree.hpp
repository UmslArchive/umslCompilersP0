//Author:   Colby Ackerman
//Class:    Program Translations (CS4280)
//Assign:   Project 0
//Date:     September 22, 2019

#ifndef TREE_H
#define TREE_H

#include <string>
#include <memory>

struct Node {
    Node();
    Node(int _key, Node* _left, Node* _right, Node* _parent);

    const int key;
    Node* left;
    Node* right;
    Node* parent;
};

class BinarySearchTree {
private:
    Node* root;

public:
    BinarySearchTree();
    BinarySearchTree(std::string file);
    ~BinarySearchTree();

    void insert(const int key);
    void remove(const int key);
    Node* search(const int key);
    int successor(const int key);
    int predecessor(const int key);
    void printInorder();
    void printPreorder();
    void printPostOrder();
};

#endif