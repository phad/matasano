#include <iostream>
#include <string>

#include "xor.h"

using namespace std;

int main(int argc, char** argv) {
  if (argc < 2) {
    cerr << "Usage: vigenere key [plaintext]" << endl;
    return 1;
  }
  string key(argv[1]);
  string plaintext;
  if (argc == 3) {
    plaintext = string(argv[2]);
  } else {
    for (string line; getline(cin, line); ) {
      plaintext += line;
    }
  }

  string ciphertext = RepeatingKeyXor(plaintext, key);
  cout << ciphertext << endl;
  return 0;
}

