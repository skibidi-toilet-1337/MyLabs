#include <iostream>
using namespace std;

double matrix[5][5];
double newMatrix[5][5];

int main() {
  int rows, columns;
  double arrNum;
  double buffNum;
  int newRow, newColumn;

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
    for (int column = 0; column < columns; ++column) {
      newRow = column;
      newColumn = rows - 1 - row;
      newMatrix[newRow][newColumn] = matrix[row][column];
      
    }
  }

  cout << "new arr" << endl;
  for (int row = 0; row < rows; ++row) {
    for (int column = 0; column < columns; ++column) {
      cout << newMatrix[row][column] << " ";
    }
    cout << endl;
  }
}
