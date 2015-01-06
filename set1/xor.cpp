#include <string>
#include <assert.h>

#include "hex.h"
#include "xor.h"

using namespace std;

string Xor(const string& a, const string& b) {
  assert(a.length() == b.length());
  string result;
  for (int i = 0; i < a.length(); ++i) {
    char r = (char)a[i] ^ (char)b[i];
    result += r;
  }
  assert(result.length() == a.length());
  return result;
}

string SingleKeyXor(const string& a, unsigned short k) {
  string key;
  key.resize(a.length(), (char)k);
  return Xor(a, key);
}

string RepeatingKeyXor(const string& a, const string& k) {
  assert(k.length() > 0 && a.length() > k.length());
  string key;
  for (int i = 0; i < 1 + a.length() / k.length(); ++i, key += k)
    ;
  key.resize(a.length());
  return Xor(a, key);
}

