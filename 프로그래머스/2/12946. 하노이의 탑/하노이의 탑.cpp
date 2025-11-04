#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> answer;

void hanoi(int num, int start, int mid, int end){
    if(num>=2){
        hanoi(num-1,start,end,mid);
        answer.push_back({start,end});
        hanoi(num-1,mid,start,end);
    }
    else if(num==1) answer.push_back({start,end});
}

vector<vector<int>> solution(int n) {
    hanoi(n,1,2,3);
    return answer;
}