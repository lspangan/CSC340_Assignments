/* 
 * File:   generalTree.cpp
 * Author: Leanna Pangan
 *
 * In this assignment, you are going to implement GeneralTree, 
 * a class similar to the tree class I implemented in class but with the following differences:
 *      The value of each node is a character, not an integer.
 *      Each node can have any number of children.
 *      Inserting a node requires specifying the parent node under which it is inserted.
 *      There is no find() method.
 * 
 */

#include <cstdlib>
#include "general_Tree.h"
#include <iostream>


using namespace std;


// A default constructor. This should explicitly set
// the start node to be NULL.
GeneralTree::GeneralTree() : start(NULL) {}

// A copy constructor. This should also explicitly
// set the start node to be NULL, and then it should
// copy the contents of other into the current tree.
GeneralTree::GeneralTree(const GeneralTree& other) {
    start = NULL;
    copyOther(other);
}

// A destructor. This should traverse the tree, freeing
// all nodes. Remember to free children before you
// free parents!
GeneralTree::~GeneralTree() {
    clear();
}

// An assignment operator. This should behave like the
// example I gave in class. If other is not the same
// as the current tree, remove everything from the current
// tree and copy the contents of other into the current
// tree.
GeneralTree& GeneralTree::operator =(const GeneralTree& other) {
    if (this != &other) {
        clear();
        copyOther(other);
    }

    return *this;
}

// An insert method. This method is tricky. If the parent
// given is NULL and the start node of the current tree
// is not NULL, you should throw an exception called
// NoParentException that you define in the header
// file. MAKE SURE THAT NO MEMORY GETS LEAKED HERE!
// If you created a node already and you’re about to
// throw an exception, delete the node first!
// 
// If the parent given is NULL and the start node
// of the current tree is also NULL, this is fine. You 
// should just create a new node with the given value
// and make it the start node.
// 
// If the parent given is not NULL, make a new node with 
// the given value and add it to the parent node’s children.
// Return the node you just inserted.
Node* GeneralTree::insert(char value, Node* parent) {

    if (parent == NULL && start != NULL) {
        throw NoParentException();
    }

    // Create new node to insert
    Node* node_to_insert = new Node();
    node_to_insert->value = value;

    if (parent == NULL && start == NULL) {
        start = node_to_insert;
    }

    if (parent != NULL && start != NULL) {

        parent->AddChild(node_to_insert);
    }

    return node_to_insert;
}

// A method to print the tree. You should print it using the
// following syntax: for non-leaf nodes (nodes that have 
// more than zero children), print an open parenthesis, then
// the node’s children, then a close parenthesis. For leaf
// nodes (nodes with zero children), just print the node’s
// character value. This should appear all on one line,
// with a newline at the end.
//
// If a tree looks like this:
//
//           .
//          / \
//         /   \
//        "c"   .
//             /|\
//            / | \
//           /  |  \
//          /   |   \
//         "x" "y"  "z"
//
// then it will be printed like this:
//
// (c(xyz))
//
// Notice that the character values of non-leaf nodes
// are ignored, so the periods never get printed.
void GeneralTree::print() const {
    printFrom(start);
    cout << "\n";
}

// Basically the same as in my example. Just make a call to
// copyFrom (see below - copyFrom looks different!).
void GeneralTree::copyOther(const GeneralTree& other) {
    copyFrom(other.start, start);
}

// Also same as the example. Make a call to clearFrom
// (again, see below).
void GeneralTree::clear() {
    clearFrom(start);
}

// Recursively print a subtree whose root is the given start node.
// Use the notation described above for print().
// use pre-order traversal
void GeneralTree::printFrom(Node* start) const {
    if (start == NULL) {
        return;
    }

    cout << "(";
    for (int child = 0; child < start->NumChildren(); child++) {
        Node* cur_child = start->GetChild(child);
        if (cur_child->NumChildren() == 0) {
            cout << cur_child->value;
        } else {
            printFrom(cur_child);
        }
    }
    cout << ")";
}

// Recursively copy into the current tree from another tree.
// The starting point for the other tree is start. The parent
// argument is the argument to be passed to a call to insert().
//
// Just to clarify:
//   - The variable “start” corresponds to a node in the tree
//     you are copying FROM.
//   - The variable “parent” corresponds to a node in the
//     tree you are copying TO.
// use pre-order traversal
void GeneralTree::copyFrom(Node* start, Node* parent) {
    if (start == NULL) {
        return;
    }

    Node* cur_child = insert(start->value, parent);
    for (int child = 0; child < start->NumChildren(); child++) {
        copyFrom(start->GetChild(child), cur_child);
    }
}

// Recursively delete all nodes in the tree.
// use post-order traversal
void GeneralTree::clearFrom(Node* start) {
    if (start == NULL) {
        return;
    }

    for(vector<Node*>::iterator it = start->children.begin(); it < start->children.end(); it++) {
        if (*it) {
            delete * it;
        }
    }
    start->children.clear();
}
