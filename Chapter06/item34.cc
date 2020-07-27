#include <iostream>
#include <string>

class Shape {
public:
  // pure virtual, only defines interface
  virtual void draw() = 0;
  // impure virtual, the derived class can inherite interface and definition
  virtual void error(const std::string &msg);
  // non-virtual, invariant over specialization
  int objectId() const;
private:
  static int id;
};

void Shape::draw() { std::cout << "virtual void Shape::draw() = 0" << std::endl; }
void Shape::error(const std::string &msg) { (void)msg; std::cout << "virtual void Shape::error(const std::string &)" << std::endl; }
int Shape::objectId() const { return id++; }

int Shape::id = 0;

class Rectangle : public Shape {
public:
  virtual void draw() { std::cout << "virtual void Rectangle::draw()" << std::endl; }
};
class Eclipse : public Shape {
public:
  virtual void draw() override { std::cout << "virtual void Eclipse::draw()" << std::endl; }
};

class Airport {};
class Airplane {
public:
  virtual void fly() = 0;
protected:
  void defaultFly() { std::cout << "void Airplane::defaultFly()" << std::endl; }
};

void Airplane::fly() {
  std::cout << "virtual void Airplane::fly() = 0" << std::endl;
}
class PlaneA : public Airplane {
public:
  virtual void fly() override { /* std::cout << "virtual void PlaneA::fly()" << std::endl; defaultFly();*/
    Airplane::fly();
  }
};
class PlaneB : public Airplane {
public:
  virtual void fly() override { /*std::cout << "virtual void PlaneB::fly()" << std::endl; defaultFly();*/
    Airplane::fly();
  }
};
class PlaneC : public Airplane {
public:
  virtual void fly() override { std::cout << "virtual void PlaneC::fly()" << std::endl; }
};

void test1() {
  // cannot declare variable ‘sp’ to be of abstract type ‘Shape’
  //Shape sp;
  Rectangle rt;
  rt.draw();
  rt.error("test");
  std::cout << rt.objectId() << std::endl;

  Eclipse ec;
  ec.draw();
  ec.error("test");
  std::cout << ec.objectId() << std::endl;
}

void test2() {
  PlaneA pa;
  pa.fly();
  PlaneB pb;
  pb.fly();
  PlaneC pc;
  pc.fly();
}

int main() {
  test1();
  std::cout << "-----------------------" << std::endl;
  test2();
}
