#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    unordered_set<string> st;
    for(int i=0;i<gems.size();i++){
        st.insert(gems[i]);
    }
    int size=st.size();
    int left=0,right=0;
    int total=0;
    int result_len=INT_MAX, resultL=0,resultR=0;
    unordered_map<string,int> mp;
    while(true){
        
        if(total==size){
            int len=right-left;
            if(len<result_len){
                result_len=len;
                resultL=left;
                resultR=right-1;
            }
            mp[gems[left]]--;
            if(mp[gems[left]]==0){
                total--;
            }
            left++;
        }
        else{
            if(right==gems.size()) break;
            mp[gems[right]]++;
            if(mp[gems[right]]==1){
                total++;
            }
            right++;
        }
    }
    answer.push_back(resultL+1);
    answer.push_back(resultR+1);
    
    return answer;
    
}