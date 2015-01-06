#ifndef HEXIT_H
#define HEXIT_H

#include <assert.h>

unsigned short Hexit(char ch) {
  if (ch >= '0' && ch <= '9') {
    return (unsigned short)(ch - '0');
  } else if (ch >= 'A' && ch <= 'F') {
    return 10 + (unsigned short)(ch - 'A');
  } else if (ch >= 'a' && ch <= 'f') {
    return 10 + (unsigned short)(ch - 'a');
  }
  assert(false);
}

#endif

