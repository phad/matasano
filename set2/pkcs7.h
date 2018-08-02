#ifndef PKCS7_H
#define PKCS7_H

#include <string>

std::string Pkcs7Pad(const std::string& in, int pad_len);

#endif  // PKCS7_H

