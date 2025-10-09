/***********************
 * Автор: Бобкова Е.А. *
 * Вариант: 16         *
 ***********************/

#include <iostream>
#include <map>

using namespace std;
const int rows = 3;
const int columns = 3;

int main() {

  double maxValue;
  map <double, unsigned> counter;
  double V[rows][columns];
  double currValue;

  for (int row = 0; row < rows; ++row) {
    for (int column = 0; column < columns; ++column) {
      cout << "Enter V[" << row << "][" << column << "]:" << endl;
      cin >> currValue;

      V[row][column] = currValue;

      if (counter.count(currValue) > 0) {
        ++counter[currValue];

      }
      else {
        counter[currValue] = 1;
      }

    }
  }

  cout << "Matrix: " << endl;

  for (int row = 0; row < rows; ++row) {
    for (int column = 0; column < columns; ++column) {
      cout << V[row][column] << "\t";
     
    }
    cout << endl;
  }
  
  maxValue = -DBL_MIN;
  for (auto value : counter) {
    if (value.second > 1) {
      maxValue = max(value.first, maxValue);
    }
  }
  cout << "Maximum value repeating more than once: " << maxValue;

}
