/***********************
 * Автор: Бобкова Е.А. *
 * Вариант: 16         *
 ***********************/

#include <iostream>
#include <cmath>

using namespace std;

const double a = 4.0 / 100;
const double l = 3.0;
const double lambda = 0.032;
const double tWalls = 30.0;
const double tAir = 150.0; 
const double nu = 2.3 * pow(10,-5);
const double g = 9.8;

double W[5]={0.5,1,2,5,10};

double calcNu(double Re, double Gr) {
    
    double result;
    
    if (Re<2200) {
      result = 0.13 * pow(Re,0.33) * pow(Gr,0.1);
    }
    else { 
      result = 0.018 * pow(Re,0.88);
    }
    
    return result;
}
  
int main() {
    
  double Re;
  double Gr;  
  
  Gr = ((tAir - tWalls) / 273.0) * ((g * pow(l,3)) / pow(nu,2)); 
  
  cout << "W" << "\t" << "Re" << "\t" << "Nu" << "\t" << "Q" << endl;
  
  for (int i = 0; i <= 4; ++i) {
    
    Re = (W[i] * a) / nu;
  
    double Nu = calcNu(Re,Gr);
  
    double Q = 4 * lambda * l * Nu * (tAir - tWalls);
  
    cout << W[i] << "\t" << Re << "\t" << Nu << "\t" << Q << endl;
 
  }

}
