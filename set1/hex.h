#ifndef HEXIT_H
#define HEXIT_H

#include <iostream>
#include <string>

#include <assert.h>

unsigned short Hexit(char ch) {
  if (ch >= '0' && ch <= '9') {
    return (unsigned short)(ch - '0');
  } else if (ch >= 'A' && ch <= 'F') {
    return 10 + (unsigned short)(ch - 'A');
  } else if (ch >= 'a' && ch <= 'f') {
    return 10 + (unsigned short)(ch - 'a');
  }
  std::cerr << "oops, Hexit didn't like ch=" << ch << "(" << (unsigned short)ch << ")" << std::endl;
  assert(false);
}

std::string FromHex(const std::string& hex) {
  assert((hex.length() & 1) == 0);
  std::string result;
  for (int i = 0; i < hex.length(); i += 2) {
    unsigned short byte = 16 * Hexit(hex[i]) + Hexit(hex[i + 1]);
    result += (char)byte;
  }
  return result;
}

std::string ToHex(const std::string& buffer) {
  std::string result;
  for (std::string::const_iterator it = buffer.begin(); it != buffer.end(); ++it) {
    unsigned short nybble = (*it) >> 4;
    result += (nybble < 10 ? ('0' + nybble) : ('a' + nybble - 10));

    nybble = (*it) & 0x0f;
    result += (nybble < 10 ? ('0' + nybble) : ('a' + nybble - 10));
  }
  return result;
}

#endif
