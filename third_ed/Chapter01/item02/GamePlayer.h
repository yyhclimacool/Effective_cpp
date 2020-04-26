#pragma once
#include <algorithm>
#include <iterator>
#include <iostream>

class GamePlayer {
  GamePlayer() : scores({0,0,0,0,0}) {}
  ~GamePlayer() = default;

  void print() const {
    std::for_each(begin(scores), end(scores), std::ostream_iterator<int>(std::cout, " "));
  }
private:
  static const int NumTurns = 5;
  int scores[NumTurns];
};
