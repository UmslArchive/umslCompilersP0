#include "BinarySearchTree.hpp"

//Node constructors.
Node::Node() : 
    key(0), left(nullptr), right(nullptr), parent(nullptr) 
{}

Node::Node(int _key, Node* _left, Node* _right, Node* _parent) :
    key(_key), left(_left), right(_right), parent(_parent)
{}

//BinarySearchTree constructors.
BinarySearchTree::BinarySearchTree() : 
    root(nullptr)  
{}

BinarySearchTree::BinarySearchTree(std::string file) {

}

//Destructor
BinarySearchTree::~BinarySearchTree() {

}

void BinarySearchTree::insert(const int key) {
    
}

void BinarySearchTree::remove(const int key) {

}

Node* BinarySearchTree::search(const int key) {
    return nullptr;
}

int BinarySearchTree::successor(const int key) {
    return 0;
}

int BinarySearchTree::predecessor(const int key) {
    return 0;
}

void BinarySearchTree::printInorder() {

}

void BinarySearchTree::printPreorder() {
    
}

void BinarySearchTree::printPostOrder() {

}
