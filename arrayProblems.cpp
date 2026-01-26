#include <iostream>
using namespace std;
double arr[100];
int arrLength;
double arrSum = 0;
double arrMulti = 1;
double arrNum;
double maxNum = DBL_MIN;
double minNum = DBL_MAX;

int main() {
  cout << "enter your length of array" << endl;
  cin >> arrLength;

  for (int element = 0; element < arrLength; ++element) {
    arrNum = 0;
    cout << "enter num " << element << endl;
    cin >> arrNum;
    if (maxNum < arrNum) {
      maxNum = arrNum;
    }
    if (minNum > arrNum) {
      minNum = arrNum;
    }
    arr[element] = arrNum;
  }

  for (int element = 0; element < arrLength; ++element) {
    cout << arr[element] << " ";
  }
  
  for (int element = 0; element < arrLength; ++element) {
    arrSum += arr[element];
    arrMulti *= arr[element];
  }

  cout << endl << "The sum of all elements of the array: " << arrSum << endl << "The multiplication of all elements of the array: " << arrMulti << endl << "Max: " << maxNum << " " << "Min: " << minNum << endl;
}