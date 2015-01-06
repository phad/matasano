#include <iostream>
#include <string>
#include <assert.h>

#include "hex.h"

using namespace std;

const char B64[] =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz"
    "0123456789+/";

string HexToB64(const string& hex) {
  cout << "In: " << hex << endl;
  string b64;
  int b = 0, p = 0;
  unsigned short byte = 0;
  for (int i = 0; i < hex.length(); i += 6) {
    byte = 16 * Hexit(hex[i]) + Hexit(hex[i + 1]);
    b = (byte & 0xfc) >> 2;
    b64 += B64[b];

    b = (byte & 0x03) << 4;
    byte = 16 * Hexit(hex[i + 2]) + Hexit(hex[i + 3]);
    b += (byte & 0xf0) >> 4;
    b64 += B64[b];

    b = (byte & 0x0f) << 2;
    byte = 16 * Hexit(hex[i + 4]) + Hexit(hex[i + 5]);
    b += (byte & 0xc0) >> 6;
    b64 += B64[b];

    b = byte & 0x3f;
    b64 += B64[b];
  }
  cout << "Out: " << b64 << endl;
  return b64;
}

int main(int argc, char** argv) {
  const string kIn = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
  const string kExpectedOut = "SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t";
  assert(kExpectedOut == HexToB64(kIn));
  return 0;
}

