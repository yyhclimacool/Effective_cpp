#include <iostream>

class UnCopyable {
public:
  UnCopyable() = default;
  ~UnCopyable() = default;
  UnCopyable(const UnCopyable &) = delete;
  UnCopyable &operator=(const UnCopyable &) = delete;
};

class HomeForSale : private UnCopyable {
  friend void test();
public:
  HomeForSale() : home_id_(0) {}
  HomeForSale(int id) : home_id_(id) {}
  int getid() const { return home_id_; }
private:
  int home_id_;
};

void test() {
  HomeForSale h1(10);
  HomeForSale h2(42);
  
  //HomeForSale h3(h1);
  //h3 = h2;
}

int main() {
  test();
}
