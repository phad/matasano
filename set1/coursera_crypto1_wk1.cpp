#include <iostream>
#include <string>
#include <vector>

#include "hex.h"
#include "xor.h"

using namespace std;

const char* kCipherTextHex1 =
    "315c4eeaa8b5f8aaf9174145bf43e1784b8fa00dc71d885a804e5ee9fa40b16349c146fb77"
    "8cdf2d3aff021dfff5b403b510d0d0455468aeb98622b137dae857553ccd8883a7bc37520e"
    "06e515d22c954eba5025b8cc57ee59418ce7dc6bc41556bdb36bbca3e8774301fbcaa3b83b"
    "220809560987815f65286764703de0f3d524400a19b159610b11ef3e";

const char* kCipherTextHex2 =
    "234c02ecbbfbafa3ed18510abd11fa724fcda2018a1a8342cf064bbde548b12b07df44ba71"
    "91d9606ef4081ffde5ad46a5069d9f7f543bedb9c861bf29c7e205132eda9382b0bc2c5c4b"
    "45f919cf3a9f1cb74151f6d551f4480c82b2cb24cc5b028aa76eb7b4ab24171ab3cdadb835"
    "6f";

const char* kCipherTextHex3 =
    "32510ba9a7b2bba9b8005d43a304b5714cc0bb0c8a34884dd91304b8ad40b62b07df44ba6e"
    "9d8a2368e51d04e0e7b207b70b9b8261112bacb6c866a232dfe257527dc29398f5f3251a0d"
    "47e503c66e935de81230b59b7afb5f41afa8d661cb";

const char* kCipherTextHex4 =
    "32510ba9aab2a8a4fd06414fb517b5605cc0aa0dc91a8908c2064ba8ad5ea06a029056f47a"
    "8ad3306ef5021eafe1ac01a81197847a5c68a1b78769a37bc8f4575432c198ccb4ef635902"
    "56e305cd3a9544ee4160ead45aef520489e7da7d835402bca670bda8eb775200b8dabbba24"
    "6b130f040d8ec6447e2c767f3d30ed81ea2e4c1404e1315a1010e7229be6636aaa";

const char* kCipherTextHex5 =
    "3f561ba9adb4b6ebec54424ba317b564418fac0dd35f8c08d31a1fe9e24fe56808c213f17c"
    "81d9607cee021dafe1e001b21ade877a5e68bea88d61b93ac5ee0d562e8e9582f5ef375f0a"
    "4ae20ed86e935de81230b59b73fb4302cd95d770c65b40aaa065f2a5e33a5a0bb5dcaba437"
    "22130f042f8ec85b7c2070";

const char* kCipherTextHex6 =
    "32510bfbacfbb9befd54415da243e1695ecabd58c519cd4bd2061bbde24eb76a19d84aba34"
    "d8de287be84d07e7e9a30ee714979c7e1123a8bd9822a33ecaf512472e8e8f8db3f9635c19"
    "49e640c621854eba0d79eccf52ff111284b4cc61d11902aebc66f2b2e436434eacc0aba938"
    "220b084800c2ca4e693522643573b2c4ce35050b0cf774201f0fe52ac9f26d71b6cf61a711"
    "cc229f77ace7aa88a2f19983122b11be87a59c355d25f8e4";

const char* kCipherTextHex7 =
    "32510bfbacfbb9befd54415da243e1695ecabd58c519cd4bd90f1fa6ea5ba47b01c909ba76"
    "96cf606ef40c04afe1ac0aa8148dd066592ded9f8774b529c7ea125d298e8883f5e9305f4b"
    "44f915cb2bd05af51373fd9b4af511039fa2d96f83414aaaf261bda2e97b170fb5cce2a53e"
    "675c154c0d9681596934777e2275b381ce2e40582afe67650b13e72287ff2270abcf73bb02"
    "8932836fbdecfecee0a3b894473c1bbeb6b4913a536ce4f9b13f1efff71ea313c8661dd9a4"
    "ce";

const char* kCipherTextHex8 =
    "315c4eeaa8b5f8bffd11155ea506b56041c6a00c8a08854dd21a4bbde54ce56801d943ba70"
    "8b8a3574f40c00fff9e00fa1439fd0654327a3bfc860b92f89ee04132ecb9298f5fd2d5e4b"
    "45e40ecc3b9d59e9417df7c95bba410e9aa2ca24c5474da2f276baa3ac325918b2daada43d"
    "6712150441c2e04f6565517f317da9d3";

const char* kCipherTextHex9 =
    "271946f9bbb2aeadec111841a81abc300ecaa01bd8069d5cc91005e9fe4aad6e04d513e96d"
    "99de2569bc5e50eeeca709b50a8a987f4264edb6896fb537d0a716132ddc938fb0f836480e"
    "06ed0fcd6e9759f40462f9cf57f4564186a2c1778f1543efa270bda5e933421cbe88a4a522"
    "22190f471e9bd15f652b653b7071aec59a2705081ffe72651d08f822c9ed6d76e48b63ab15"
    "d0208573a7eef027";

