/* 
 * File:   main.cpp
 * Author: Leanna Pangan
 * ID:     913074778
 * Email:  lspangan@mail.sfsu,edu
 *
 * 
 */

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

// takes a string and returns true if that string is a palindrome and false otherwise
bool isPalindrome(const string input) {
    string::const_iterator start = input.begin();
    string::const_iterator end = input.end();
    if (end - start <= 1) {
        cout << "Yes it is a palindrome" << endl;
        return true;
    }
    if (*start++ != *--end) {
        cout << "No it is not a palindrome" << endl;
        return false;
    }
    return isPalindrome(string(start, end));
}

// takes an integer and returns the sum of its digits
int digitSum(int input) {
    int sum = 0;
    if (input < 10) {
        return input;
    }
    if (input > 10) {
        sum += input % 10;
        input /= 10;
        return sum + digitSum(input);
    }
}

// takes a total number of stairs in the staircase and returns the number of ways to climb it
// option of taking a small stride (one stair) or a large stride (two stairs)
int waysToClimb(int numStairs) {
    
    if (numStairs == 0 || numStairs == 1) {
        return 1;
    }
    if (numStairs > 1) {
        return waysToClimb(numStairs - 1) + waysToClimb(numStairs - 2);
    }
}

int main() {
    
    // Test isPalindrome()
    cout << "Is 'noon' a palindrome?" << endl;
    string word1 = "noon";
    isPalindrome(word1); // returns true
    cout << "---------" << endl;
    cout << "Is 'moon' a palindrome?" << endl;
    string word2 = "moon";
    isPalindrome(word2); // returns false
    cout << "---------" << endl;
    
    // Test digitSum()
    int num;
    cout << "Enter number: ";
    cin >> num;
    cout << "The sum of " << num << "'s digits is: " << digitSum(num) << endl; // returns sum of digits of number inputted
    cout << "---------" << endl;
    
    // Test waysToClimb()
    int numOfStairs;
    cout << "Enter number of stairs: ";
    cin >> numOfStairs;
    cout << "Number of ways: " << waysToClimb(numOfStairs) << endl; // returns num of ways of number inputted
    return 0;
}

