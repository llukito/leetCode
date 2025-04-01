/*
 * File: FleschKincaid.cpp
 * ----------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the starter project for the Flesch-Kincaid problem.
 * [TODO: rewrite the documentation]
 */

#include <iostream>
#include <fstream>
#include "console.h"
#include "simpio.h"
#include "tokenscanner.h"
#include <algorithm> // used to turn string into lowercase

using namespace std;

// constants we need to compute grade
const double C_0 = -15.59;
const double C_1 = 0.39;
const double C_2 = 11.8;

// function prototypes
void getGrade();
void readFile(ifstream& file);
bool startsWithLetter(string& token);
int countSyllables(string token);
bool isVowel(char ch);
bool isSentenceEnd(string& token);
void checkFileContent(int& s1, int& s2);
double calculateGrade(int n1, int n2, int n3);
void printResults(int numWords, int numSentences, int numSyllables, double grade);

int main() {
    getGrade();
    return 0;
}

/*
* This function let's user input file names as many times
* as they wish if they don't exit. Also if they entered 
* wrong name they are notified
*/
void getGrade() {
    while (true) {
        string fileName = getLine("Enter file Name or type exit: ");
        if (fileName == "exit")break;
        ifstream file(fileName.c_str());
        if (file.is_open()) {
            readFile(file);
            file.close();
        }
        else {
            cout << "Error occured while opening file" << endl;
        }
    }
    cout << "You exited" << endl;
}

/*
* Reads content of file with TokenScanner and count words, 
* sentences and syllables. After it prints results
*/
void readFile(ifstream &file) {
    int numWords = 0;
    int numSentences = 0;
    int numSyllables = 0;
    string line;
    while (getline(file, line)) {
        TokenScanner scanner(line);
        scanner.ignoreWhitespace();
        scanner.addWordCharacters("'"); // will not treat as delimiter
        while (scanner.hasMoreTokens()) {
            string token = scanner.nextToken();
            if (startsWithLetter(token)) {
                numWords++;
                numSyllables += countSyllables(token);
            }
            else if (isSentenceEnd(token)) {
                numSentences++;
            }
        }
    }
    checkFileContent(numWords, numSentences);
    double grade = calculateGrade(numWords, numSentences, numSyllables);
    printResults(numWords, numSentences, numSyllables, grade);
}

/*
* This functions checks if token (if not empty) starts with 
* a letter. If it starts, then it is a word
*/
bool startsWithLetter(string& token) {
    if (token.empty()) return false;
    return isalpha(static_cast<unsigned char>(token[0]));
}

/*
* This function counts syllables in a word by counting vowels,
* which should not be next to each other and last char should 
* not be 'e' (task specified those)
*/
int countSyllables(string token) {
    transform(token.begin(), token.end(), token.begin(), ::tolower);
    int syllables = 0;
    bool vowelBefore = false;
    // iterate till last char, since we treat last one differently
    for (int i = 0; i < token.length()-1; i++) {
        if (isVowel(token[i])) {
            if (!vowelBefore) {
                syllables++;
            }
            vowelBefore = true;
        }
        else {
            vowelBefore = false;
        }
    }
    char lastChar = token[token.length() - 1];
    if (isVowel(lastChar) && !vowelBefore && lastChar != 'e')syllables++;
    return max(syllables, 1); // we return 1 if found none
}

/*
* I couls have used string of "aeiouy" and then find, but this would
* be so uneffective regarding time
*/
bool isVowel(char ch) {
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y';
}

/*
* Here We check if token indicates the end of sentence, which
* means that token should be (.)(!) or (?) -> task specified those
*/
bool isSentenceEnd(string& token) {
    return token == "." || token == "!" || token == "?";
}

/*
* As task said, we need to make sure numWords and numSentences 
* are not 0, so we don't devide by 0. Syllables can be 0, since
* we don't devide anything with it
*/
void checkFileContent(int &numWords, int &numSentences) {
    if (numWords == 0) { 
        numWords = 1;
    }
    if (numSentences == 0) {
        numSentences = 1;
    }
}

/*
* Our primary function that uses formula to compute grade
*/
double calculateGrade(int numWords, int numSentences, int numSyllables) {
    double wordsOverSentences = numWords / (double)numSentences;
    double syllablesOverWords = numSyllables / (double)numWords;
    return C_0 + C_1 * wordsOverSentences + C_2 * syllablesOverWords;
}

void printResults(int numWords, int numSentences, int numSyllables, double grade) {
    cout << "words " << numWords << endl;
    cout << "sentences " << numSentences << endl;
    cout << "syllables " << numSyllables << endl;
    cout << "grade " << grade << endl;
}