#pragma once
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

namespace bullpgia {

class Guesser {
public:
unsigned int length;
string b_n_p;

virtual string guess() = 0;
virtual void startNewGame(uint length) {
      length=length;
};

virtual void learn(string results) {
        b_n_p = results;
};
};
}
