#include <string>
#include <bits/stdc++.h>

using namespace std;

// 합이 9이면서 곱이 최대가 되려면, s를 균등하게 나누면 됨, 
// 즉 s / n = 중간값(이걸 기준으로 다른 값이 더해짐)
// n-1만큼 중간값이 반복되고, 나머지 n개째에 s%n(나머지) 추가한 값

vector<int> solution(int n, int s) {
    vector<int> answer;
    int mid=s/n;
    int rem=s%n;
    if(mid==0) return {-1};
    
    int size=rem/n;
    for(int i=0;i<n-rem;i++){
        answer.push_back(mid);
    }
    for(int i=0;i<rem;i++){
        answer.push_back(mid+1);
    }
    // for(int i=0;i<n-1;i++){
    //     answer.push_back(mid);
    // }
    // answer.push_back(mid+rem);
    return answer;
}