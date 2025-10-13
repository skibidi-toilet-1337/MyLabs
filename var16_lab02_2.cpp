/***********************
 * Автор: Бобкова Е.А. *
 * Вариант: 16         *
 ***********************/

#include <iostream>
#include <cmath>

using namespace std;

double calcV(double V10, double h, double h0) {

  double V;

  V = V10 * (pow(log(h / h0), 2) / pow(log(10.0 / h0), 2));

  return V;
}

int main() {

  double h0 = 0.05;
  double V10 = 7.5;
  double V;
  double h = 0;
  int step = 2;
  int startValue;
  int endValue;
  
  cout << "Enter the start and end value: " << endl;
  cin >> startValue >> endValue;
  cout << "h: " << "\t" << "V: " << endl;

  while (h < startValue) {

    h += step;
    V = calcV(V10, h, h0);

    cout << h << "\t" << V << endl;
  }

  do {

    h += step * 10;
    V = calcV(V10, h, h0);

    cout << h << "\t" << V << endl;
  } while (h < endValue);

}