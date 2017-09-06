/* 
 * File:   matrix_multiplication.cpp
 * Author: Leanna Pangan
 * ID#:    913074778
 * Email:  lspangan@mail.sfsu.edu
 *
 * Write a C++ program to compute the product of two matrices. 
 * You are required to use the template class vector to represent a matrix. 
 * (See the sample code below on how to create and initialize a 2d-matrix using vectors.) 
 * Specifically, your program will include the main( ) function and a second function multiply_matrices( ). 
 * The main() function will 
 * - allow the end-users to provide the dimensionality of the two matrices A and B, and subsequently the content of A and B
 * - call the multiply_matrices() function to compute the product of A and B
 * - print out the multiplication result
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <iomanip>


using namespace std;

vector< vector<int> > multiply_matrices(vector< vector<int> > &matrixA, vector< vector<int> > &matrixB){
    int aRow = matrixA.size(), aCol = matrixA[0].size(), bCol = matrixB[0].size();
    vector< vector<int> > matrixC(aRow, vector<int> (bCol));
    
    //go through elements of matrixA: i, k
    //go through elements of matrixB: k, j
    //matrixC += matrixA[i][k] * matrixB[k][j]
    //matrixC = i,j
    cout << setw(3);
    for (int i = 0; i < aRow; i++){
        for(int j = 0; j < bCol; j++){
            for(int k = 0; k < aCol; k++){
                matrixC[i][j] += matrixA[i][k] * matrixB[k][j];
            }
            cout << "   " << matrixC[i][j] << setw(3);
            }
        cout << endl;
    }
    return matrixC;
} 

int main() {
    int num_rowsA, num_rowsB, num_colsA, num_colsB;
    
    // asks user for the # of rows and columns for Matrix A and B
    cout << "Please provide the number of rows and columns for Matrix A: ";
    cin >> num_rowsA >> num_colsA; 
    cout << "Please provide the number of rows and columns for Matrix B: ";
    cin >> num_rowsB >> num_colsB;
    
    //initializes each matrix based on dimensions given from user
    vector < vector<int> > matrixA(num_rowsA, vector<int>(num_colsA));
    vector < vector<int> > matrixB(num_rowsB, vector<int>(num_colsB));
    
    if (num_rowsB == num_colsA){
        
        // asks user for numbers to add in Matrix A
        cout << endl << "Please provide numbers for Matrix A: ";
        
        for (int rowA = 0; rowA < matrixA.size(); rowA++){
            for (int colA = 0; colA < matrixA[rowA].size(); colA++){
                cout << "A[" << rowA << "][" << colA << "] = ";
		cin >> matrixA[rowA][colA];
            }
        }

        cout << setw(3);
        //displays Matrix A
        cout << endl << "Matrix A: " << endl;
        for (int rowA = 0; rowA < matrixA.size(); rowA++){
            for (int colA = 0; colA < matrixA[rowA].size(); colA++){
                cout << "   " << matrixA[rowA][colA] << setw(3);
            }
            cout << endl;
        }
        
        // asks user for numbers to add in Matrix B
        cout << endl << "Please provide numbers for Matrix B: ";
        
        for (int rowB = 0; rowB < matrixB.size(); rowB++){
            for (int colB = 0; colB < matrixB[rowB].size(); colB++){
                cout << "B[" << rowB << "][" << colB << "] = ";
		cin >> matrixB[rowB][colB];
            }
        }
        
        cout << setw(3);
        // displays Matrix B
        cout << endl << "Matrix B: " << endl;
        for (int rowB = 0; rowB < matrixB.size(); rowB++){
            for (int colB = 0; colB < matrixB[rowB].size(); colB++){
                cout << "   " << matrixB[rowB][colB] << setw(3);
            }
            cout << endl;
        }
    } else {
        
        // stops program if user inputs different values for colA and rowB]
        cout << "Sorry, matrix multiplication only works when the # of columns of Matrix A "
                "and the # of rows of Matrix B are equal" << endl;
    }
    
    // calls multiply_matrices to multiply Matrix A and B
    cout << endl << "Product of Matrix A and B: " << endl;
    multiply_matrices(matrixA, matrixB);
    
    return 0;
}

