/* 
 * File:   generalTree_main.cpp
 * Author: Leanna Pangan
 *
 * 
 */

#include <cstdlib>
#include <iostream>
#include <sstream>
#include "general_Tree.h"

using namespace std;


void parseRecursive(stringstream& ss, GeneralTree& gt, Node* parent)
{
    char nextChar;
    while (true) {
        ss >> nextChar;
        if (ss.fail())
            return;

        if (nextChar == ')')
            return;

        if (nextChar == '(') {
            Node* newNode = gt.insert(' ', parent);
            parseRecursive(ss, gt, newNode);
        } else {
            gt.insert(nextChar, parent);
        }
    }
}

void parseExpression(const string& expr, GeneralTree& gt)
{
    stringstream ss;
    ss << expr;

    parseRecursive(ss, gt, NULL);
}

int main()
{
    // This should print:
    // (c(ab))
    GeneralTree gt;
    Node* grandparent = gt.insert('.', NULL);
    Node* parent1 = gt.insert('c', grandparent);
    Node* parent2 = gt.insert('.', grandparent);
    Node* kid1 = gt.insert('a', parent2);
    Node* kid2 = gt.insert('b', parent2);
    gt.print();

    // This should print:
    // (abab(cd)d(ef(g(h))))
    GeneralTree gt2;
    parseExpression("(abab(cd)d(ef(g(h))))", gt2);
    gt2.print();

    // This should print:
    // (c(ab))
    GeneralTree gt3 = gt;
    gt3.print();

    // This should print:
    // (abab(cd)d(ef(g(h))))
    GeneralTree gt4(gt2);
    gt4.print();
    
    // throws NoParentException()
    try {
        GeneralTree gt8;
        Node* grandparent = gt8.insert('.', NULL);
        Node* parent1 = gt8.insert('.', grandparent);
        Node* parent2 = gt8.insert('.', grandparent);
        Node* kid1 = gt8.insert('a', NULL);
        Node* kid2 = gt8.insert('b', NULL);
        gt8.print();
    } catch (NoParentException &e) {
        cout << "Error has occurred. " << e.what() << endl;
    }
    
    // This should print the values of gt5, gt6
    // then deletes the values in those trees
    GeneralTree gt5, gt6;
    Node* grandparent5 = gt5.insert('.', NULL);
    Node* parent3 = gt5.insert('.', grandparent5);
    Node* kid3 = gt5.insert('a', parent3);
    parseExpression("(ababb(cb(a)))", gt6);
    for (int i = 0; i < 2; i++){ 
        gt5.print();
        gt6.print();
        gt5.~GeneralTree();
        gt6.~GeneralTree();
    }
    return 0;
}