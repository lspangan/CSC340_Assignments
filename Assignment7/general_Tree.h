/* 
 * File:   general_Tree.h
 * Author: Leanna Pangan
 *
 * 
 */

#ifndef GENERAL_TREE_H
#define	GENERAL_TREE_H

#include <cstdlib>
#include <exception>
#include <vector>

// Node class from which we will store the values in
class Node {

    public:
        // constructor
        Node() {
            children.clear();
        }
        // destructor
        ~Node() {
            for(std::vector<Node*>::iterator it = children.begin(); it < children.end(); it++) {
                if (*it) {
                    delete * it;
                }
            }
            children.clear();
        }
        
    public:
        // adds a new node to the vector of nodes
        void AddChild(Node* child) {
            children.push_back(child);
        }
        
        // returns the size of the vector of nodes
        int NumChildren() {
            return children.size();
        }
        
        // returns a node from the vector of nodes at a specific index
        Node* GetChild(int index) {
            return children[index];
        }

    public:
        // Node class contains a vector of nodes and the value type stored in those nodes is char
        char value;
        std::vector<Node*> children; 
};

// General Tree class that we will implement using the Node class to make a tree of characters
class GeneralTree {
    public:
        GeneralTree(); // constructor
        GeneralTree(const GeneralTree& other); // copy constructor
        ~GeneralTree(); // destructor
        GeneralTree& operator=(const GeneralTree& other); // operator = , functions same way as copy constructor
        Node* insert(char value, Node* parent); // inserts a new node into the tree
        void print() const; // calls printFrom()
    private:
        Node* start;
        void copyOther(const GeneralTree& other); // calls copyFrom()
        void clear(); // calls clearFrom()
        void printFrom(Node* start) const; // prints the tree using pre-order traversal
        void copyFrom(Node* start, Node* parent); // copies am existing tree into another tree using pre-order traversal
        void clearFrom(Node* start); // deletes the nodes from the tree using post-order traversal
};

// Exception class is thrown when a child node exists, but a parent node doesn't
class NoParentException : public std::exception {

    public:
        const char *what() const throw() {
            return "Parent node cannot be null if the child node is not null.";
        }
};

#endif	/* GENERAL_TREE_H */

