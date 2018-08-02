// $ g++ challenge10.o cbc_mode.o xor.o hex.o -lssl -lcrypto -o challenge10
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include <openssl/aes.h>

#include "cbc_mode.h"

using namespace std;
using namespace std::placeholders;

const int block_size = 16;

string decrypt(const string& ciphertext, const string& key) {
  AES_KEY dec_key;
  AES_set_decrypt_key((const unsigned char*)key.c_str(), 128, &dec_key);
  unsigned char decrypted[block_size];
  AES_decrypt((const unsigned char*)ciphertext.c_str(),
              decrypted, &dec_key);
  return string((const char*)decrypted, block_size);
}

int main(int argc, char **argv) {
  ifstream file("10.bin", ios::in | ios::binary | ios::ate);
  if (!file.is_open()) {
    cerr << "Couldn't open 10.bin" << endl;
    return -1;
  }

  streampos size(file.tellg());
  char* buffer(new char[size]);
  file.seekg(0, ios::beg);
  file.read(buffer, size);
  file.close();

  string ciphertext(buffer, size);
  delete [] buffer;

  const string key("YELLOW SUBMARINE");
  const string iv(block_size, char('\000')); 

  const string plaintext(cbc_decrypt(ciphertext, iv, block_size,
                                     bind(&decrypt, _1, key)));

  cout << "Found plaintext: " << endl << plaintext << endl;
  return 0;
}
