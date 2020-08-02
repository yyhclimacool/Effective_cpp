#include <iostream>
#include <list>
#include <string>

template<typename C>
void print2nd(const C &container) {
  if (container.size() >= 2) {
    typename C::const_iterator iter(container.begin());
    ++iter;
    std::cout << *iter << std::endl;
  }
}

template<typename T>
class Base {
public:
  class Nested {
  };
};

template<typename T>
class Derived : public Base<T>::Nested {
public:
  Derived() : Base<T>::Nested() {}
};

template<typename T>
void workWithIterator(T iter) {
  typedef typename std::iterator_traits<T>::value_type value_type;
  value_type temp(*iter);
  std::cout << temp << std::endl;
}

int main() {
  std::list<std::string> slist {"first", "second", "third", "fourth"};
  print2nd(slist);

  Derived<int> d;

  workWithIterator(--slist.end());
}
