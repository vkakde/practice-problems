#include<iostream>
#include<conio.h>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    int customPow(int b, int e){
        int res=1;
        while(e-->0){
            res*=b;
        }
        return res;
    }

    int titleToNumber(string s) {
        int res=0;
        int multiplier=0;
        for(int i=s.length()-1; i>=0; i--){
            //cout<<"\nCharToInt "<<s[i]<<": "<<(int)s[i];
            res+=(((int)s[i]-65+1)*customPow(26,multiplier++));
        }
        return res;
    }
};

int main(){
    Solution s;
    int res = s.titleToNumber("AA");
    cout<<res;

    return 0;
}