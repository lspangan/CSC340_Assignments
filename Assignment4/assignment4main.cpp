/* 
 * File:   assignment4main.cpp
 * Author: leannapangan
 *
 * Created on October 12, 2015, 1:01 PM
 */

#include <cstdlib>
#include <iostream>
#include "assignment4.h"

using namespace std;


int main() {
    int choice, exponent, num;
    myPolynomial poly, poly1, poly2, result;
    // asks user to create a polynomial
    cout << "Enter highest degree: ";
    cin >> num;
    poly.readFromUser(num);
    cout << "The polynomial is: ";
    poly.printPolynomial();
    cout << "Type the number that corresponds to the command" << endl;
    cout << "1. Display highest degree 2. Display coefficient 3. Change coefficient" << endl <<
            "4. Multiply polynomial by a scalar value 5. Add 2 polynomials 6. Negate polynomial" << endl <<
            "7. End program" << endl;
    while (cin >> choice){
        if (choice < 1 || choice > 7){
        cout << "Please type the correct number" << endl;
        } else if (choice == 1){
            // prints highest degree that corresponds to the initial polynomial provided by the user 
            cout << "The highest degree is: " << poly.degree() << endl;
        } else if (choice == 2){
            // prints coefficient that corresponds to the initial polynomial provided by the user
            cout << "Enter degree that corresponds to the coefficient you wish to display: ";
            cin >> exponent;
            if (exponent < 0){
                cout << "No coefficient with that degree" << endl;
            } else {
                cout << "The coefficient is: " << poly.coefficient(exponent) << endl;;
            }
        } else if (choice == 3){
            // prints new coefficient that corresponds to the initial polynomial provided by the user
            int newCoefficient, degree;
            cout << "Enter degree that corresponds to the coefficient you wish to change: ";
            cin >> degree;
            if (degree < 1){
                cout << "No coefficient with that degree" << endl;
            } else {
                cout << "Enter new coefficient: ";
                cin >> newCoefficient;
                cout << "The new coefficient is: ";
                poly.changeCoefficient(newCoefficient, degree);
                poly.printPolynomial();
            }
        } else if (choice == 4){
            // prints the initial polynomial multiplied by the value the user provided
            int scalar;
            cout << "What number do you wish to multiply by the polynomial? ";
            cin >> scalar;
            poly.multiply(scalar, poly);
            poly.printPolynomial();
        } else if (choice == 5){
            // prints the resultant polynomial after adding two polynomials provided by the user
            int num2;
            cout << "Enter highest degree for first polynomial: ";
            cin >> num2;
            poly1.readFromUser(num2);
            cout << "The first polynomial is: ";
            poly1.printPolynomial();
            cout << "Enter highest degree for second polynomial: ";
            cin >> num2;
            poly2.readFromUser(num2);
            poly2.printPolynomial();
            result.add(poly1, poly2, result);
            cout << "The resultant polynomial is: ";
            result.printPolynomial();
        } else if (choice == 6){
            // prints the negation of the initial polynomial provided by the user
            poly.operator -();
            poly.printPolynomial();
        } else if (choice == 7){
            // prints "Goodbye" and returns 0 to end the while loop and program
            cout << "Goodbye" << endl;
            return 0;
        }
    }
    
    return 0;
}

