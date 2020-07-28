#include <iostream>
#include <string>
#include <functional>

class GameCharacter {
public:
  // non-virtual function
  // Template method: non-virtual interface, NVI
  int healthValue() const {
    std::cout << "int GameCharacter::healthValue() const" << std::endl;
    return doHealthValue();
  }
private:
  virtual int doHealthValue() const {
    std::cout << "virtual int GameCharacter::doHealthValue() const" << std::endl; 
  }
};

class Soldier : public GameCharacter {
private:
  virtual int doHealthValue() const {
    std::cout << "virtual int Soldier::doHealthValue() const" << std::endl;
  }
};

class Goblin : public GameCharacter {
private:
  virtual int doHealthValue() const {
    std::cout << "virtual int Goblin::doHealthValue() const" << std::endl;
  }
};

void test1() {
  Soldier sd;
  sd.healthValue();
}

class GameCharacterBase;
int healthCalcFunc(const GameCharacterBase &) {
  std::cout << "::healthCalcFunc(const GameCharacterBase &)" << std::endl;
  return 42;
}
int lowHealthLose(const GameCharacterBase &) {
  std::cout << "::lowHealthLose(const GameCharacterBase &)" << std::endl;
  return 45;
}
class GameCharacterBase {
public:
  using healthFunc = std::function<int(const GameCharacterBase &)>;
  explicit GameCharacterBase(healthFunc f = healthCalcFunc) : func_(f) {}
  ~GameCharacterBase() = default;
  int healthValue() const {
    return func_(*this);
  }
private:
  healthFunc func_;
};

class BadGuy : public GameCharacterBase {
public:
  explicit BadGuy(healthFunc f = healthCalcFunc) : GameCharacterBase(f) {}
private:
};

void test2() {
  BadGuy bg1;
  bg1.healthValue();
  BadGuy bg2(lowHealthLose);
  bg2.healthValue();
}

int main() {
  test1();
  test2();
}
