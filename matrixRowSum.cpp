#include <iostream>
using namespace std;

double matrix[5][5];
double columns;
double rows;

int main() {

  double lineSum = 0;

  cout << "enter num of rows" << endl;
  cin >> rows;
  cout << "enter num of columns" << endl;
  cin >> columns;


  for (int row = 0; row < rows; ++row) {
    for (int column = 0; column < columns; ++column) {
      cout << "enter num of " << row+1 << "; " << column+1 << ": ";
      cin >> matrix[row][column];
    }
  }

  for (int row = 0; row < rows; row++) {
    lineSum = 0;
    for (int col = 0; col < columns; col++) {
      cout << matrix[row][col] << "\t";
      lineSum += matrix[row][col];
    }
    cout << "sum: " << lineSum;
    cout << endl;
  }
}