const char* kCipherTextHex10 =
    "466d06ece998b7a2fb1d464fed2ced7641ddaa3cc31c9941cf110abbf409ed39598005b339"
    "9ccfafb61d0315fca0a314be138a9f32503bedac8067f03adbf3575c3b8edc9ba7f5375305"
    "41ab0f9f3cd04ff50d66f1d559ba520e89a2cb2a83";

const char* kCipherTextHexTarget =
    "32510ba9babebbbefd001547a810e67149caee11d945cd7fc81a05e9f85aac650e9052ba6a"
    "8cd8257bf14d13e6f0a803b54fde9e77472dbff89d71b57bddef121336cb85ccb8f3315f4b"
    "52e301d16e9f52f904";

const char* kAllCipherTextsHex[] = {
    kCipherTextHex1, kCipherTextHex2, kCipherTextHex3, kCipherTextHex4,
    kCipherTextHex5, kCipherTextHex6, kCipherTextHex7, kCipherTextHex8,
    kCipherTextHex9, kCipherTextHex10, kCipherTextHexTarget
};

const int kNumCipherTexts = 11;

string ByteSeparatedToHex(const string& octets) {
  string hex = ToHex(octets);
  string output;
  for (int idx = 0; idx < hex.length(); idx += 2) {
    output += hex.substr(idx, 2);
    output += " ";
  }
  return output;
}

string HexDump(const string& octets) {
  string hex = ToHex(octets);
  string output;
  for (int idx = 0; idx < hex.length(); idx += 2) {
    string octet = hex.substr(idx, 2);
    unsigned short ch = FromHex(octet)[0];
    if (ch < 0x20 || ch > 0x7e) {
      output += ".";
    } else {
      output += (unsigned char)ch;
    }
  }
  return output;
}

string LikelyAlphaOrSpace(const string& octets) {
  string hex = ToHex(octets);
  string output;
  for (int idx = 0; idx < hex.length(); idx += 2) {
    string octet = hex.substr(idx, 2);
    unsigned short ch = FromHex(octet)[0];
    if (ch <= 0xb) {
      output += "Aa";
    } else if (ch >= 0x41 && ch <= 0x7a) {
      output += "sp"; 
    } else {
      output += ". ";
    }
    output += " ";
  }
  return output;
}

int main(int argc, char** argv) {
  string crib;
  if (argc == 2) {
    crib = string(argv[1]);
    cout << "Using crib: " << crib << endl;
  }
  // Find shortest ciphertext, we'll take that prefix of all.
  int shortest = 9999;
  for (int idx = 0; idx < kNumCipherTexts; ++idx) {
    string ciphertext(kAllCipherTextsHex[idx]);
    if (ciphertext.length() < shortest) {
      shortest = ciphertext.length();
    }
  }

  // Truncated all ciphertexts to the length of the shortest so we can XOR them
  // all.
  vector<string> ciphertexts;
  for (int idx = 0; idx < kNumCipherTexts; ++idx) {
    string truncated_ciphertext = string(kAllCipherTextsHex[idx]).substr(0, shortest);
    ciphertexts.push_back(FromHex(truncated_ciphertext));
  }

  // Pair-wise XOR of all pairs.
  for (int count1 = 0; count1 < kNumCipherTexts - 1; ++count1) {
    for (int count2 = count1 + 1; count2 < kNumCipherTexts; ++count2) {
      string xored = Xor(ciphertexts[count1], ciphertexts[count2]);
      cout << "CT" << 1 + count1 << " ^ CT" << 1 + count2;
      if (1 + count1 < 10) cout << " ";
      if (1 + count2 < 10) cout << " ";
      cout << ": " << ByteSeparatedToHex(xored) << endl;
      cout << "           : " << LikelyAlphaOrSpace(xored) << endl;
    }
  }

  // Output CT11, which we need to decrypt.
  cout << " Target CT : " << ByteSeparatedToHex(ciphertexts[10]) << endl;

  // If no crib, then we're done.
  if (crib.empty()) {
    return 0;
  }

  crib.resize(ciphertexts[0].length(), ' ');
  string key = Xor(crib, ciphertexts[10]);
  cout << "       Key : " << ByteSeparatedToHex(key) << endl;
  for (int idx = 0; idx < kNumCipherTexts; ++idx) {
    string plaintext = Xor(key, ciphertexts[idx]);
    cout << " Cand. PT" << 1 + idx;
    if (1 + idx < 10) cout << " ";
    cout << ": " << HexDump(plaintext) << endl;
  }
}

