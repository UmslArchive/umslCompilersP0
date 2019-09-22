//Author:   Colby Ackerman
//Class:    Program Translations (CS4280)
//Assign:   Project 0
//Date:     September 22, 2019

#include "BinarySearchTree.hpp"

//Node constructors.
Node::Node() : key(0), left(NULL), right(NULL), parent(NULL) {}

Node::Node(int _key, std::string datum, Node* _left, Node* _right, Node* _parent) :
    key(_key), left(_left), right(_right), parent(_parent)
{    
    data.push_back(datum);
}

//BinarySearchTree constructor.
BinarySearchTree::BinarySearchTree() : root(NULL) {}

//Destructor
BinarySearchTree::~BinarySearchTree() {

}

void BinarySearchTree::buildTree(const std::vector<std::string>& data) {
    for(int i = 0; i < data.size(); ++i) {
        insert(root, stringToKey(data[i]), data[i]);
    }
}

Node* BinarySearchTree::insert(Node* node, const int key, std::string datum) {
    //Create node if doesn't exist.
    if(node == NULL) {
        node = new Node(key, datum, NULL, NULL, NULL);
        
        if(root == NULL) {
            root = node;
        }

        return node;
    }

    //Check for matching key.
    else if(key == node->key) {
        node->data.push_back(datum);
    }

    //Check left.
    else if(key < node->key) {
        node->left = insert(node->left, key, datum);
    }

    //Check right.
    else if(key > node->key) {
        node->right = insert(node->right, key, datum);
    }

    return node;
}

void BinarySearchTree::remove(const int key) {

}

Node* BinarySearchTree::search(const int key) {
    return NULL;
}

int BinarySearchTree::successor(const int key) {
    return 0;
}

int BinarySearchTree::predecessor(const int key) {
    return 0;
}

void BinarySearchTree::printInorder(Node* node) {
    if(root == NULL) {
        std::cerr << "Cannot print empty tree." << std::endl;
        return;
    }

    if(node != NULL) {
        printInorder(node->left);
        for(int i = 0; i < node->data.size(); ++i) {
            std::cout << "Key " << node->key << ": " << node->data.at(i) << std::endl;
        }
        printInorder(node->right);
    }
}

void BinarySearchTree::printPreorder(Node* node) {
    if(root == NULL) {
        std::cerr << "Cannot print empty tree." << std::endl;
        return;
    }

    if(node != NULL) {
        for(int i = 0; i < node->data.size(); ++i) {
            std::cout << "Key " << node->key << ": " << node->data.at(i) << std::endl;
        }
        printPreorder(node->left);
        printPreorder(node->right);
    }
}

void BinarySearchTree::printPostOrder(Node* node) {
    if(root == NULL) {
        std::cerr << "Cannot print empty tree." << std::endl;
        return;
    }

    if(node != NULL) {
        printPostOrder(node->left);
        printPostOrder(node->right);
        for(int i = 0; i < node->data.size(); ++i) {
            std::cout << "Key " << node->key << ": " << node->data.at(i) << std::endl;
        }
    }
}

int BinarySearchTree::stringToKey(std::string str) {
    if(!str.empty())
        return (int) str.at(0);
    else
        return -1;
}