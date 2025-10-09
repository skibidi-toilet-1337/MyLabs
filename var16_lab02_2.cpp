/***********************
 * Автор: Бобкова Е.А. *
 * Вариант: 16         *
 ***********************/

#include <iostream>
#include <cmath>

using namespace std;

double calcV(double V10, double h, double h0) {

  double V;

  V = V10 * (pow(log(h / h0), 2) / pow(log(10 / h0), 2));

  return V;
}

int main() {

  double h0 = 0.05;
  double V10 = 7.5;
  double V;
  double h = 0;

  cout << "h: " << "\t" << "V: " << endl;

  while (h < 10) {

    h += 2;
    V = calcV(V10, h, h0);

    cout << h << "\t" << V << endl;
  }

  do {

    h += 20;
    V = calcV(V10, h, h0);

    cout << h << "\t" << V << endl;
  } while (h < 90);

}
