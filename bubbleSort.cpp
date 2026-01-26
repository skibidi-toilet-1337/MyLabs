#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& numbers) {
  int length = numbers.size();
  for (int i = 0; i < length - 1; ++i) {
    
    bool flag = false;
    for (int j = 0; j < length - i - 1; ++j) {
      if (numbers[j] > numbers[j + 1]) {
        swap(numbers[j], numbers[j + 1]);

        flag = true;
      }
    }

    if (!flag)
      break;
  }
}

int main() {

  int len, number;
  vector<int> numbers = {};

  cout << "Enter how many numbers" << endl;
  cin >> len;

  for (int element = 0; element < len; ++element) {
    cout << "Enter " << element+1 << " number" << endl;
    cin >> number;
    numbers.push_back(number);
  }

  bubbleSort(numbers);

  for (int element = 0; element < numbers.size(); ++element) {
    cout << numbers[element] << " ";
  }
}