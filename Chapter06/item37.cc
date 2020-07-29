#include <iostream>
#include <string>

class Shape {
public:
  enum Color {Red, Yellow, Blue};
  virtual void draw(Color c = Red) {
    switch(c) {
    case Red:
      std::cout << "Shape::Red" << std::endl;
      break;
    case Yellow:
      std::cout << "Shape::Yellow" << std::endl;
      break;
    case Blue:
      std::cout << "Shape::Blue" << std::endl;
      break;
    default:
      std::cout << "Shape : Illegal color" << std::endl;
      break;
    }
  }
};

class Circle : public Shape {
public:
  virtual void draw(Color c) {
    switch(c) {
    case Red:
      std::cout << "Circle::Red" << std::endl;
      break;
    case Yellow:
      std::cout << "Circle::Yellow" << std::endl;
      break;
    case Blue:
      std::cout << "Circle::Blue" << std::endl;
      break;
    default:
      std::cout << "Circle : Illegal color" << std::endl;
      break;
    }
  }
};

class Rectangle : public Shape {
public:
  virtual void draw(Color c = Blue) {
    switch(c) {
    case Red:
      std::cout << "Rectangle::Red" << std::endl;
      break;
    case Yellow:
      std::cout << "Rectangle::Yellow" << std::endl;
      break;
    case Blue:
      std::cout << "Rectangle::Blue" << std::endl;
      break;
    default:
      std::cout << "Rectangle : Illegal color" << std::endl;
      break;
    }
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
