/**********************
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
    
    cout << "h: " << "\t" << "V: " << endl;

    for (int h: {2, 4, 6, 8, 10, 30, 50, 70, 90}) {
      V = V10 * (pow(log(h / h0), 2) / pow(log(10 / h0), 2));
      cout << h << "\t" << V << endl;
    }
}
