#include <iostream>
#include <cmath>
using namespace std;

int main() {
  double a, b, c;
  double semiperimeter, square;
  cout << "Enter the lengths of triangle's sides a, b, c: ";
  cin >> a >> b >> c;

  if (a <= 0 || b <= 0 || c <= 0) {
    cout << "Lengths must be positive." << endl;
    return 1;
  }
    
  if ((a + b > c) && (a + c > b) && (b + c > a)) {
    semiperimeter = (a + b + c) / 2;
    square = sqrt(semiperimeter * (semiperimeter - a) * (semiperimeter - b) * (semiperimeter - c));
    cout << "Triangle is ok! Square: " << square << endl;

  } else {
    cout << "Triangle is not ok." << endl;
  }
}