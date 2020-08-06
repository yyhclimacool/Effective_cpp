#include <iostream>
#include <string>
#include <vector>

void test1() {
  std::vector<std::string> svec{"a", "an", "the"};

  std::vector<std::string>::iterator it = svec.begin();
  const std::vector<std::string>::iterator cit = svec.begin();
  *cit = "A";
  // can't modify cit
  //++cit;
  std::vector<std::string>::const_iterator itc = svec.begin();
  // can't modify content of *itc
  //*itc = "A";
  ++itc;
}

class TextBook {
public:
  TextBook(const std::string &s) : text(s) {}
  ~TextBook() = default;

  // overload
  const char &operator[](size_t i) const { return text[i]; }
  // char &operator[](size_t i) { return text[i]; }
  char &operator[](size_t i) {
    return const_cast<char &>(static_cast<const TextBook &>(*this)[i]);
  }
private:
  std::string text;
};

void print(const TextBook &bk) {
  std::cout << "first element of TextBook : " << bk[0] << std::endl;
}
void test2() {
  TextBook tb1("nice");
  const TextBook tb2("good");
  print(tb1);
  print(tb2);
}

int main() {
  test1();
  test2();
}
