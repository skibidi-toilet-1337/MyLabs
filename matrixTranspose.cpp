#include <iostream>
using namespace std;

double matrix[5][5];

int main() {
  int rows, columns;
  double arrNum;
  double buffNum;
  
  cout << "enter num of rows" << endl;
  cin >> rows;
  cout << "enter num of columns" << endl;
  cin >> columns;

  
  for (int row = 0; row < rows; ++row) {
    for (int column = 0; column < columns; ++column) {
      arrNum = 0;
      cout << "enter num of " << row << " " << column << endl;
      cin >> arrNum;
      matrix[row][column] = arrNum;
    }
  }

  cout << "your arr" << endl;
  for (int row = 0; row < rows; ++row) {
    for (int column = 0; column < columns; ++column) {
      cout << matrix[row][column] << " ";
    }
    cout << endl;
  }

  for (int row = 0; row < rows; ++row) {
    for (int column = row+1; column < columns; ++column) {
      buffNum = matrix[row][column];
      matrix[row][column] = matrix[column][row];
      matrix[column][row] = buffNum;
    }
  }

  cout << "transposed arr" << endl;
  for (int row = 0; row < rows; ++row) {
    for (int column = 0; column < columns; ++column) {
      cout << matrix[row][column] << " ";
    }
    cout << endl;
  }
}
