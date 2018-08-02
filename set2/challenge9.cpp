#include <iostream>
#include <string>
#include <vector>

#include "pkcs7.h"

using namespace std;

struct Test {
  string in;
  int pad_len;
  string want_out;
};

void TestPkcs7() {
  const vector<Test> tests({
    {"", 16, ""},
    {"no padding needs", 16, "no padding needs"},
    {"short of a few", 16, "short of a few\002\002"},
    {"short by most chs", 16, "short by most chs\017\017\017\017\017\017\017"
                                           "\017\017\017\017\017\017\017\017"},
    {"just over", 8, "just over\007\007\007\007\007\007\007"}
  });

  for (const auto& t : tests) {
    const string got(Pkcs7Pad(t.in, t.pad_len));
    if (got != t.want_out) {
      cerr << "Fail: got '" << got << "' want '" << t.want_out << "'";
    }
  }
}
int main(int argc, char **argv) {
  TestPkcs7();
  return 0;
}

