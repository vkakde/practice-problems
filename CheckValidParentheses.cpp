#include <iostream>
#include <conio.h>
#include<string>
#include<stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        
        for(auto it: s){
            if(stk.empty()){
                stk.push(it);
            }
            else if((stk.top() == '(' && it == ')') ||
                    (stk.top() == '{' && it == '}') ||
                    (stk.top() == '[' && it == ']')
                   ){
                stk.pop();
            }
            else{
                stk.push(it);
            }
        }
        
        if(!stk.empty()){
            return false;
        }
        
        return true;
    }
};

int main(){
    Solution s;
    std::cout<<s.isValid("()");
    return 0;
}