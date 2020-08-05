#include <iostream>
#include <string>

class Transaction {
public:
  Transaction() {
    std::cout << "this:" << this << " Transaction::Transaction()" << std::endl;
    logTransaction();
  }
  virtual void logTransaction() {
    std::cout << "this:" << this << " Transaction::logTransaction()" << std::endl;
  }
};

class BuyTransaction : public Transaction {
public:
  BuyTransaction() : Transaction() {}
  virtual void logTransaction() override {
    std::cout << "this:" << this << " BuyTransaction::logTransaction()" << std::endl;
  }
};

void test() {
  Transaction *t = new Transaction();
  Transaction *t1 = new BuyTransaction();
  delete t;
  delete t1;
  t = nullptr;
  t1 = nullptr;
}

int main() {
  test();
}
