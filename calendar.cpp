#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  int month, year;
  string monthsList[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
  int mDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
  cout << "Enter month number: ";
  cin >> month;

  while (month < 1 || month > 12) {
    cout << "Invalid month entry";
    cin >> month;
  }

  cout << "Enter a year number from 1900 to 2035: ";
  cin >> year;

  while (year < 1900 || year > 2077) {
    cout << "Invalid year entry";
    cin >> year;
  }

  cout << " -------------------------------" << endl << " Calendar - " << year << endl << " -------------------------------" << endl << endl;
  
  int days;
  int current;
  static int t[] = { 6, 2, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
  int y = year % 100;
  current = y / 12 + y % 12 + y % 12 / 4 + t[month - 1] + (20 - year / 100);

  if ((year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) &&
    month <= 2) current--;

  current = current % 7;

  if (month == 2) 
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
      days = 29;
    else
      days = mDays[month - 1];
  else
    days = mDays[month - 1];

  cout << endl << " -----------" << monthsList[month - 1] <<
    "-------------" << endl << "   Mon  Tue  Wed  Thu  Fri  Sat  Sun" << endl;
  cout ;
  
  int k;

  for (k = 0; k < current; k++)
    cout << "     ";

  for (int j = 1; j <= days; j++) {
    k++;
    cout << setw(5) << j;

    if (k > 6) {
      k = 0;
      cout << endl;
    }
  }

  if (k)
    cout << endl;

  current = k;
  return 0;
}
