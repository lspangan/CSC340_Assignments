/* 
 * File:   shortestPath_main.cpp
 * Author: Leanna Pangan
 * ID:     913074778
 * Email:  lspangan@mail.sfsu.edu
 *
 */
#include <cstdlib>
#include "graphs.h"

using namespace std;


int main() {
	Graphs<string> g;
	Node<string>* a = g.insert("a");
	Node<string>* b = g.insert("b");
	Node<string>* c = g.insert("c");
	Node<string>* d = g.insert("d");
	Node<string>* e = g.insert("e");
	g.connect(a, b);
	g.connect(c, d);
	g.connect(b, e);
	g.connect(c, e);
	cout << "Graph 1" << endl;
	g.print();
	cout << "-----" << endl;

	vector<Node<string>*> path = g.shortestPath("a", "e");
	cout << "Graph 1: path from a to e: ";
	for (int i = 0; i < path.size(); i++) {
		cout << path[i]->value << " ";
	}
	cout << endl;
	cout << "----" << endl;

	Graphs<string> g2(g);
	g2.connect("a", "e");
	cout << "Graph 1 again" << endl;
	g.print();
	cout << "-----" << endl;
	cout << "Graph 2" << endl;
	g2.print();
	cout << "-----" << endl;

	path = g.shortestPath("a", "e");
	cout << "Graph 1: path from a to e: ";
	for (int i = 0; i < path.size(); i++) {
		cout << path[i]->value << " ";
	}
	cout << endl;
	cout << "----" << endl;

	path = g2.shortestPath("a", "e");
	cout << "Graph 2: path from a to e: ";
	for (int i = 0; i < path.size(); i++) {
		cout << path[i]->value << " ";
	}
	cout << endl;
	cout << "----" << endl;

	Graphs<string> g3;
	g3.insert("z");         // this should get overwritten
	g3.insert("y");         // and this
	g3.connect("y", "z");   // also this
	g3 = g;
	g3.connect("a", "e");
	cout << "Graph 1 a third time" << endl;
	g.print();
	cout << "-----" << endl;
	cout << "Graph 3" << endl;
	g3.print();
	cout << "-----" << endl;

	path = g.shortestPath("a", "e");
	cout << "Graph 1: path from a to e: ";
	for (int i = 0; i < path.size(); i++) {
		cout << path[i]->value << " ";
	}
	cout << endl;
	cout << "----" << endl;

	path = g3.shortestPath("a", "e");
	cout << "Graph 3: path from a to e: ";
	for (int i = 0; i < path.size(); i++) {
		cout << path[i]->value << " ";
	}
	cout << endl;
	cout << "----" << endl;
        
        // Tests the shortest path of a complex graph
        Graphs<string> g4;
	Node<string>* l = g4.insert("l");
	Node<string>* m = g4.insert("m");
	Node<string>* n = g4.insert("n");
	Node<string>* o = g4.insert("o");
	Node<string>* p = g4.insert("p");
	Node<string>* q = g4.insert("q");
	Node<string>* r = g4.insert("r");
	Node<string>* s = g4.insert("s");
	Node<string>* t = g4.insert("t");
	Node<string>* u = g4.insert("u");        
	g4.connect(l, m);
	g4.connect(n, o);
        g4.connect(m, p);
	g4.connect(n, p);
        g4.connect(p, r);
	g4.connect(m, o);     
	g4.connect(r, s);
	g4.connect(m, t);
        g4.connect(q, u);
	g4.connect(o, s);
        g4.connect(t, u);
	g4.connect(s, u);        
	cout << "Graph 4" << endl;
	g4.print();
	cout << "-----" << endl;

	vector<Node<string>*> path2 = g4.shortestPath("l", "u");
	cout << "Graph 4: path from l to u: ";
	for (int i = 0; i < path2.size(); i++) {
		cout << path2[i]->value << " ";
	}
	cout << endl;
	cout << "----" << endl;
        
        // Throws NonExistentNodeException()
        try {
            cout << "Testing NonExistentNodeException() - there shouldn't be an end node x" << endl;        
            Graphs<string> g5;
            Node<string>* a = g5.insert("a");
            Node<string>* b = g5.insert("b");
            Node<string>* c = g5.insert("c");
            Node<string>* d = g5.insert("d");
            Node<string>* e = g5.insert("e");
            g5.connect(a, b);
            g5.connect(c, d);
            g5.connect(b, e);
            g5.connect(c, a);
            cout << "Graph 5" << endl;
            g5.print();
            cout << "-----" << endl;
            cout << "Graph 5: path from a to x: " << endl;
            vector<Node<string>*> path = g4.shortestPath("a", "x");
            cout << "Graph 5: path from a to e: ";
            for (int i = 0; i < path.size(); i++) {
		cout << path[i]->value << " ";
            }
            cout << endl;
            cout << "----" << endl;            
        } catch (NonExistentNodeException &e) {
            cout << "Error occurred" << endl;
            cout << e.what() << endl; 
            cout << "----" << endl;
        }
        
        // Throws NoPathException()
        try {
            cout << "Testing NoPathException() - there shouldn't be a path to e" << endl;        
            Graphs<string> g6;
            Node<string>* a = g6.insert("a");
            Node<string>* b = g6.insert("b");
            Node<string>* c = g6.insert("c");
            Node<string>* d = g6.insert("d");
            Node<string>* e = g6.insert("e");
            g6.connect(a, b);
            g6.connect(c, d);
            g6.connect(b, c);
            g6.connect(c, a);
            cout << "Graph 6" << endl;
            g6.print();
            cout << "-----" << endl;
            cout << "Graph 6: path from a to e: " << endl;
            vector<Node<string>*> path = g6.shortestPath("a", "e");
            for (int i = 0; i < path.size(); i++) {
		cout << path[i]->value << " ";
            }
            cout << endl;
            cout << "----" << endl;
        } catch (NoPathException &e) {
            cout << "Error occurred" << endl;
            cout << e.what() << endl;
        }

    return 0;
}

