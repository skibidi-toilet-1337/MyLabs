#include <iostream>
using namespace std;
int year;

int main() {

  cout << "Enter your year" << endl;
  cin >> year;

  if ((year % 400 == 0) or ((year % 4 == 0) and (year % 100 != 0))) {
    cout << "This year is a leap year!!!!";
  } else {
    cout << "This year is not a leap year";
  }
}