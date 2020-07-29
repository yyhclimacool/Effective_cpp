#include <iostream>
#include <string>

class Shape {
public:
  enum Color {Red, Yellow, Blue};
  void doDraw(Color c) {
    switch(c) {
    case Red:
      std::cout << "Red" << std::endl;
      break;
    case Yellow:
      std::cout << "Yellow" << std::endl;
      break;
    case Blue:
      std::cout << "Blue" << std::endl;
      break;
    default:
      std::cout << "Illegal color" << std::endl;
      break;
    }
  }
  virtual void draw(Color c = Red) {
    doDraw(c);
  }
};

class Circle : public Shape {
public:
  virtual void draw(Color c) {
    doDraw(c);
  }
};

class Rectangle : public Shape {
public:
  // Do NOT overwrite default parameter
  virtual void draw(Color c = Blue) {
    doDraw(c);
  }
};

void test() {
  Shape *ps;
  Shape *pr = new Rectangle;
  Shape *pc = new Circle;

  pr->draw();
  pc->draw();
}

int main() {
  test();
}
