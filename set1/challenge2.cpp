#include <iostream>
#include <string>
#include <assert.h>

#include "hex.h"

using namespace std;

string BufferXor(const string& a, const string& b) {
  cout << "In 1: " << a << endl << "In 2: " << b << endl;
  assert(a.length() == b.length());
  string result;
  for (int i = 0; i < a.length(); ++i) {
    unsigned short r = Hexit(a[i]) ^ Hexit(b[i]);
    result += (r < 10 ? (r + '0') : (r - 10 + 'a'));
  }
  cout << "Out:  " << result << endl;
  return result;
}

int main(int argc, char** argv) {
  const string kIn1 = "1c0111001f010100061a024b53535009181c";
  const string kIn2 = "686974207468652062756c6c277320657965";
  const string kExpectedOut = "746865206b696420646f6e277420706c6179";
  assert(kExpectedOut == BufferXor(kIn1, kIn2));
  return 0;
}
