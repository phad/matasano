#include <iostream>
#include <string>

#include <assert.h>

#include "hex.h"
#include "single_xor.h"

using namespace std;

int main(int argc, char** argv) {
  const string kCipherText =
      "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736";      
  string ciphertext = FromHex(kCipherText);
  assert(ciphertext.length() == kCipherText.length() / 2);
  string plaintext;
  char bestKey;
  float bestScore = attemptDecrypt(ciphertext, &plaintext, &bestKey);
  cout << "Highest scoring plaintext = " << plaintext << endl;
  cout << "Encrypted with key " << bestKey << " which scored " << bestScore << endl;
  return 0;
}

