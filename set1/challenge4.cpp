#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "hex.h"
#include "single_xor.h"

using namespace std;

int main(int argc, char **argv) {
  ifstream inputFile("4.txt");
  vector<string> ciphertexts;
  string ciphertexthex;
  while (inputFile >> ciphertexthex) {
    ciphertexts.push_back(FromHex(ciphertexthex));
  }

  string bestPlaintext;
  float bestScore = 0.0;
  for (vector<string>::iterator it = ciphertexts.begin(); it != ciphertexts.end(); ++it) {
    string plaintext;
    char key;
    float score = attemptDecrypt(*it, &plaintext, &key);
    if (score > bestScore) {
      bestPlaintext = plaintext;
      bestScore = score;
    }
  }

  cout << "Found plaintext: " << bestPlaintext << endl;
}

