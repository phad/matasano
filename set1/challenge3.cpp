#include <iostream>
#include <string>

#include <assert.h>

#include "hex.h"
#include "xor.h"

using namespace std;

float attemptDecrypt(const string& ciphertext, unsigned short k, string* plaintext) {
  assert(plaintext != NULL);
  assert(ciphertext.length() > 0);

  string key;
  key.resize(ciphertext.length(), (char)k);
  *plaintext = Xor(ciphertext, key);

  int etaspCount = 0;
  for (string::iterator it = plaintext->begin(); it != plaintext->end(); ++it) {
    if (*it == ' ' || *it == 'e' || *it == 'E' || *it == 't' || *it == 'T' || *it == 'a' || *it == 'A')
      ++etaspCount;
  }

  return etaspCount * 1.0 / ciphertext.length();
}

int main(int argc, char** argv) {
  const string kCipherText =
      "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736";      
  string ciphertext = FromHex(kCipherText);
  assert(ciphertext.length() == kCipherText.length() / 2);
  string plaintext;
  float bestScore = 0.0;
  char bestKey;
  for (unsigned short k = 0x0; k <= 0xff; ++k) {
    string candidate;
    float score = attemptDecrypt(ciphertext, k, &candidate);
    if (score > bestScore) {
      bestScore = score;
      bestKey = (char)k;
      plaintext = candidate;
    }
  }
  cout << "Highest scoring plaintext = " << plaintext << endl;
  cout << "Encrypted with key " << bestKey << " which scored " << bestScore << endl;
  return 0;
}

