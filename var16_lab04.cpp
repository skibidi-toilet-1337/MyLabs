/***********************
 * Автор: Бобкова Е.А. *
 * Вариант: 16         *
 ***********************/

#include <iostream>
#include <stdio.h>

using namespace std;
const int rows = 100;
const int columns = 100;

int compare(const void* a, const void* b) {

  double dA = *(double*)a;
  double dB = *(double*)b;

  if (dA > dB) {
    return 1;
  }
  else if (dA == dB) {
    return 0;
  }
  return -1;
}

int main() {

  double maxValue;
  double V[rows][columns];
  double values[rows * columns];
  double currValue;
  int numOfRows;
  int numOfColumns;
  int index = 0;
  double prevValue;
 
  cout << "Enter the number of rows: " << endl;
  cin >> numOfRows;

  cout << "Enter the number of columns: " << endl;
  cin >> numOfColumns;

  for (int rowIndex = 0; rowIndex < numOfRows; ++rowIndex) {
    for (int columnIndex = 0; columnIndex < numOfColumns; ++columnIndex) {
      cout << "Enter V[" << rowIndex << "][" << columnIndex << "]:" << endl;
      cin >> currValue;
      V[rowIndex][columnIndex] = currValue;
      values[index] = currValue;
      ++index;
      
    }
  }

  qsort(values, numOfRows*numOfColumns, sizeof(double), compare);
  prevValue = values[0];
  maxValue = values[0];
  
  for (int index = 1; index < numOfRows * numOfColumns; ++index ) {
    if (prevValue == values[index]) {
      maxValue = max(values[index], maxValue);
    }
    prevValue = values[index];
  }

  cout << "Matrix: " << endl;

  for (int rowIndex = 0; rowIndex < numOfRows; ++rowIndex) {
    for (int columnIndex = 0; columnIndex < numOfColumns; ++columnIndex) {
      cout << V[rowIndex][columnIndex] << "\t";
     
    }
    cout << endl;
  }

  cout << "Maximum value repeating more than once: " << maxValue;
  
}
