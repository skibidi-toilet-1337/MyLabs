#include <iostream>
using namespace std;

double matrix[5][5];

int rows;
int columns;

int main() {

  cout << "how many rows" << endl;
  cin >> rows;

  cout << "how many columns" << endl;
  cin >> columns;

  double arrNum;
  double maxNum = DBL_MIN;
  double minNum = DBL_MAX;
  int maxRow, maxColumn;
  int minRow, minColumn;
   
    for (int row = 0; row < rows; ++row) {
      for (int column = 0; column < columns; ++column) {
        arrNum = 0;
        cout << "enter num of " << row << column << endl;
        cin >> arrNum;
        if (maxNum < arrNum) {
          maxNum = arrNum;
          maxRow = row;
          maxColumn = column;
        }
        if (minNum > arrNum) {
          minNum = arrNum;
          minRow = row;
          minColumn = column;
        }
        matrix[row][column] = arrNum;
      }
    }

    cout << "your array" << endl;
    for (int row = 0; row < rows; ++row) {
      for (int column = 0; column < columns; ++column) {
       
        cout << matrix[row][column] << " ";
      }
      cout << endl;
    }
    cout << "max: " << maxNum << endl << "min: " << minNum << endl;

    matrix[maxRow][maxColumn] = minNum;
    matrix[minRow][minColumn] = maxNum;

    cout << "your array but changed" << endl;
    for (int row = 0; row < rows; ++row) {
      for (int column = 0; column < columns; ++column) {
       
        cout << matrix[row][column] << " ";
      }
      cout << endl;
    }
}

