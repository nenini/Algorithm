#include <string>
#include <vector>
#include <queue>
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> pq;
    for(int i=0;i<works.size();i++){
        pq.push(works[i]);
    }
    while(n>0&&!pq.empty()){
        n--;
        int cur=pq.top();
        pq.pop();
        if(cur-1<=0) continue;
        pq.push(cur-1);
    }
    
    while(!pq.empty()){
        int cur= pq.top();
        pq.pop();
        answer+= (cur*cur);
    }
    return answer;
}