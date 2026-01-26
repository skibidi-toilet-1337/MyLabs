#include <iostream>
using namespace std;

double matrix[5][5];
int columns;
int rows;
double mainDiagonalSum = 0;
double secondaryDiagonalSum = 0;

int main() {
  cout << "enter num of rows" << endl;
  cin >> rows;
  cout << "enter num of columns" << endl;
  cin >> columns;
  
  for (int row = 0; row < rows; ++row) {
    for (int column = 0; column < columns; ++column) {
      cout << "enter num of " << row + 1 << "; " << column + 1 << ": ";
      cin >> matrix[row][column];
    }
  }
  
  cout << "Before replace: " << endl;
  for (int row = 0; row < rows; row++) {
    for (int col = 0; col < columns; col++) {
      cout << matrix[row][col] << "\t";
    }
    cout << endl;
  }

    cout << "Begin replace: " << endl;
    for (int index = 0; index < rows; index++) {
      cout << "enter element[" << index << "][" << index << "]: ";
      cin >> matrix[index][index];
    }

    cout << "After replace: " << endl;
    for (int row = 0; row < rows; row++) {
      for (int col = 0; col < columns; col++) {
        cout << matrix[row][col] << "\t";
      }
      cout << endl;
    } 
}

