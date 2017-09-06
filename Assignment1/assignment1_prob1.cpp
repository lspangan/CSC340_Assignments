/* 
 * File:   assignment1_prob1.cpp
 * Author: Leanna Pangan
 * ID#:    913074778
 * Email:  lspangan@mail.sfsu.edu
 * Class:  CSC 340.01
 * Problem 1. Implement a C++ program that has the following functions:
 * Reads in a paragraph of English text up to 100 words from the keyboard and stores this paragraph in a string object. 
 * Feel free to include this task in the main() function.
 * Identifies the least frequent letter (case insensitive) in the above paragraph. 
 * Implement a separate function getLeastFreqLetter() for this task. 
 * The main() function then calls this function to find out the least frequent letter and its frequency.
 * Calculate the frequency of each unique word (case insensitive). 
 * Implement another function countWordFreq() for this task. 
 * Use white spaces and punctuation marks such as comma, period, semicolon and question mark as word delimiters. 
 * Please define a global struct that contains two fields, word and its count for this task. You can then define an array of this struct to store all the unique words and its counts. The main() function will call this function to print out each word and its corresponding frequency.
 * Identify the most frequently occurring word in the paragraph. 
 * Implement another stand-alone function getMostFreqWord() for this purpose. 
 * This function will be called in main() to identify the most frequent word and its respective frequency.
 * Please provide a simple yet flexible user interface so other people can use & test your program.
 */

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

// this struct will be used to store words and their frequencies
struct WordCounter
{
    string word;
    int wordFreq;
};

int numUniqueWords = 0;
WordCounter uniqueWordCounters[100];

// converts user input into lowercase letters
unsigned char convertCharToLowerCase(unsigned char in) {
  if (in >= 65 && in <= 91) {
    return in + 32;
  }
  return in;
}

// converts user input into lowercase words
string convertStringToLowerCase(string input) { 
    string output = input;
    if (input != ""){
        for (int i = 0; i < input.size(); i++) {
            output[i] = convertCharToLowerCase(input[i]);
        }
    }
    return output;
}

// checks if two lowercase words are the same
bool areLowercaseWordsTheSame(string firstLowercaseWord, string secondLowercaseWord) {
    if (convertStringToLowerCase(firstLowercaseWord) == convertStringToLowerCase(secondLowercaseWord)){
        return true;
    }  
    return false;
}

// checks if the letters inputted by the user and makes them case insensitive
bool isLetter(char in) {
    if ((in >= 65 && in <= 91) || (in >= 65 + 32 && in <= 91 + 32)) {
	return true;
    }
    return false;
}

// gets the next word of user input
string getNextWord(string input, int &curChar) {
    string output;
    while (curChar < input.size() && isLetter(input[curChar])) {
        output.append(1, input[curChar]);
        curChar++;
    }

    // move the curChar to the first letter of next word
    while (curChar < input.size() && !isLetter(input[curChar])) {
	curChar++;
    }
    return output;
}

// prints and lists out the words inputted by the user and their frequencies
void countWordFreq(string paragraph) {
    // to store each word before putting it into the wordFreq.word[position]
    string tempWord = "";
    int wordCount = 0, curChar = 0;
    // go through paragraph, getting one word at a time
    while (curChar < paragraph.size()){
    string currentWord = getNextWord(paragraph, curChar);
    tempWord = convertStringToLowerCase(currentWord);
        // keeps track of words inputted by user and their frequencies
        // stores them inside uniqueWordCounters
        for (int i = 0; i < wordCount; i++){
            if (areLowercaseWordsTheSame(tempWord, uniqueWordCounters[i].word)) {
                uniqueWordCounters[i].wordFreq++;
                tempWord = "";
            }
        }
        if (tempWord != "") {
            uniqueWordCounters[wordCount].word = tempWord;
            uniqueWordCounters[wordCount].wordFreq = 1;
            tempWord = "";
            wordCount++;
        }
    }
    cout << endl << "Words" << "\tFrequencies" << endl;
    for (int j = 0; j<wordCount; j++) {
	cout << uniqueWordCounters[j].word << "\t" << uniqueWordCounters[j].wordFreq << endl;
    }
}

// prints out the most frequent word from user input, 
// its frequency and total number of words altogether
void getMostFreqWord(string paragraph) {
    string temp = "";
    int curChar = 0, tempCount = 0, mostFreqWordIndex = 0;
    // go through paragraph, getting one word at a time
    while (curChar < paragraph.size()){
        string currentWord = getNextWord(paragraph, curChar);
        temp = convertStringToLowerCase(currentWord);  
	// check if word exists in list: uniqueWordCounters (use the function areLowercaseWordsTheSame)
	// if the word does not exist, create a new WordCounter entry in the list 
	// if the word exists, add a count of 1 to the WordCounter for the word 
        // finds temp (the most frequent word and its frequency) and numUniqueWords (total number of words)
        for (int i = 0; i < 100; i++){
            if(areLowercaseWordsTheSame(temp, uniqueWordCounters[i].word)){
                numUniqueWords++;
            }
            if (uniqueWordCounters[i].wordFreq > 0 && uniqueWordCounters[i].wordFreq > tempCount){
                mostFreqWordIndex = i;
                tempCount = uniqueWordCounters[mostFreqWordIndex].wordFreq;
            } 
        }
    }
    
    cout << endl << "Most frequent word and its frequency: " << endl;
    cout << uniqueWordCounters[mostFreqWordIndex].word << "\t" << tempCount << endl;
    cout << endl << "Number of words: " << endl << numUniqueWords << endl;
}

// prints out the least frequent letter from user input and its frequency
void getLeastFreqLetter(string paragraph)
{ 
  // if there are no letters, don't do anything
    if (paragraph.size() == 0) {
        cout << "There are no letters";
        return;
    }

    // creates an array for a-z
    int letters[26] = {0};
    
    // increments through the paragraph
    for (int i = 0; i < paragraph.size(); i++){
        letters[convertCharToLowerCase(paragraph[i]) - (unsigned char)'a']++;
    }

    // finds least frequent letter
    // first assume that the least letter count is the size of the paragraph + 1.
    int leastLetterCount = int(paragraph.size() + 1); // start with the size of the paragraph
    int leastLetterIndex = -1; // start with an invalid value
    for (int k = 0; k < 26; k++){
        // do not consider non occurring letters
        if(letters[k] > 0 && letters[k] < leastLetterCount){
            leastLetterIndex = k;
            leastLetterCount = letters[leastLetterIndex];
        }
    }
    cout << endl << "Least frequent letter and its frequency: " << endl;
    cout << (unsigned char)(leastLetterIndex + (unsigned char)'a') << "\t" << leastLetterCount << endl;
}

// asks for user input and calls each function taking in user input
int main() 
{
    string paragraph;
    cout << "Enter input:" << endl;
    getline (cin, paragraph);
    getLeastFreqLetter(paragraph);
    countWordFreq(paragraph);
    getMostFreqWord(paragraph);
    return 0;
}