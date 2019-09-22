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

BinarySearchTree::BinarySearchTree(int _outputState, std::string fileName) :
    outputState(_outputState), outFileName(fileName), root(NULL) 
{
    //DEBUG
    //std::cout << "STATE: " << outputState << std::endl;
    std::cout << "outFileName: " << outFileName << std::endl;
}

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

void BinarySearchTree::printInorder(Node* node, int level) {
    if(root == NULL) {
        std::cerr << "Cannot print empty tree." << std::endl;
        return;
    }

    if(node != NULL) {

        //Set indent.
        std::string indent = "";
        for(int i = 0; i < level; ++i) {
            indent.append("    ");
        }

        printInorder(node->left, level + 1);

        //Write to file.
        std::fstream outFile;
        std::string filename;
        if(outputState == 1) {
            filename = outFileName + ".inorder";
        }
        else {
            filename = "tree.inorder";
        }
        outFile.open(filename.c_str(), std::ios_base::out | std::ios_base::app);
        for(int i = 0; i < node->data.size(); ++i) {
            //std::cout << indent << "Key " << node->key << ": " << node->data.at(i) << std::endl;
            outFile << indent << "Key " << node->key << ": " << node->data.at(i) << std::endl;
        }
        outFile.close();

        printInorder(node->right, level + 1);
    }
}

void BinarySearchTree::printPreorder(Node* node, int level) {
    if(root == NULL) {
        std::cerr << "Cannot print empty tree." << std::endl;
        return;
    }

    //Set indent.
    if(node != NULL) {
        std::string indent = "";
        for(int i = 0; i < level; ++i) {
            indent.append("    ");
        }
        
        //Write to file.
        std::fstream outFile;
        std::string filename;
        if(outputState == 1) {
            filename = outFileName + ".preorder";
        }
        else {
            filename = "tree.preorder";
        }
        outFile.open(filename.c_str(), std::ios_base::out | std::ios_base::app);
        for(int i = 0; i < node->data.size(); ++i) {
            //std::cout << indent << "Key " << node->key << ": " << node->data.at(i) << std::endl;
            outFile << indent << "Key " << node->key << ": " << node->data.at(i) << std::endl;
        }
        outFile.close();

        printPreorder(node->left, level + 1);
        printPreorder(node->right, level + 1);
    }
}

void BinarySearchTree::printPostOrder(Node* node, int level) {
    if(root == NULL) {
        std::cerr << "Cannot print empty tree." << std::endl;
        return;
    }

    //Set indent.
    if(node != NULL) {
        std::string indent = "";
        for(int i = 0; i < level; ++i) {
            indent.append("    ");
        }

        printPostOrder(node->left, level + 1);
        printPostOrder(node->right, level + 1);

        //Write to file.
        std::fstream outFile;
        std::string filename;
        if(outputState == 1) {
            filename = outFileName + ".postorder";
        }
        else {
            filename = "tree.postorder";
        }
        outFile.open(filename.c_str(), std::ios_base::out | std::ios_base::app);
        for(int i = 0; i < node->data.size(); ++i) {
            //std::cout << indent << "Key " << node->key << ": " << node->data.at(i) << std::endl;
            outFile << indent << "Key " << node->key << ": " << node->data.at(i) << std::endl;
        }
        outFile.close();
    }
}

int BinarySearchTree::stringToKey(std::string str) {
    if(!str.empty())
        return (int) str.at(0);
    else
        return -1;
}