#include <iostream>
using namespace std;

int main() {

  double x1, x2, x3, x4, y1, y2, y3, y4;
  double xAB, xDC, yAB, yDC;

  cout << "Enter A1(x1,y1)" << endl;
  cin >> x1 >> y1;
 
  cout << "Enter A2(x2,y2)" << endl;
  cin >> x2 >> y2;

  cout << "Enter A3(x3,y3)" << endl;
  cin >> x3 >> y3;

  cout << "Enter A4(x4,y4)" << endl;
  cin >> x4 >> y4;

  xAB = (x2 - x1);
  yAB = (y2 - y1);

  xDC = (x3 - x4);
  yDC = (y3 - y4);

  if ( (xAB == xDC) and (yAB == yDC) ) {
    cout << "This is a parallelogram!!!!";
  }
  else {
    cout << "This is not a parallelogram";
  }
}