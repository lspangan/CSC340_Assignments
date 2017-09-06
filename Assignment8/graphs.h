/* 
 * File:   graphs.h
 * Author: Leanna Pangan
 * ID:     913074778
 * Email:  lspangan@mail.sfsu.edu
 *
 */

#ifndef _GRAPHS_H
#define _GRAPHS_H

#include <cstdlib>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <stdexcept>
#include <exception>

/*
 * Exception for trying to find
 * a path between two nodes if
 * at least one of the nodes
 * doesn't exist.
 */
class NonExistentNodeException : public std::exception {
    public:
	virtual const char* what() const throw() {
            return "At least one of those nodes doesn't exist!";
	}
};

/*
 * Exception for trying to find
 * a path between two nodes when
 * no path exists.
 */
class NoPathException : public std::exception {
    public:
	virtual const char* what() const throw() {
            return "No path exists between those two nodes!";
	}
};

/*
 * Node
 * -----
 * Represents a node in a graph. T is
 * the type of value held in the node.
 */
template <typename T>
class Node {
    public:
	Node(const T& value) : value(value) {}

	/*
	 * Why wouldn't this do what we want?
	 *
	 * Hint: what is the new node connected to?
	 */
	/*

	Node<T>* copy(const Node& other) {
		return new Node<T>(value);
	}

	*/
	
	/*
	 * Why not a vector for the list of adjacent
	 * nodes?
	 */
	std::unordered_set<Node<T>*> adjacents;
	T value;
	bool marked;
};

/*
 * Graph
 * -----
 * Represents a bi-directional (undirected)
 * graph. Nodes can have any value. The
 * graph does not have to be connected. Values
 * must be unique.
 */
template <typename T>
class Graphs {
    public:
	Graphs() {}
	
	/*
	 * Since we dynamically allocate each node,
	 * we need the big 3!
	 * 
	 * - destructor
	 * - copy constructor
	 * - assignment operator
	 */
	~Graphs() {
            clear();
        }

	Graphs(const Graphs<T>& other) {
            copyOther(other);
        }

        Graphs<T>& operator=(const Graphs<T>& other) {
            if (this != &other) {
                clear();
                copyOther(other);
            }
            return *this;
        }

	/*
	 * Common graph operations.
	 */
	Node<T>* insert(const T& value) {
            if (nodes.find(value) != nodes.end()) {
                return NULL;
            }
            Node<T>* newNode = new Node<T>(value);
            nodes[value] = newNode;
            return newNode;
        }

	// Two versions of connect! One that takes
	// node pointers, another that takes node
	// values.
	void connect(Node<T>* first, Node<T>* second) {
            first->adjacents.insert(second);
            second->adjacents.insert(first);
        }

	void connect(const T& first, const T& second) {
            if (nodes.find(first) == nodes.end() ||
                nodes.find(second) == nodes.end()) {
                throw NonExistentNodeException();
            }
            connect(nodes[first], nodes[second]);
        }

	void unmarkAll() {
            for (auto iter = nodes.begin();
                iter != nodes.end();
                iter++) {
                    iter->second->marked = false;
            }
        }

	void print() {
            for (auto iter = nodes.begin();
                iter != nodes.end();
                iter++) {
                    std::cout << iter->first << ": ";

                    for (auto neighborsIter = iter->second->adjacents.begin();
                        neighborsIter != iter->second->adjacents.end();
                        neighborsIter++) {

                            std::cout << (*neighborsIter)->value << " ";
                    }
                    std::cout << std::endl;
            }
        }

	std::vector<Node<T>*> shortestPath(const T& start, const T& end) {
            // Make sure both nodes exist! If one doesn't, throw
            // the appropriate exception.
            if (nodes.find(start) == nodes.end() || nodes.find(end) == nodes.end()) {
                 throw NonExistentNodeException();
            }
            // Ok, both nodes exist. Get the node pointers from
            // your unordered_map!
                
            // You will need some way to store partial paths.
            // I highly recommend representing a partial
            // path as a vector of node pointers, since this
            // is what you will ultimately be returning.
            std::vector<Node<T>*> partialPath;
                        
            // I would ALSO recommend using a deque to store
            // all your partial paths. (A deque is
            // shorthand for double-ended queue. It's part
            // of the STL.
            //
            // If you choose to use a deque (which you should),
            // you'll have a deque of vectors, where each vector
            // in turn contains node pointers. Kind of
            // complicated! But effective!
            std::deque<std::vector<Node<T>*> > myDeque;           
                        

            // Don't forget to unmark your nodes!
            unmarkAll();

            // Your first partial path will just contain one
            // node - the start node. Not much of a path, but
            // you have to start somewhere!
            Node<T>* startNode = nodes[start]; // node pointer that points to start value
            Node<T>* endNode = nodes[end]; // node pointer that points to end value
            partialPath.push_back(startNode);
            
            // startNode is now marked, so it is true
            startNode->marked = true;
            
            // store partial path into deque
            myDeque.push_back(partialPath); 
                
            // Now, repeatedly do the following:               
            //    1. Get the topmost partial path.
            while (!myDeque.empty()) {
                partialPath = myDeque.front();
                myDeque.pop_front();
                startNode = partialPath.back();
                //    2. Look at every node you can get to from
                //       the end of that partial path (ignoring
                //       nodes you've already seen).
                for (auto neighborsIter = startNode->adjacents.begin();
                    neighborsIter != startNode->adjacents.end();
                    neighborsIter++) {              
                        //    3. Create a partial path that has the same
                        //       nodes as the current partial path, PLUS
                        //       one more node (the node that you're
                        //       looking at).
                        // TODO: if node is unmarked, then create a partial path
                        //       set path equal to current partial path
                        //       push back the unmarked node in the partial path
                        if ((*neighborsIter)->marked == false) {  
                            (*neighborsIter)->marked = true; // mark unmarked nodes as true
                            std::vector<Node<T>*> nextPath(partialPath);                                    
                            nextPath.push_back(*neighborsIter);                                                           
                            // You stop when:
                            //    - You see the end node in step 2. Put the
                            //      end node at the end of the current partial
                            //      path, and then return the partial (now
                            //      complete) path!
                            if ((*neighborsIter) == endNode) {
                                return nextPath; // this is the complete path
                            }
                            //    4. Store those partial paths at the end.
                            // TODO: push back partial paths at the end of myDeque
                            myDeque.push_back(nextPath);                               
                        }
                }                  
            }     
            
            //    - You run out of partial paths to look at.
            //      If this ever happens, that means there is
            //      no path to the end node. Throw the 
            //      appropriate exception.            
            throw NoPathException();
        }

    private:
	std::unordered_map<T, Node<T>*> nodes;  // for uniqueness and lookup

	void copyOther(const Graphs<T>& other) {
            for (auto iter = other.nodes.begin();
                iter != other.nodes.end();
                iter++) {
                    insert(iter->first);
            }
            for (auto iter = other.nodes.begin();
                iter != other.nodes.end();
                iter++) {
                    auto adjacents = iter->second->adjacents;
                    for (auto neighborsIter = adjacents.begin();
                        neighborsIter != adjacents.end();
                        ++neighborsIter) {
                    // Need to connect the values here!
                    // Connecting iter->second and *neighborsIter
                    // would re-connect the nodes in the old graph
                    // (so this would do nothing)
                            connect(iter->first, (*neighborsIter)->value);
                    }
            }
        }

        void clear() {
            for (auto iter = nodes.begin();
                iter != nodes.end();
                iter++) {
                    delete iter->second;
            }

            nodes.clear();
        }
};



#endif	/* GRAPHS_H */

