#ifndef XOR_H
#define XOR_H

#include <string>
#include <assert.h>

#include "hex.h"

std::string Xor(const std::string& a, const std::string& b) {
  assert(a.length() == b.length());
  std::string result;
  for (int i = 0; i < a.length(); ++i) {
    char r = (char)a[i] ^ (char)b[i];
    result += r;
  }
  assert(result.length() == a.length());
  return result;
}

#endif

