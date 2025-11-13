/***********************
 * Автор: Бобкова Е.А. *
 * Дата: 13.11.2025    *
 ***********************/

#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

vector<string> romanNumerals { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
vector<int> arabValues { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };

int arabicNumber;
string romanNumber;
bool optionSelected;

void romanEncoder(int number) {

  string result = "";
  int remaining = number;

  for (int index = 0; index < romanNumerals.size(); ++index) {
    int arabValue = arabValues[index];
    string romanNumeral = romanNumerals[index];

    while (remaining >= arabValue) {
      result += romanNumeral;
      remaining -= arabValue;
    }
  }
  cout << result;
}

void romanDecoder(string number) {
  
  int result = 0;
  string newNum;

  for (int index = 0; index < number.length(); ++index) {
    newNum += toupper(number[index]);
  }

  for (int index = 0; index < romanNumerals.size(); ++index) {
    string romanNum = romanNumerals[index];
    int arabValue = arabValues[index];

    while (newNum.substr(0, romanNum.length()) == romanNum) {
      result += arabValue;
      newNum = newNum.substr(romanNum.length());

    }
  }
  cout << result;
}

int main() {

  cout << "Do you want to encode in roman numerals? Print 1 or 0" << endl;
  cin >> optionSelected;
  
  if (optionSelected) {
    cout << "You have chosen roman numeral encoding!" << endl << "Enter your number:" << endl;
    cin >> arabicNumber;
    romanEncoder(arabicNumber);

  } else {
    cout << "You have chosen arab numeral encoding!" << endl << "Enter your number:" << endl;
    cin >> romanNumber;
    romanDecoder(romanNumber);
  }
}

