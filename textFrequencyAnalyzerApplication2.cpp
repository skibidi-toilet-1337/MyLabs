/***********************
 * Автор: Бобкова Е.А. *
 * Дата: 06.11.2025    *
 ***********************/

#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <map>

using namespace std;

map<char, int> alphabet;
map<string, int> twoLettersComb;

ifstream incomingStream("D:/text_example.txt");

void letterRepetitionFrequency() {

  string line;
  int numOfLettersInLine = 0;
  int numOfLetters = 0;

  while (getline(incomingStream, line)) {
        numOfLettersInLine = 0;

        for (int index = 0; index < line.length(); ++index) {
          char firstChar = tolower(line[index]);
          char secondChar = tolower(line[index + 1]);
          string twoLetters = "" + string(1, firstChar) + string(1, secondChar);

          if (isalpha(firstChar) != 0) {
            numOfLettersInLine += 1;

            if (alphabet.count(firstChar) >= 0) {
              alphabet[firstChar] += 1;
            }
            else {
              alphabet[firstChar] = 1;
            }

            if (isalpha(secondChar) != 0) {

              if (twoLettersComb.count(twoLetters) >= 0) {
                twoLettersComb[twoLetters] += 1;
              }
              else {
                twoLettersComb[twoLetters] = 1;
              }
            }
          }
        } 
    numOfLetters += numOfLettersInLine;
  } 

  cout << "Letter repetition frequency in text: " << endl;
  for (map<char, int>::iterator it = alphabet.begin(); it != alphabet.end(); ++it) {
    cout << "Key: " << it -> first <<
      "\tFrequency: " << ((float) it -> second / numOfLetters) * 100 <<
      "%" << endl;
  }
  cout << endl << "Frequency of repetitions of two-letter combinations in text: " << endl;
  for (map<string, int>::iterator it = twoLettersComb.begin(); it != twoLettersComb.end(); ++it) {
    cout << "Key: " << it -> first <<
      "\tFrequency: " << ((float) it -> second / numOfLetters) * 100 <<
      "%" << endl;
  }
}

int main() {

  if (incomingStream.is_open() == 0) {
    cout << "Opening error" << endl;
    return -1;
  }
  else {
      letterRepetitionFrequency();
      incomingStream.close();
  }
}
