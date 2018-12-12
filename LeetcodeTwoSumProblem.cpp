#include<iostream>
#include<conio.h>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

vector<int> twoSum(vector<int> input, int target){
    vector<int> result;
    map<int, int> mp;
    for(int i=0; i<input.size(); i++){
        if(mp.find(target-input[i])!=mp.end() && mp.at(target-input[i])!=i){
            result.push_back(mp.at(target-input[i]));
            result.push_back(i);
            return result;
        }
        mp.insert(make_pair(input[i], i));
    }

    return result;
}

int main(){
    vector<int> input = {2,7,11,15,3,8,18};
    int target =21;
    vector<int> result = twoSum(input, target);

    cout<<result[0]<<" "<<result[1];
    return 0;
}