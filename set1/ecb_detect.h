#ifndef ECB_DETECT_H
#define ECB_DETECT_H

#include <map>
#include <string>

bool is_likely_ecb(const string& ciphertext, int block_size) {
  std::map<string, int> block_counts;
  for (int offset = 0; offset < ciphertext.size(); offset += block_size) {
    const string& block(ciphertext.substr(offset, block_size));
    block_counts[block]++;
  }
  int num_duplicate_blocks(0);
  for (std::map<string, int>::const_iterator it = block_counts.begin();
       it != block_counts.end(); ++it) {
     num_duplicate_blocks += (it->second > 1) ? 1 : 0;
  }
  return num_duplicate_blocks > 0;
}

#endif  // ECB_DETECT_H

