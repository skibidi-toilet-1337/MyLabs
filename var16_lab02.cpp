/***********************
 * Автор: Бобкова Е.А. *
 * Вариант: 16         *
 ***********************/
 
#include <iostream>
#include <cmath>

using namespace std;

int main() {
	
  double h0 = 0.05;
  double V10 = 7.5;
  double V;  
  double h = 0;
  
  cout << "h: " << "\t" << "V: " << endl;
    
  do {
    h+=(h<10)?2:10;  
    V = V10 * (pow(log(h / h0), 2) / pow(log(10 / h0), 2));
    cout << h << "\t" << V << endl;
    } while (h<90);
}
