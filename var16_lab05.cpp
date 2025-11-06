/***********************
 * Автор: Бобкова Е.А. *
 * Вариант: 16         *
 ***********************/

#include <iostream>
#include <stdio.h>

using namespace std;
const int lenMax = 100;

void inputArray(int& len, double V[lenMax]) {
  cout << "Enter the length of array: " << endl;
  cin >> len;
  for (int index = 0; index < len; ++index) {
    double currValue = 0;
    cout << "Enter V[" << index << "]:" ; 
    cin >> currValue;
    V[index] = currValue;
  }
}

double arithmeticAverage(int len, double V[lenMax]) {
  double sum = 0;
  for (int index = 0; index < len; ++index) {
    sum += V[index];
  }
  return sum / len;
}

int main() {
  double X[lenMax], Y[lenMax], Z[lenMax];
  int lenX = 0, lenY = 0, lenZ = 0;

  cout << "X array:" << endl;
  inputArray(lenX, X);
  cout << "Y array:" << endl;
  inputArray(lenY, Y);
  cout << "Z array:" << endl;
  inputArray(lenZ, Z);

  cout << "X\tY\tZ" << endl;
  cout << arithmeticAverage(lenX, X) << "\t" << arithmeticAverage(lenY, Y) << "\t" << arithmeticAverage(lenZ, Z);
}


