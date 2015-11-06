#include "hamming.h"

#include <iostream>
#include <string>

#include <assert.h>

using namespace std;

int main(int argc, char **argv) {
  const string a("this is a test");
  const string b("wokka wokka!!!");
  const int distance(HammingDistance(a, b));
  cout << "Distance for [" << a << "] and [" << b << "] is "
       << distance << endl;
  assert(distance == 37);
  return 0;
}
 
