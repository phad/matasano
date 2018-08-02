#ifndef CBC_MODE_H
#define CBC_MODE_H

#include <functional>
#include <string>
 
std::string cbc_decrypt(const std::string& input, const std::string& iv, int block_size,
                        std::function<std::string(const std::string&)> df);


//template<typename DecFunc> 
//std::string cbc_decrypt(const std::string& input, const std::string& iv,
//	                    int block_size, DecFunc df);

#endif  // CBC_MODE_H

