#ifndef XOR_H
#define XOR_H

#include <string>

// length(a) == length(b)
std::string Xor(const std::string& a, const std::string& b);

std::string SingleKeyXor(const std::string& a, unsigned short key);

std::string RepeatingKeyXor(const std::string& a, const std::string& key);

#endif

