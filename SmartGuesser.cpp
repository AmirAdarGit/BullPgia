#include <iostream>
#include <iomanip>
#include <math.h>
#include <sstream>
#include <string>
#include "SmartGuesser.hpp"

using namespace bullpgia;
using namespace std;

void SmartGuesser::startNewGame(uint length) {
        my_list.clear();
        length=length;
        allOptions();
}

string SmartGuesser::guess() {
        list<string>::iterator iter = my_list.begin();
        if(my_list.size() == 1){
                my_guess = *my_list.begin();
        }
        else if(my_list.size()>1) {
                advance(iter, rand()%(my_list.size()-1));
                my_guess = *iter;
        }
        return my_guess;
}


 void SmartGuesser::allOptions(){
        int size_of_list = pow(10,length);
        for (size_t i = 0; i < size_of_list; i++) {
                stringstream stream;
                stream << setw(length) << setfill('0') << i;
                string temp = stream.str();
                my_list.push_front(temp);
        }
 }

void SmartGuesser::learn(string results){
        deleteElement(results);
}

void SmartGuesser::deleteElement(string ans){
        list<string>::iterator iter;
        for(iter = my_list.begin() ; iter != my_list.end() ; )
        {
                string back = calculateBullAndPgia(*iter,my_guess);
                if(back.compare(ans) != 0) {
                        iter=my_list.erase(iter);
                }
                else{
                        ++iter;
                }
        }
      my_list.remove(my_guess);
}



