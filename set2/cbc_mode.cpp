#include <assert.h>
#include <string>

#include "cbc_mode.h"
#include "../util/xor.h"

using namespace std;

//template<typename DecFunc>
string cbc_decrypt(const string& input, const string& iv, int block_size, //DecFunc df) {
	               function<string(const string&)> df) {
  assert(iv.length() == block_size);
  string prev(iv);
  string output;

  for (int offset = 0; offset < input.size(); offset += block_size) {
    const string& iblock(input.substr(offset, block_size));
    const string oblock(df(Xor(iblock, prev)));
    prev = oblock;
    output += oblock;
  }

  return output;
}
