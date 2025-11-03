#include <bits/stdc++.h>
#include <vector>

using namespace std;
int x[10];
int y[10];
int sum[10];
string solution(string X, string Y) {
    
    for(char c:X){
        x[c-'0']++;
    }
    for(char c:Y){
        y[c-'0']++;
    }
    string answer="";
    
    for(int i=0;i<=9;i++){
            sum[i]=min(x[i],y[i]);
        }
    
    for(int i=9;i>=0;i--){
        answer.append(sum[i],char(i+'0'));
    }
    if(answer.length()==0) return "-1";
    if(answer[0]=='0') return "0";
    
    return answer;
}
