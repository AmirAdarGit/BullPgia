
#include "SmartGuesser.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <math.h>
#include <string>
using std::string;
using namespace std;
using namespace bullpgia;




string SmartGuesser::guess() {
        std::list<std::string>::iterator it = myList.begin();
         if(myList.size()==0){
              build_the_List();       
        }
        else if(myList.size()==1){
                this->myGuess = *myList.begin();
        }
        if(myList.size()>1) {
                std::advance(it, rand()%(myList.size()-1));
                this->myGuess = *it;
        }
      
        return myGuess;
}
//http://www.cplusplus.com/reference/list/list/insert/
//http://www.cplusplus.com/reference/iomanip/setfill/
 void SmartGuesser::build_the_List(){
        int size= pow(10,length);
        for (size_t i = 0; i < size; i++) {
                stringstream stream;
                stream << setw(length) << setfill('0') << i;  
                string s = stream.str();
                myList.push_front(s); 
        }
 }


void SmartGuesser::startNewGame(uint length) {
        myList.clear();
        this->length=length;
        build_the_List();
}

void SmartGuesser::learn(string results)

{
        remove_element_from_list(results);
}
void SmartGuesser::remove_element_from_list(string results){
        list<string>::iterator itr;
        for(itr = myList.begin(); itr != myList.end();)
        {
                string back=calculateBullAndPgia(*itr,myGuess);
                if(back.compare(results)!=0) {
                        itr=myList.erase(itr);
                }
                else{
                        ++itr;
                }
        }
      this-> myList.remove(myGuess);
}