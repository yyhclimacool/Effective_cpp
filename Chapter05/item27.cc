#include <iostream>

void test_old_style_casting() {
  int ival = 42;
  std::cout << "old style casting: (double)ival = " << (double)ival << std::endl;
  std::cout << "old style casting: double(ival) = " << double(ival) << std::endl;
}

/*
 * const_cast<T>(expr)  cast away constness
 *
 * dynamic_cast<T>(expr) cast pointer to Base to pointer to Derived, safe downcasting
 *
 * reinterpret_cast<T>(expr) bit-wise cast
 *
 * static_cast<T>(expr) implicit conversions, non-const to const etc.
 * 
 */


class Widget {
public:
  explicit Widget(int ) {}
};

void doSomeWork(const Widget &w) {
  std::cout << "doSomeWork on Widget addr:" << &w << std::endl;
}

void test_old_cast() {
  doSomeWork(Widget(42));
  doSomeWork(static_cast<Widget>(42));
}

class Base {
public:
  Base() {}
  ~Base(){}
private:
  int ival;
  std::string sval;
};
class Derived : public Base {
public:
  Derived() : Base() {}
  ~Derived(){}
private:
  std::string dsval;
};

void test_derived_and_base_ptr() {
  Derived d;
  Derived *pd = &d;
  Base *pb = &d;

  std::cout << "pointer to base addr:" << pb << " pointer to derived addr:" << pd << std::endl;
  if (pb == pd) {
    std::cout << "pointer to base addr equal pointer to derived" << std::endl;
  } else {
    std::cout << "pointer ot base addr not equal pointer to derived" << std::endl;
  }
}

class Window{
public:
  virtual void onResize() {
    std::cout << "Window::onResize on " << this << std::endl;
  }
  virtual void onScroll() {
    std::cout << "Window::onScroll on " << this << std::endl;
  }
};

class SpecialWindow : public Window {
public:
  virtual void onResize() {
    static_cast<Window>(*this).onResize();
    std::cout << "SpecialWindow::onResize on " << this << std::endl;
  }

  virtual void onScroll() {
    Window::onScroll();
    std::cout << "SpecialWindow::onScroll on " << this << std::endl;
  }
};

void test_specialwindow() {
  SpecialWindow sw;
  sw.onResize();
  sw.onScroll();
}

int main() {
  test_old_style_casting();
  test_old_cast();
  test_derived_and_base_ptr();
  test_specialwindow();
}
