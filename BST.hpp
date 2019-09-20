#ifndef TREE_H
#define TREE_H

#include <string>

class Node {
    public:
        int key;
        Node* left;
        Node* right;
        Node* parent;
};

class Tree {
    private:
        Node* root;

    public:
        void insert(Node* node, std::string data);
};

#endif