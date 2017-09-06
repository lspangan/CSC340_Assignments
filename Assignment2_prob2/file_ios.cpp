/* 
 * File:   file_ios.cpp
 * Author: Leanna Pangan
 * ID#:    913074778
 * Email:  lspangan@mail.sfsu.edu
 *
 * Given two text files, each of which contains a a sorted list of integers (one integer per line) in non-decreasing order, 
 * write a C++ program to merge these two input files into a third file in which all the numbers remain their sorted order. 
 * Your program will include the main() function and another function that merges the two files. 
 * Specifically, the main() function will ask a user to type in the names of the two input files. 
 * It will then call the merging function to merge the two files. 
 * Finally, it informs the user the name of the merged file. 
 * Note that you are not allowed to first load all the numbers in the two files into an array or vector 
 * then apply a sorting algorithm to this array.
 */

#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;


// merges two files and keeps them in sorted order
void merge(ifstream& inStream1, ifstream& inStream2, ofstream& outStream){
    int num1 = 0, num2 = 0; //represents current lowest number in file 1 and file 2
    
    // takes the first number from each file
    inStream1 >> num1;
    inStream2 >> num2;
        
    // compares the numbers from both files
    while (inStream1.good() || inStream2.good()) {
        if (num1 < num2) {
            outStream << num1 << endl; // adds the lowest current number in file1 to the new file
            inStream1 >> num1; // goes to the next number in file1
        } else {
            outStream << num2 << endl; // adds the lowest current number in file2 to the new file
            inStream2 >> num2; // goes to the next number in file2
        }
    }
    // after while loop we have two numbers left
    // compares numbers to see which is greater
    // lower number gets inserted first, then the higher number after
    if (num1 < num2) {
	outStream << num1 << endl;
	outStream << num2 << endl;
    } else {
	outStream << num2 << endl;
	outStream << num1 << endl;
    }
}

// reads from two int text files provided by the user using ifstream
// writes to a new file merge_two_files.txt using ofstream
// calls merge() to combine the numbers from the two files into merge_two_files.txt
// keeps numbers in sorted order from least to greatest
int main() {
    
    ifstream inStream1;
    ifstream inStream2;
    ofstream outStream;
    string filename1, filename2, filename3 = "merge_Files.txt";
    
    // asks the user for two int .txt file names
    cout << "Type name for the first input file(put quotation marks around filename): ";
    filename1 = "numA.txt"; // "numA.txt used as test file
    cout << endl << "Type name for the second input file(put quotation marks around filename): ";
    filename2 = "numB.txt"; // "numB.txt" used as test file
    // checks whether the files were opened successfully
    inStream1.open(filename1);
    inStream2.open(filename2);
    if (!inStream1.is_open() && !inStream2.is_open()) {
        cout << "Error opening files.";
        return 0;
    }
    
    // writes a new file that contains the contents of file1 and file2
    outStream.open(filename3, ios_base::app);
    
    // prints out the new file name
    cout << endl << "The new file name is: " << filename3.c_str() << endl;
    
    // calls merge() to merge the two files given by the user
    merge(inStream1, inStream2, outStream);
    
    inStream1.close();
    inStream2.close();
    outStream.close();


}

