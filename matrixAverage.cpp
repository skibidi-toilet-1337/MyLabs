#include <iostream>
using namespace std;

double matrix[5][5];
double columns;
double rows;
double lineSumOfNegatives[5];

int main() {

  cout << "enter num of rows" << endl;
  cin >> rows;
  cout << "enter num of columns" << endl;
  cin >> columns;

  for (int row = 0; row < rows; ++row) {
    for (int column = 0; column < columns; ++column) {
      cout << "enter m[" << row + 1 << "][" << column + 1 << "] : ";
      cin >> matrix[row][column];
    }
  }

  for (int col = 0; col < columns; col++) {
    lineSumOfNegatives[col] = 0;
    for (int row = 0; row < rows; row++) {
      lineSumOfNegatives[col] += matrix[row][col];
    }
    lineSumOfNegatives[col] /= rows;
  }
  for (int row = 0; row < rows; row++) {
    for (int col = 0; col < columns; col++) {
      cout << matrix[row][col] << "\t";
    }
    cout << endl;
  }

  cout << "--------" << endl << "Averages:" << endl;
  for (int col = 0; col < columns; col++) {
    cout << lineSumOfNegatives[col] << ",\t";
  }
}
