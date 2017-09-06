/* 
 * File:   access_to_file.cpp
 * Author: Leanna Pangan
 * ID#:    913074778
 * Email:  lspangan@mail.sfsu.edu
 *
 * The file posted here on iLearn contains a formatted list of 9999 integers that are randomly generated in the range of [1,9999]. 
 * Each integer occupies one single line and takes 4 characters' space per line. 
 * Alternatively, you can think that each number takes 5 characters' space, four for the number and one for the newline character. 
 * Write a C++ program using the seekg() and seekp() functions to insert the numbers 7777 through 7781 between the 6000-th and 6001-st numbers of the input file. 
 * Below are a few useful tips:
 * The tellg() and tellp() functions return the position of the current character in an input stream or output stream, respectively.
 * You are strongly recommended to use the tellg() function to first learn about the starting position of each integer. 
 * This will help you locate the exact starting position to insert the new numbers.
 * You can use the width() function to specify the number of characters you'd like an integer to occupy.
 * In addition to the "output" operator (<<), you can also use the write() function to write to a file.
 * Before you insert the numbers, you will need to first store all the numbers from the 6001-st number in an internal data structure, e.g., array. 
 * Otherwise, some of them will be overwritten.
 * Finally, always call the clear() function before calling the seekg() or seekp() function. 
 * Otherwise, you might encounter inexplicable behaviors.
 * You are not allowed to create or use any other files except the single input file.
 * You must use seekg() or seekp() to directly identify the insertion point to insert the new numbers.
 * It's acceptable to hardcode the input file name and implement everything in the main() function. 
 * However, it's preferred to create a separate function that handles the insertion of new numbers.
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// inserts the numbers 7777-7781 into file1.txt after the 6000th number
void insertNums(fstream& f_File){
    
    // inserts numbers 7777-7781 into text file
    for (int insertedNums = 7777; insertedNums < 7782; insertedNums++){
        f_File << insertedNums << endl;
    }
}

// uses fstream to read/write to file1.txt
// locates the 30,000th byte and stores the numbers after it into a vector<int>
// calls insertNums()
// inserts the vector into the file after inserting numbers 7777-7781
int main() {
    fstream f_File;
    vector<int> storedNums;
    f_File.open("file1.txt");
    
    // locates position of current character and move position of character between the 6000th and 6001th number
    // stores numbers 6001-9999 in a vector<int>
    f_File.seekg(30000); // goes to the 30,000th byte (6001th number)
    while (true){
        int nextNum;
        f_File >> nextNum;
        if (f_File.fail()) {
            cout << "Error opening file.";
            break;
        }
        storedNums.push_back(nextNum);
    }  
    
    f_File.clear();
    
    // uses seek to locate the position after the 6000th number
    f_File.seekp(30000);
    
    // calls insertNums() to insert 7777-7781
    insertNums(f_File);
    
    f_File.clear();
    f_File.seekp(30025);
    // adds the array of numbers back into the list
    for(int storeVector = 0; storeVector < storedNums.size(); storeVector++){
        f_File << storedNums[storeVector] << endl;
    }
    
    f_File.close();
    
    return 0;
}

