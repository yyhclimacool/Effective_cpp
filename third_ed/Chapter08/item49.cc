#include <new>
#include <memory>
#include <iostream>
#include <string>

static const unsigned long long SZ = 1000000000000000000;

void oom() {
  std::cerr << "Out of memory! program abort!" << std::endl;
  std::abort();
}

void test_set_new_handler() {
  std::set_new_handler(oom);
  int *p = new int[SZ];
}

class NewHandlerHolder {
public:
  explicit NewHandlerHolder(std::new_handler nh) : p(nh) { std::cout << __func__ << std::endl; }
  ~NewHandlerHolder() { std::set_new_handler(p); std::cout << __func__ << std::endl; }
private:
  std::new_handler p;
};

template<typename T>
class NewHandlerSupport {
public:
  static std::new_handler set_new_handler(std::new_handler p) noexcept;
  static void *operator new(std::size_t sz) noexcept(false);
  void *operator new(std::size_t sz, int dummy);
private:
  static std::new_handler currentHandler_;
};

template<typename T>
std::new_handler NewHandlerSupport<T>::currentHandler_ = 0;

template<typename T>
std::new_handler NewHandlerSupport<T>::set_new_handler(std::new_handler nh) noexcept {
  std::new_handler oldHandler = currentHandler_;
  currentHandler_ = nh;
  return oldHandler;
}

template<typename T>
void *NewHandlerSupport<T>::operator new(std::size_t sz) noexcept(false) {
  std::cout << "Setting new_handler for NewHandlerSupport" << std::endl;
  std::new_handler old = std::set_new_handler(currentHandler_);
  void *p = 0;
  try {
    p = ::operator new(sz);
  } catch (...) {
    std::cout << "Resetting new_handler for NewHandlerSupport on exception" << std::endl;
    std::set_new_handler(old);
  }
  std::cout << "Resetting new_handler for NewHandlerSupport" << std::endl;
  std::set_new_handler(old);

  return p;
}

template<typename T>
void *NewHandlerSupport<T>::operator new(std::size_t sz, int dummy) {
  NewHandlerHolder h(std::set_new_handler(currentHandler_));
  return ::operator new(sz);
}

class Widget : public NewHandlerSupport<Widget> {
  int array[SZ];
};

int main() {
  //test_set_new_handler();
  Widget::set_new_handler(oom);
  Widget *p = new (42) Widget;
  delete p;
}
