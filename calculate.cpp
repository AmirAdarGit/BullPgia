
#include <string>
#include "iostream"
using namespace std;
namespace bullpgia {
std::string bullpgia::calculateBullAndPgia(string choice,string guess)
{
int choiseArr[10];
int guessArr[10];
int bullCount=0;
int pgiaCount=0;


if(choice.length()!=guess.length())
{
  return "error input";
}

for(int i=0;i<10;i++)//initioal the arr with 0
{ 
choiseArr[i]=0;
}
for(int i=0;i<10;i++)//initioal the arr with 0
{ 
guessArr[i]=0;
}
//put 1 ont the choice array at the correct cell
for(int i=0;i<choice.length();i++) //choice == guess (length)
  {
    string gu;
    gu=guess[i];
    int tempGu;
    tempGu=stoi(gu);

    string ch;
    ch = choice[i];
    int tempCh;
    tempCh=stoi(ch);//custing from stirng to int 

    for(int j=0;j<10;j++)
    {
      if(tempGu==j)
      {
         choiseArr[j]++;
      }
      if(tempCh==j)
      {
         guessArr[j]++;
      }
    }
  }
 
for(int i=0;i<choice.length();i++)
{
  if(choice[i]==guess[i])
  {
  bullCount++;
  string temp;
  temp=choice[i];
  int n=stoi(temp);
      for(int j=0;j<10;j++)
    {
      if(j==n)
      {
      choiseArr[j]--;
      guessArr[j]--;
      }
    }
  }
}
 
for(int i=0;i<10;i++)
{
  if(choiseArr[i] != 0 && guessArr[i] != 0)
  {
    while(choiseArr[i]!=0||guessArr[i]!=0)
    {
      pgiaCount++;
      choiseArr[i]--;
      guessArr[i]--;
    }
  }
}

// cout<<bullCount<<" bulls";
// cout<<pgiaCount<<" pgia"<<endl;
return to_string(bullCount) + "," + to_string(pgiaCount);
}
}
