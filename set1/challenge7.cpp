#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include <openssl/aes.h>

using namespace std;

string decrypt(const string& ciphertext, const string& key) {
  AES_KEY dec_key;
  AES_set_decrypt_key((const unsigned char*)key.c_str(), 128, &dec_key);
  unsigned char decrypted[16];
  AES_decrypt((const unsigned char*)ciphertext.c_str(),
              decrypted, &dec_key);
  return string((const char*)decrypted, 16);
}

int main(int argc, char **argv) {
  ifstream file("7.bin", ios::in | ios::binary | ios::ate);
  if (!file.is_open()) {
    cerr << "Couldn't open 7.bin" << endl;
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
  string plaintext;
  for (int offset = 0; offset < ciphertext.size(); offset += key.length()) {
    const string& block(ciphertext.substr(offset, key.length()));
    const string block_plaintext(decrypt(block, key));
    plaintext += block_plaintext;
  }

  cout << "Found plaintext: " << endl << plaintext << endl;
}

