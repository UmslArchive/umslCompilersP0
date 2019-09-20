#include "BST.hpp"

//Node constructors.
Node::Node() : 
    key(0), left(nullptr), right(nullptr), parent(nullptr) 
{}

Node::Node(int _key, Node* _left, Node* _right, Node* _parent) :
    key(_key), left(_left), right(_right), parent(_parent)
{}

//BST constructors.
BST::BST() : 
    root(nullptr)  
{}

BST::BST(std::string file) {

}

//Destructor
BST::~BST() {

}

void BST::insert(const int key) {
    
}

void BST::remove(const int key) {

}

Node* BST::search(const int key) {
    return nullptr;
}

int BST::successor(const int key) {
    return 0;
}

int BST::predecessor(const int key) {
    return 0;
}

void BST::printInorder() {

}

void BST::printPreorder() {
    
}

void BST::printPostOrder() {

}
