#include <iostream>
#include "passchecker.h"

using namespace std;

static inline void getInput(string& input){cout<<'>';cin>>input;}
template<class T> static inline void print(const T& output){cout<<output<<endl;}
static inline void clear(){system("cls");}
static inline void waitENTER(){cin.get();string s;getline(cin,s);}

int main()
{
    while(true){
        clear();
        print("Enter your password to validate");
        string password;
        getInput(password);
        PassChecker::checkPass(password);
        waitENTER();
    }
}
