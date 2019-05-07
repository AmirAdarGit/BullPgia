#pragma once
#include "Guesser.hpp"
#include "calculate.hpp"
#include <list>

namespace bullpgia {
class SmartGuesser : public bullpgia :: Guesser{
private:

  list<std::string> myList;
  std::string myGuess;

public:
string guess() override;
void startNewGame(uint length) override;
void learn(string results) override;


void remove_element_from_list(string results);
void build_the_List();

};
}
