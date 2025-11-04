#include <bits/stdc++.h>

using namespace std;

int arr[24]; // 각 시간당 현재 운영 가능한 서버 개수(추가될때마다 증설된 횟수만큼 +)

int solution(vector<int> players, int m, int k) {
    //m: m명 늘어날때마다 추가, k: 증설된 서버의 운영 시간
    int answer = 0;
    for(int i=0;i<=23;i++){
        int person = players[i];
        int need=person/m;
        if(arr[i]<need){
            int plus_server =  need-arr[i];
            for(int j=0;j<k;j++){
                if(i+j<=23) arr[i+j] = arr[i+j] + plus_server;
            }
            answer+=plus_server;
        }
    }
    return answer;
}