#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

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
    map<string, int> block_counts;
    for (int offset = 0; offset < ciphertext.size(); offset += kBlockSize) {
      const string& block(ciphertext.substr(offset, kBlockSize));
      block_counts[block]++;
    }
    bool stop(false);
    for (map<string, int>::const_iterator it = block_counts.begin();
         it != block_counts.end(); ++it) {
      stop |= (it->second > 1);
    }
    if (stop) {
      cout << "Detected ECB for cipher text with index: " << index << endl;
      cout << "Ciphertext was: [" << ToHex(ciphertext) << "]" << endl;
      break;
    }
  }
  return 0;
}

