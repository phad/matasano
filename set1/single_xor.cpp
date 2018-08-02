#include <iostream>
#include <string>

#include <assert.h>

#include "../util/hex.h"
#include "../util/xor.h"

#include "single_xor.h"

using namespace std;

float attemptDecrypt(const string& ciphertext, unsigned short k, string* plaintext) {
  assert(plaintext != NULL);
  assert(ciphertext.length() > 0);

  *plaintext = SingleKeyXor(ciphertext, k);

  int etaspCount = 0;
  for (string::iterator it = plaintext->begin(); it != plaintext->end(); ++it) {
    if (*it == ' ' || *it == 'e' || *it == 'E' || *it == 't' || *it == 'T' || *it == 'a' || *it == 'A')
      ++etaspCount;
  }

  return etaspCount * 1.0 / ciphertext.length();
}

float attemptDecrypt(const string& ciphertext, string* plaintext, char* key) {
  float bestScore = 0.0;
  for (unsigned short k = 0x0; k <= 0xff; ++k) {
    string candidate;
    float score = attemptDecrypt(ciphertext, k, &candidate);
//    cout << " key: " << k << ", score: " << score << ", cand: "
//         << candidate.substr(0, 32) << endl;
    if (score > bestScore) {
      bestScore = score;
      *key = (char)k;
      *plaintext = candidate;
    }
  }
  return bestScore;
}

