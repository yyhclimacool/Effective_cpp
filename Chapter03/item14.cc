#include <iostream>
#include <memory>

class Mutex {
public:
  Mutex() { std::cout << "Mutex::Mutex()" << std::endl; }
  ~Mutex() { std::cout << "Mutex::~Mutex()" << std::endl; }
};

void lock(Mutex *m) {
  std::cout << "lock Mutex addr " << m << std::endl;
}

void unlock(Mutex *m) {
  std::cout << "unlock Mutex addr " << m << std::endl;
}

class Lock {
public:
  explicit Lock(Mutex &m) : m_(m) { lock(&m_); std::cout << "lock(&m)" << std::endl; }
  ~Lock() { unlock(&m_); std::cout << "unlock(&m)" << std::endl; }
private:
  Mutex &m_;
};

class LockShared {
public:
  explicit LockShared(Mutex &m) : pM(&m, unlock) {}
  // auto release with shared_ptr
private:
  std::shared_ptr<Mutex> pM;
};

void test() {
  Mutex m;
  Lock lk(m);
}

void test2() {
  Mutex m;
  LockShared ls(m);
}

int main() {
  test();
  test2();
}
