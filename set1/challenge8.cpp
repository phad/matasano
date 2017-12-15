#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "ecb_detect.h"
#include "hex.h"

const int kBlockSize = 16;

using namespace std;

int main(int argc, char **argv) {
  ifstream inputFile("8.txt");
  vector<string> ciphertexts;
  string ciphertexthex;
  while (inputFile >> ciphertexthex) {
    const string ciphertext(FromHex(ciphertexthex));
    ciphertexts.push_back(ciphertext);
  }

  int index = 0;
  for (vector<string>::iterator it = ciphertexts.begin();
       it != ciphertexts.end(); ++it, ++index) {
    const string& ciphertext(*it);
    if (is_likely_ecb(ciphertext, kBlockSize)) {
      cout << "Detected ECB for cipher text with index: " << index << endl;
      cout << "Ciphertext was: [" << ToHex(ciphertext) << "]" << endl;
      break;
    }
  }
  return 0;
}

