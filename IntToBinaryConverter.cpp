#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

int main (){
    int in  = 128;
    string res="";

    while(in>0){
        res = std::to_string(in%2)+res;
        if(in==1){
            break;
        }
        in/=2;
    }

    cout<<stoi(res);
    return 0;
}