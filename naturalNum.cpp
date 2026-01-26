#include <iostream>
using namespace std;

int main() {
  int num;
  cout << "Enter your num: ";
  cin >> num;

  if (num < 2) {
    cout << "This natural number is not prime";
    return 0;
  }

  for (int index = 2; index * index <= num; ++index) {
    if (num % index == 0) {
      cout << "This natural number is not prime";
      return 0;
      }
    }
  
  cout << "This natural number is prime!!!";
  return 0;
}
