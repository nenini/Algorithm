#include <bits/stdc++.h>

using namespace std;
map<string,string> mp;
int solution(vector<string> words) {
    int answer = 0;
    sort(words.begin(),words.end(),[](const string& a,const string& b){
        return a.length()<b.length();
    });
    for(int i=0;i<words.size();i++){
        int sum=0;
        for(int j=0;j<words[i].length();j++){
            string str=words[i].substr(0,j+1);
            if(mp.find(str)==mp.end()){
                sum+=j+1;
                cout<<sum<<" ";
                mp[str]=words[i];
                break;
            }else{
                if(mp[str].length()>=j+1){
                    string key=mp[str].substr(0,j+2);
                    if(mp.find(key)==mp.end()){
                        mp[key]=mp[str];
                        cout<<sum<<" ";
                        sum+=1;
                    }
                }
            }
        }
        answer+=sum;
    }
    return answer;
}