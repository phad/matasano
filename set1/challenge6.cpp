#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "hamming.h"
#include "hex.h"
#include "single_xor.h"

using namespace std;

bool ByIncreasingDistance(
    const pair<int, float>& left,
    const pair<int, float>& right) {
  return left.second < right.second;
}

int main(int argc, char **argv) {
  ifstream file("6.bin", ios::in | ios::binary | ios::ate);
  if (!file.is_open()) {
    cerr << "Couldn't open 6.bin" << endl;
    return -1;
  }

  streampos size(file.tellg());
  char* buffer(new char[size]);
  file.seekg(0, ios::beg);
  file.read(buffer, size);
  file.close();

  string ciphertext(buffer, size);
  delete [] buffer;

  cout << "Ciphertext length: " << ciphertext.length() << endl << endl;

  vector<pair<int, float> > distances_for_key_size;
  for (int key_size = 2; key_size <= 40; ++key_size) {
    int overall_distance(0);
    const int num_blocks(4);
    for (int block = 0; block < num_blocks; ++block) {
      const int offset(block * key_size * 2);
      const string a(ciphertext.substr(offset, key_size));
      const string b(ciphertext.substr(offset + key_size, key_size));
      const int distance(HammingDistance(a, b));
      overall_distance += distance;
    }
    float normalized_distance = 1.0 * overall_distance / (1.0 * num_blocks * key_size);
    distances_for_key_size.push_back(make_pair(key_size, normalized_distance));
  }

  sort(distances_for_key_size.begin(), distances_for_key_size.end(),
       ByIncreasingDistance);

  for (int attempt = 0; attempt < 5; ++attempt) {
    const int key_size(distances_for_key_size[attempt].first);
    const float distance(distances_for_key_size[attempt].second);

    cout << "Trying key size: " << key_size << " for distance: "
         << distance << endl;

    string key;

    string* slices(new string[key_size]);
    for (int i = 0; i < ciphertext.length(); ++i) {
      slices[i % key_size] += ciphertext[i];
    }

    string* decrypted_slices(new string[key_size]);
    for (int j = 0; j < key_size; ++j) {
      string* plaintext(&decrypted_slices[j]);
      char k;
      float score = attemptDecrypt(slices[j], plaintext, &k);
      key += k;
    }

    cout << "Decrypt follows; key = [" << key << "]" << endl;
    for (int i = 0; i < ciphertext.length(); ++i) {
      const string& slice(decrypted_slices[i % key_size]);
      cout << slice[i / key_size];
    }
    cout << endl << endl << endl;

    delete [] slices;
    delete [] decrypted_slices;
  }
  return 0;
}

