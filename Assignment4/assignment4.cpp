/* 
 * File:   assignment4.cpp
 * Author: Leanna Pangan
 * ID:     913074778
 * Email:  lspangan@mail.sfsu.edu
 * 
 * Use separate compilation to implement a polynomial ADT that manipulates polynomials in a single variable x (e.g., p = 4 x5 + 7 x 3 – x2 + 9 ). 
 * For this problem, consider only polynomials whose exponents are nonnegative integers. 
 * You are required to identify a proper data representation schema to store such polynomials and hide such data from external users of this ADT. 
 * Additionally, your ADT will at least include the following member functions:
 *      One default constructor, which creates a polynomial with no terms.
 *      One method allowing one to get an entire polynomial by interacting with the user (by writing to cout and reading from cin) to obtain the degree and coefficient of each term in a polynomial. 
 *          If the user enters nonsense, your program should not crash! 
 *          It is up to you how to handle this case. 
 *      The method can look something like this when called:
 *      myPolynomial.readFromUser();    // prompts the user for the degree and coefficients and stores the results in myPolynomial
 *      degree() // Returns the degree of a polynomial, which is the highest power of a term with a nonzero coefficient. E.g.: int deg = myPolynomial.degree();
 *      coefficient(power) // Returns the coefficient of the x p o w e r term.
 *      changeCoefficient(newCoefficient, power) // Replaces the coefficient of the x p o w e r term with newCoefficient.
 *      A method that multiplies a polynomial by an integer (make this a normal named method - do not overload the multiplication operator).
 *      A method that adds two polynomials (you can overload the addition operator or make this a normal named method).
 *      method that prints out a polynomial.
 *      Overload the negation operator (-) as a member function to negate a polynomial.
 *      (NOTE: This is different from the subtraction operator! 
 *      The subtraction operator takes an argument - the polynomial you are subtracting - whereas the negation operator takes no arguments.)
 * 
 */
#include <iostream>
#include <cstdlib>
#include "assignment4.h"
 

using namespace std;

// initializes polynomial
myPolynomial::myPolynomial(){
    for (int i = 0; i <= 30; i++){
        coefficients[i] = 0;
    }
}

//creates a new polynomial
void myPolynomial::create(int num){
    maxDegree = num;
    for (int i = 0; i <= maxDegree; i++){
        coefficients[i] = 0;
    }
}

// asks for user input for coefficients and exponents
// return error message if input is not an int
// adds terms together if same exponent
// if exponent = 0, then multiply coefficient by 1
// store results in myPolynomial
void myPolynomial::readFromUser(int &num){
    maxDegree = num;
    for (int i = 0; i <= maxDegree; i++){
        cout << "Please insert coefficient at degree " << i << ": ";
        cin >> coefficients[i];
        // insert error case if user doesn't enter an int
        if (coefficients[i] >= -100 && coefficients[i] <= 100 && coefficients[i] != 0){
            if (maxDegree == 0){
                cout << coefficients[i] << " +";
            } else 
                cout << coefficients[i] << "x^" << i;
        } else {
            cout << "Only enter numbers. Try again." << endl;
        }
        cout << endl;
    }
}

// Returns the degree of a polynomial, which is the highest power of a term with a nonzero coefficient. 
// E.g.: int deg = myPolynomial.degree();
int myPolynomial::degree(){
    int temp[maxDegree];
    int first,max,tempNum;
    for (int i = 0; i <= maxDegree; i++){
        temp[i] = coefficients[i];
    }
    for (int j = maxDegree + 1; j > 0; j--){
        first = 0;
        for (int k = 1; k <= maxDegree; k++){
            if (temp[k] < temp[first]){
                first = k;
            }
        }
        tempNum = temp[first];
        temp[first] = temp [j];
        temp[j] = first;
    }
    return temp[maxDegree];
}

// Returns the coefficient of the x p o w e r term
int myPolynomial::coefficient(int exponent){
    for (int i = 0; i <= maxDegree; i++){
        if (i == exponent){
            return coefficients[i];
        }
    }
    return 0;
}

// Replaces the coefficient of the x p o w e r term with newCoefficient
void myPolynomial::changeCoefficient(int newCoefficient, int exponent){
    for (int i = 0; i <= maxDegree; i++){
        if (i == exponent){
            coefficients[i] = newCoefficient;
            if (exponent == 0){
                cout << "No term exists with that degree. No changes were made." << endl;
            }
        }
    }
}

// A method that multiplies a polynomial by an integer
void myPolynomial::multiply(int scalar, myPolynomial poly){
    for (int i = 0; i <= maxDegree; i++){
        if (coefficients[i] == 0){
            cout << "Please make sure you entered values for the polynomial" << endl;
        } else {
            coefficients[i] *= scalar;
        }
    }
}

// A method that adds two polynomials
myPolynomial myPolynomial::add(myPolynomial poly1, myPolynomial poly2, myPolynomial result){
    for (int i = 0; i <= maxDegree; i++){
        result.coefficients[i] = coefficients[i];
    }
    for (int j = 0; j <= poly1.maxDegree; j++){
        result.coefficients[j] = poly1.coefficients[j];
    }
    for (int k = 0; k <= poly2.maxDegree; k++){
        result.coefficients[k] += poly2.coefficients[k];
    }
    return result;
}

// negates a polynomial
myPolynomial myPolynomial:: operator -(){
    for (int i = 0; i <= maxDegree; i++){
        if (coefficients[i] == 0){
            cout << "Please make sure you entered values for the polynomial" << endl;
            return *this;   
        } else {
            coefficients[i] *= -1;
        }
    }
    return *this;
}

// prints the polynomial the user provided
void myPolynomial::printPolynomial(){
    for (int i = 0; i <= maxDegree; i++){
        if (coefficients[i] >= -100 && coefficients[i] <= 100 && coefficients[i] != 0){
            if (maxDegree == 0){
                cout << coefficients[i] << " +";
            } else {
                cout << coefficients[i] << "x^" << i << " + ";
            }
        } else {
            cout << "Only enter numbers. Try again." << endl;
        }
    }
    cout << endl;
}