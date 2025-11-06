#include <bits/stdc++.h>

using namespace std;
//맵을 이용해서 키: 작성한 검색 / 값: 자동완성 값
//입력되는 단어의 index 0~size까지 반복적으로 돌면서 만약 map에 현재 키 단어가 있다면 계속반복, 키 단어가 없다면 추가하고 끝내기 ->그리고 그 index를 result에 더하기
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
                //현재 키가 없다면
                sum+=j+1;
                cout<<sum<<" ";
                mp[str]=words[i];
                break;
            }else{
                //현재 키가 있다면
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