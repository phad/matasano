#include <string>
#include <assert.h>

#include "../util/hex.h"
#include "../util/xor.h"

using namespace std;

int main(int argc, char** argv) {
  const string kPlainText =
      "Burning 'em, if you ain't quick and nimble\n"
      "I go crazy when I hear a cymbal";
  const string kExpectedCipherTextHex =
      "0b3637272a2b2e63622c2e69692a23693a2a3c6324202d623d63343c2a26226324272765"
      "272a282b2f20430a652e2c652a3124333a653e2b2027630c692b20283165286326302e27"
      "282f";
  const string kKey = "ICE";
  string ciphertexthex = ToHex(RepeatingKeyXor(kPlainText, kKey));
  assert(kExpectedCipherTextHex == ciphertexthex);
  return 0;
}

