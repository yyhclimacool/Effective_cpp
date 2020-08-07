#include <iostream>

typedef std::string Address[4];

void test() {
  std::string *p = new Address;
  p[0] = "a";
  p[1] = "an";
  p[2] = "the";
  p[3] = "fine";

  std::cout << p[3] << std::endl;
  delete [] p;
}

int main() {
  test();
}
