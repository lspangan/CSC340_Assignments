/* 
 * File:   assignment4.h
 * Author: Leanna Pangan
 * ID:     913074778
 * Email:  lspangan@mail.sfsu.edu
 * 
 * 
 * 
 * 
 */

#ifndef ASSIGNMENT4_H
#define	ASSIGNMENT4_H

#include <iostream>
#include <cstdlib>

using namespace std;

//creates a class called myPolynomial that declares its variables and functions to be used in .cpp file
class myPolynomial {
    // data must be private
    private:
        int maxDegree;
        int coefficients[30]; // initialized to 30, so program does not crash and does not run out of memory
    // functions will be used by the user, so they must be public
    public:
        myPolynomial(); // constructor for myPolynomial
        void create(int num); // creates a new myPolynomial
        void readFromUser(int &num); // asks for user input to create a polynomial
        int degree(); // returns the highest degree in the polynomial
        int coefficient(int exponent); // returns the coefficient that corresponds to the given degree
        void changeCoefficient(int newCoefficient, int exponent); // allows the user to change the coefficient of a term
        void multiply(int scalar, myPolynomial poly); // multiplies the polynomial by a scalar
        myPolynomial add(myPolynomial poly1, myPolynomial poly2, myPolynomial result); // adds two polynomials
        myPolynomial operator-(); // negates the polynomial
        void printPolynomial(); // displays the polynomial
};


#endif	/* ASSIGNMENT4_H */

