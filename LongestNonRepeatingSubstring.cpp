#include<string>
#include<iostream>
#include<conio.h>
#include<map>
#include<math.h>
#include<algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        
        map<char, int> mp;
        
        int i=0, j=0;
        
        while(j<s.length()){
            cout<<"\nMap contents: ";
            for(auto it: mp){
                cout<<endl<<it.first<<"  "<<it.second;
            }

            if(mp.find(s[j])==mp.end()){
                mp.insert(make_pair(s[j], j));
            }
            else{
                i = mp.at(s[j])+1;
                mp[s[j]]=j;
                
                for(auto it: mp)
                    if(it.second<i)
                        mp.erase(mp.find(it.first));
            }
            res = max(res, j-i+1);
            j++;
        }
        
        return res;
    }
};

int main(){
	Solution s;
	string str ("abbcde");
	int res = s.lengthOfLongestSubstring(str);
	cout<<"\n"<<res;

	return 0;
}