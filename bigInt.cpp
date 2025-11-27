#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class bigInt {
private:
  string digits;
  bool negative;     

  // Удаление ведущих нулей
  static void trim(string& s) {
    while (s.size() > 1 && s[0] == '0') s.erase(0, 1);
  }

  // Сравнение модулей
  static bool absLess(const string& a, const string& b) {
    if (a.size() != b.size()) return a.size() < b.size();
    return a < b;
  }

  // Сложение модулей
  static string addAbs(const string& a, const string& b) {
    string A = a, B = b;
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());
    string res;

    int carry = 0;
    for (size_t i = 0; i < max(A.size(), B.size()); ++i) {
      int x = (i < A.size() ? A[i] - '0' : 0);
      int y = (i < B.size() ? B[i] - '0' : 0);
      int sum = x + y + carry;
      carry = sum / 10;
      res.push_back(char('0' + sum % 10));
    }
    if (carry) res.push_back(char('0' + carry));

    reverse(res.begin(), res.end());
    return res;
  }

  // Вычитание модулей
  static string subAbs(const string& a, const string& b) {
    string A = a, B = b;
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());
    string res;

    int carry = 0;
    for (size_t i = 0; i < A.size(); ++i) {
      int x = A[i] - '0';
      int y = (i < B.size() ? B[i] - '0' : 0);
      int diff = x - y - carry;
      if (diff < 0) {
        diff += 10;
        carry = 1;
      }
      else carry = 0;
      res.push_back(char('0' + diff));
    }

    while (res.size() > 1 && res.back() == '0') res.pop_back();
    reverse(res.begin(), res.end());
    return res;
  }

public:
  // Конструкторы
  bigInt(long long x = 0) {
    negative = (x < 0);
    if (x < 0) x = -x;
    digits = to_string(x);
  }

  bigInt(const string& s) {
    if (s[0] == '-') {
      negative = true;
      digits = s.substr(1);
    }
    else {
      negative = false;
      digits = s;
    }
    trim(digits);
  }

  // Вывод
  friend ostream& operator<<(ostream& out, const bigInt& n) {
    if (n.negative && n.digits != "0") out << "-";
    out << n.digits;
    return out;
  }

  // Ввод
  friend istream& operator>>(istream& in, bigInt& n) {
    string s;
    in >> s;
    n = bigInt(s);
    return in;
  }

  // Сравнение
  bool operator<(const bigInt& b) const {
    if (negative != b.negative) return negative;
    if (!negative)
      return absLess(digits, b.digits);
    else
      return absLess(b.digits, digits);
  }

  bool operator>(const bigInt& b) const { return b < *this; }
  bool operator==(const bigInt& b) const { return negative == b.negative && digits == b.digits; }

  // Сложение
  bigInt operator+(const bigInt& b) const {
    if (negative == b.negative) {
      bigInt r;
      r.negative = negative;
      r.digits = addAbs(digits, b.digits);
      return r;
    }

    // Разные знаки, вычитание модулей
    if (!absLess(digits, b.digits)) {
      bigInt r;
      r.negative = negative;
      r.digits = subAbs(digits, b.digits);
      return r;
    }
    else {
      bigInt r;
      r.negative = b.negative;
      r.digits = subAbs(b.digits, digits);
      return r;
    }
  }

  // Вычитание
  bigInt operator-(const bigInt& b) const {
    bigInt nb = b;
    nb.negative = !b.negative;
    return *this + nb;
  }

  // Умножение
  bigInt operator*(const bigInt& b) const {
    string A = digits, B = b.digits;
    vector<int> res(A.size() + B.size(), 0);

    for (int i = A.size() - 1; i >= 0; --i) {
      for (int j = B.size() - 1; j >= 0; --j) {
        int mul = (A[i] - '0') * (B[j] - '0');
        int sum = res[i + j + 1] + mul;
        res[i + j + 1] = sum % 10;
        res[i + j] += sum / 10;
      }
    }

    string s;
    for (int x : res) s.push_back(char('0' + x));
    trim(s);

    bigInt r;
    r.digits = s;
    r.negative = negative != b.negative && s != "0";
    return r;
  }

  // Целочисленное деление
  bigInt operator/(const bigInt& b) const {
    if (b.digits == "0") throw runtime_error("Division by zero");

    bigInt divisor = b;
    divisor.negative = false;

    bigInt cur = 0;
    bigInt result = 0;
    result.digits.clear();

    for (char c : digits) {
      cur = cur * 10 + bigInt(c - '0');
      int x = 0;
      while (!(cur < divisor)) {
        cur = cur - divisor;
        x++;
      }
      result.digits.push_back('0' + x);
    }

    trim(result.digits);
    result.negative = (negative != b.negative) && result.digits != "0";
    return result;
  }
};

int main() {
  bigInt a, b;
  cout << "Enter two numbers:\n";
  cin >> a >> b;

  cout << "a + b = " << (a + b) << "\n";
  cout << "a - b = " << (a - b) << "\n";
  cout << "a * b = " << (a * b) << "\n";
  cout << "a / b = " << (a / b) << "\n";

  cout << "a > b = " << (a > b) << "\n";
  cout << "a < b = " << (a < b) << "\n";
  cout << "a == b = " << (a == b) << "\n";

  return 0;
}
