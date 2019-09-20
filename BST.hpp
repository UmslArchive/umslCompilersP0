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

class BST {
private:
    Node* root;

public:
    BST();
    BST(std::string file);
    ~BST();

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