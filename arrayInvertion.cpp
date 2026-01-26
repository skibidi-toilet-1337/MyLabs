#include <iostream>
using namespace std;

double arr[100];
double num;

int main() {
    
  cout << "Enter num of elements: " << endl;
  cin >> num;

  for (int index = 0; index < num; ++index) {
     cout << "element [" << index << "]" << ": ";
     cin >> arr[index]; 
  }
    
  int secondIndex;
  int temp;

  for (int index = 0; index < num/2; ++index) {
      secondIndex = num - 1 - index;
      temp = arr[index];
      arr[index] = arr[secondIndex];
      arr[secondIndex] = temp;
  }

  for (int index = 0; index < num; ++index) {
     cout << arr[index] << "\t";
  }
}
