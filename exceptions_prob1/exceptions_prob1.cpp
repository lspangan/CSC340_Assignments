/* 
 * File:   exceptions_prob1.cpp
 * Author: Leanna Pangan
 * ID:     913074778
 * Email:  lspangan@mail.sfsu.edu
 *
 * Q1. The following code uses two arrays, one to store products and the other to store product ID's 
 * (a better organization would be to use a singe array of a class or struct, but that is not the subject of this Programming Project). 
 * The function getProductID takes as input the two arrays, the length of the arrays, and a target product to search for. 
 * It then loops through the product name array and if a match is found it returns the corresponding product ID:
 * 
 * 
 * One problem with this implementation of the getProductID() function is that it returns the special error code of -1 if the target name is not found.  
 * The caller later might actually want to have -1 as a valid product ID number. 
 * Revise the program so that it throws an appropriate exception when a product is not found instead of returning -1.  
 * Please define an exception class Exception_ID_Not_Found as a derived  class of the standard exception class exception. 
 * (See the example code on iLearn for exception subclassing.) 
 * Then modify the getProductID() function to throw Exception_ID_Not_Found instead of returning -1. 
 * Finally, test this type of exceptions properly in the main() function using a try-catch statement.

You are not required to use separate compilation for this problem.
 */

#include <cstdlib>
#include <iostream>
#include "exceptionsprob1.h"

using namespace std;

// exception class used in getProductID()
// prints error message if product is not found in the array
/*const char* Exception_ID_Not_Found::what() const throw() {
    return "Product name is not found in the array.";
}*/

// uses two arrays, one to store products and the other to store product ID's
// loops through the product name array and if a match is found it returns the corresponding product ID
// if there is no match, then  it throws an exception
int getProductID(int ids[], string names[], int numProducts, string target) {
    for (int i=0; i < numProducts; i++) {
        if (names[i] == target) {
            return ids[i];
        }
    }  
    throw Exception_ID_Not_Found();
}

 
// Sample code to test the getProductID function
int main() {
    int productIds[]= {4, 5, 8, 10, 13};
    string products[] = { "computer", "flash drive", "mouse", "printer", "camera" };   
    
    // prints "mouse" and its product id
    try {
        cout << "Product:\t" << "Product ID: " << endl << "mouse\t\t\t";
        cout << getProductID(productIds, products, 5, "mouse") << endl;
    } catch (Exception_ID_Not_Found &e) {
        cout << "Error has occurred. " << e.what() << endl;   
    }
    
    // prints camera and its product id
    try {
        cout << "Product:\t" << "Product ID: " << endl << "camera\t\t\t";
        cout << getProductID(productIds, products, 5, "camera") << endl; 
    } catch (Exception_ID_Not_Found &e) {
        cout << "Error has occurred. " << e.what() << endl;   
    }
    
    // prints "laptop"
    // laptop does not exist in array, so it prints the error message from exception class
    try {
        cout << "Product:\t" << "Product ID: " << endl << "laptop\t\t\t";
        cout << getProductID(productIds, products, 5, "laptop") << endl;
    } catch (Exception_ID_Not_Found &e) {
        cout << "Error has occurred. " << e.what() << endl;    
    }

return 0;
}