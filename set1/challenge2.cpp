#include <iostream>
#include <string>
#include <assert.h>

#include "hex.h"
#include "../util/xor.h"

using namespace std;

int main(int argc, char** argv) {
  const string kIn1 = "1c0111001f010100061a024b53535009181c";
  const string kIn2 = "686974207468652062756c6c277320657965";
  const string kExpectedOut = "746865206b696420646f6e277420706c6179";
  const string in1 = FromHex(kIn1);
  const string in2 = FromHex(kIn2);
  const string result = Xor(in1, in2);
  const string out = ToHex(result);
  assert(kExpectedOut == out);
  return 0;
}
