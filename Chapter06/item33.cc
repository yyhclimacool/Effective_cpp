#include <iostream>

class Base {
public:
  virtual void mf1() { std::cout << "Base::mf1()" << std::endl; }
  virtual void mf1(int) { std::cout << "Base::mf1(int)" << std::endl; }
  virtual void mf2() { std::cout << "Base::mf2()" << std::endl; }
  void mf3() { std::cout << "Base::mf3()" << std::endl; }
  void mf3(double) { std::cout << "Base::mf3(double)" << std::endl; }
private:
  int x;
};

class Derived : public Base {
public:
  //using Base::mf1;
  using Base::mf3;
  // hiding Base::mf1() and Base::mf1(int)
  virtual void mf1() { std::cout << "Derived::mf1()" << std::endl; Base::mf1(); }

  // hiding Base::mf3() and Base::mf3(double)
  void mf3() { std::cout << "Derived::mf3()" << std::endl; }

  void mf4() { std::cout << "Derived::mf4()" << std::endl; }
private:

};

void Test1() {
  Base b;
  Derived d;

  b.mf1();
  b.mf1(42);
  b.mf2();
  b.mf3();
  b.mf3(1.24);

  d.mf1();
  // error
  //d.mf1(42);
  d.mf2();
  d.mf3();
  // error
  //d.mf3(1.24);
  d.mf4();
}

void Test2() {
  Base b;
  Derived d;

  b.mf1();
  b.mf1(42);
  b.mf2();
  b.mf3();
  b.mf3(1.24);

  d.mf1();
  //d.mf1(42);
  d.mf2();
  d.mf3();
  d.mf3(1.24);
  d.mf4();
}

int main() {
  Test1();
  Test2();
}
