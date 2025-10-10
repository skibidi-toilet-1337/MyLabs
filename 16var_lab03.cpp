/***********************
 * Автор: Бобкова Е.А. *
 * Вариант: 16         *
 ***********************/

#include <iostream>
#include <cmath>

using namespace std;

const double g = 9.8;
double l = 3.0;
double lambda = 0.032;
double tWalls = 30.0;
double tAir = 150.0; 
double W;

double calcNu(double Re, double Gr) {
    
    double result;
    
    if (Re < 2200) {
      result = 0.13 * pow(Re, 0.33) * pow(Gr, 0.1);
    }
    else { 
      result = 0.018 * pow(Re, 0.88);
    }
    
    return result;
}
  
int main() {
    
  double Re;
  double Gr;  
  double Q;
  double Nu;  
  double a;
  double nu;
  double count;
  
  cout << "Enter number of variables: ";
  cin >> count;
 
  a = 4.0 / 100;
  nu = 2.3 * pow(10,-5);
  Gr = ((tAir - tWalls) / 273.0) * ((g * pow(l, 3)) / pow(nu, 2)); 
  
  for (int iteration = 0; iteration < count; ++iteration) {
    
    cout << "Enter a numeric variable: ";
    cin >> W;
    
    Re = (W * a) / nu;
    Nu = calcNu(Re, Gr);
    Q = 4 * lambda * l * Nu * (tAir - tWalls);
    
    cout << "W" << "\t" << "Re" << "\t" << "Nu" << "\t" << "Q" << endl 
         << W   << "\t" << Re   << "\t" << Nu   << "\t" << Q   << endl;
 
  }

}