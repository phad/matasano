#ifndef _HAMMING_H_
#define _HAMMING_H_

#include <string>
#include <assert.h>

int HammingDistance(const std::string& a, const std::string& b) {
  assert(a.length() == b.length());
  int distance = 0;
  for (int pos = 0; pos < a.length(); ++pos) {
    const char cha = a[pos];
    const char chb = b[pos];
    char chx = cha ^ chb;
    while (chx) {
      chx &= chx - 1;
      ++distance;
    }
  }
  return distance;
}

#endif  // _HAMMING_H_
