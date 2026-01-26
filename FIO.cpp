#include <iostream>
#include <string> 
#include <vector>
using namespace std;

vector <string> split(string str) {
  int oldPos = 0;
  int pos = 0;
  vector <string> lines;
  
  while (pos < str.length()) {
    pos = str.find(' ', pos + 1) + 1;
    if (pos <= 0) {
      string delta = str.substr(oldPos, pos - oldPos - 1);
      lines.push_back(delta);
      break;
    } else {
      string delta = str.substr(oldPos, pos - oldPos - 1);
      lines.push_back(delta);
      oldPos = pos;
    }
  }
  return lines;
}

int main() {
  string str = "";
  cout << "Enter strings with whitespaces:" << endl;
  
  getline(cin, str);
  vector<string> lines = split(str);
  
  string FIO = lines[0] + " " + lines[1][0] + ". " + lines[2][0] + ".";
  cout << FIO << endl;
}
