#pragma once
#include "calculate.hpp"
#include "Guesser.hpp"
#include <list>
#include <string>

namespace bullpgia {
class SmartGuesser : public bullpgia :: Guesser{
private:

  list<string> my_list;
  string my_guess;

public:

string guess() override;
void learn(string results) override;
void startNewGame(uint length) override;

void deleteElement(string ans);
void allOptions();

  };
}
