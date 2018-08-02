#include "pkcs7.h"

#include <string>

using namespace std;

string Pkcs7Pad(const string& in, int block_size) {
  const int last_block_used(in.length() % block_size);
  if (last_block_used == 0) {
    return in;
  }
  const int num_pad_ch(block_size - last_block_used);
  string out(in);
  out.append(num_pad_ch, char(num_pad_ch));
  return out;
}

