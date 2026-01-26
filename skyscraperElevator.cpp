#include <iostream>
using namespace std;

int main() {
  int floorsAmount, apartNum, floor, liftFloor;

  cout << "How many floors?" << endl;
  cin >> floorsAmount;

  cout << "Enter your apartment number" << endl;
  cin >> apartNum;

  floor = (apartNum + 2) / 3;

  if (floor % 2 == 0) {
    liftFloor = floor - 1;

  } else {
    liftFloor = floor;
  }

  cout << liftFloor;
}
