#ifndef XOR_H
#define XOR_H

#include <string>
#include <assert.h>

#include "hex.h"

using namespace std;

string Xor(const string& a, const string& b) {
  assert(a.length() == b.length());
  string result;
  for (int i = 0; i < a.length(); ++i) {
    char r = (char)a[i] ^ (char)b[i];
    result += r;
  }
  return result;
}

#endif

