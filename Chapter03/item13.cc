#include <iostream>
#include <memory>
#include <string>

class Investment {
  public:
    ~Investment() {
      std::cout << "Investment::~Investment()" << std::endl;
    }
};

Investment *createInvestment() {
  return new Investment;
}

void test() {
  std::shared_ptr<Investment> pInv(createInvestment());
}

int main() {
  test();
}
