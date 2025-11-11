#include <bits/stdc++.h>

using namespace std;
priority_queue<int,vector<int>,greater<int>> pq;
bool check;
int solution(vector<int> scoville, int K) {
    int answer = 0;
    for(int i=0;i<scoville.size();i++){
        pq.push(scoville[i]);
    }
    int sum=0;
    while(true){
        if(pq.top()>=K){
            check=true;
            break;
        }
        if(pq.size()==1){
            break;
        }
        int first=pq.top();
        pq.pop();
        int second=pq.top();
        pq.pop();
        int num=first+(second*2);
        pq.push(num);
        sum++;
    }
    if(check) answer=sum;
    else answer=-1;
    return answer;
}