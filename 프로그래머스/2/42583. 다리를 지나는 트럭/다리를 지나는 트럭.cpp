#include <bits/stdc++.h>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int size=truck_weights.size();
    int curr_weight=0;
    queue<int> q;
    int index=0;
    while(true){
        if(!q.empty()&&q.size()==bridge_length){
            if(q.front()==size-1){
            answer++;
            break;
            }
            if(q.front()!=-1)
            curr_weight-=truck_weights[q.front()];
            q.pop();
        }
        if(index<size&&curr_weight+truck_weights[index]<=weight){
            curr_weight+=truck_weights[index];
            q.push(index);
            index++;
        }else{
            q.push(-1);
        }
        answer++;
    }
    return answer;
}