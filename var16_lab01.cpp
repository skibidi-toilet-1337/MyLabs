/***********************
 * Автор: Бобкова Е.А. *
 * Вариант: 16         *
 ***********************/
 
#include <iostream>
#include <cmath>

using namespace std;

const double Pi = 3.14159265358979323846;

double DegreesToRadians(double degrees) {
    return degrees * (Pi/180);
}
  
int main() {

  double m = 2.145;
  double a = 4.3;
  double b = 6.6;
  const double g = 9.8;
  
  double phi = 20;
      
  phi = DegreesToRadians(phi);
  
  double gamma1, gamma2, T1, T2;
  
  gamma1 = atan(a / g);
  T1 = m * sqrt(a * a + g * g);
 
  gamma2 = atan( - (( b * cos(phi)) / (g * (( 1 - b * sin(phi) / g) ))));
  T2 = m * sqrt( g * g + b * b - 2 * g * b * sin(phi));
  
  cout << "gamma1 = " << gamma1 << endl;
  cout << "T1 = " << T1 << endl;
  
  cout << "gamma2 = " << gamma2 << endl;
  cout << "T2 = " << T2 << endl;    
      
  return 0;
}
