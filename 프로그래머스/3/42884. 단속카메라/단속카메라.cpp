#include <bits/stdc++.h>

using namespace std;
int num=-(int)1e9;
int solution(vector<vector<int>> routes) {
    int answer = 0;
    sort(routes.begin(),routes.end(),[](const vector<int>& a,const vector<int>& b){
        return a[1]<b[1];
    });
    for(int i=0;i<routes.size();i++){
        if(num<routes[i][0]){
            num=routes[i][1];
            answer++;
        }
    }
    
    return answer;
}