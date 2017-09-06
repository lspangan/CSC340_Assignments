/* 
 * File:   assignment1_prob2.cpp
 * Author: Leanna Pangan
 * ID#:    913074778
 * Email:  lspangan@mail.sfsu.edu
 * Class:  CSC 340.01
 * Problem 2: Implement another C++ program to sort a list of integers using the selection sort algorithm. 
 * You are required to use an integer vector to store the input numbers typed from the keyboard. 
 * The declaration of this vector will be in main(). 
 * You'll need to implement a separate function readData() to read numbers from the keyboard;
 * implement a separate function called selectionSort(), which will be called by the main() function to sort the afore-mentioned vector;
 * implement another function printVector() to print out the content of the vector. 
 * This function will be called by main() right after calling readData() and selectionSort(), respectively, to print out the vector content before and after being sorted.
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

// gets user input of random numbers (separated by a space) as a stringstream
// adds each number from the stringstream in to the vector<int> nums
void readData(vector<int> &nums)
{
    stringstream ss;
    string numbers;
    int num;
    getline(cin, numbers);
    ss << numbers;
    while (ss >> num){
        nums.push_back(num);
    }
}
       
// sorts vector<int> nums in order from least to greatest
void selectionSort(vector<int> &nums) {
    int minIndex = 0;
    for (int i = 0; i < nums.size() - 1; i++) {
        minIndex = i;
        for (int j = i + 1; j < nums.size(); j++)
            if (nums[j] < nums[minIndex])
                minIndex = j;
            if (minIndex != i) {
                swap(nums[i], nums[minIndex]);
            }
    }
}

// prints vector<int> nums in order from the least to greatest
void printVector(vector<int> &nums)
{
    selectionSort(nums);
    for (int i = 0; i < nums.size(); i++){
        cout << nums[i] << endl;
    }
}

// asks for numbers (separated by a space)
// calls each function taking in the numbers inputted by the user
int main() 
{
    vector<int> nums;
    int num;
    cout << "Enter numbers with a space between each number: ";
    readData(nums);
    selectionSort(nums);
    printVector(nums);
    return 0;
}

