#include <algorithm>
#include <iostream>
#include <iterator>

using namespace std;

#define ASPECT_RATIO 1.654

// Compiler will see AspectRatio.
// The object code will be smaller.
const double AspectRatio = 1.654;

class GamePlayer {
public:
  // the enum hack
  enum {ArraySize = 5};
  GamePlayer() : scores{0,0,0,0,0} {}
  ~GamePlayer() = default;

  void print() const {
    //std::for_each(begin(scores), end(scores), std::ostream_iterator<int>(std::cout, " "));
  }
private:
  static const int NumTurns = 5; // bear in mind: it's decleration not definition!
public:
  //int scores[NumTurns];
  int scores[ArraySize];
};


class CostEstimate {
public:
  static const double FudgeFactor;
};

const double CostEstimate::FudgeFactor = 3.14;

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
  GamePlayer p;
  std::cout << "p.scores's size = " << sizeof(p.scores) / sizeof(p.scores[0]) << std::endl;
  std::cout << "CostEstimate::FudgeFactor = " << CostEstimate::FudgeFactor << std::endl;
}
