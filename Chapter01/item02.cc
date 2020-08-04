#include <algorithm>
#include <iostream>
#include <iterator>

using namespace std;

#define ASPECT_RATIO 1.654

const double AspectRatio = 1.654;

class GamePlayer {
  GamePlayer() : scores{0,0,0,0,0} {}
  ~GamePlayer() = default;

  void print() const {
    //std::for_each(begin(scores), end(scores), std::ostream_iterator<int>(std::cout, " "));
  }
private:
  static const int NumTurns = 5;
  int scores[NumTurns];
};

void printARManyTimes() {
  std::cout << "AR: " << AspectRatio << std::endl; 
  std::cout << "AR: " << AspectRatio << std::endl; 
  std::cout << "AR: " << AspectRatio << std::endl; 
  std::cout << "AR: " << AspectRatio << std::endl; 
  std::cout << "AR: " << AspectRatio << std::endl; 
  std::cout << "AR: " << AspectRatio << std::endl; 
  std::cout << "AR: " << AspectRatio << std::endl; 
  std::cout << "AR: " << AspectRatio << std::endl; 
}

int main() {
  printARManyTimes();
}
