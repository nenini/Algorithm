#include <bits/stdc++.h>
using namespace std;

priority_queue<int,vector<int>,greater<int>>pq;  // 데드라인은 마이너스
vector<pair<int,int>> vct;
int N;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int d,c;
        cin>>d>>c;
        vct.push_back(make_pair(d,c));
    }
    int result=0;
    sort(vct.begin(),vct.end());
    for(int i=0;i<vct.size();i++){
        pq.push(vct[i].second);
        result+=vct[i].second;
        if(pq.size()>vct[i].first){
            result-=pq.top();
            pq.pop();
        }
    }
    cout<<result;
    
}