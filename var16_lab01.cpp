/***********************
 * Автор: Бобкова Е.А. *
 * Вариант: 16         *
 ***********************/
 
#include <iostream>
#include <cmath>

using namespace std;

const double pi = 3.14159265358979323846;
const double g = 9.8;
  
double degreesToRadians(double degrees) {
    return degrees * (pi / 180);
}
  
int main() {
	
  double m = 2.145;
  double a = 4.3;
  double b = 6.6;
  double phi = 20.0;
      
  phi = degreesToRadians(phi);
  
  double gamma1, gamma2, T1, T2;
  
  gamma1 = atan(a / g);
  T1 = m * sqrt(a * a + g * g);
 
  gamma2 = atan(-(( b * cos(phi)) / (g * ((1 - b * sin(phi) / g)))));
  T2 = m * sqrt( g * g + b * b - 2 * g * b * sin(phi));
  
  cout << "gamma1 = " << gamma1 << endl << "T1 = " << T1 << endl;
  cout << "gamma2 = " << gamma2 << endl << "T2 = " << T2 << endl;
   
  return 0;
}

