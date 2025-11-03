#include <bits/stdc++.h>
using namespace std;
int n;
int sum;
vector<pair<int, int> > vct;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    priority_queue<int, vector<int>, greater<int> > pq;
    for (int i = 0; i < n; i++) {
        int d, p;
        cin >> p >> d;
        vct.push_back(make_pair(d, p));
    }
    sort(vct.begin(), vct.end());
    
    for (int i = 0; i < vct.size(); i++) {
        pq.push(vct[i].second);
        sum+=vct[i].second;
        if(pq.size()>vct[i].first){
            sum-=pq.top();
            pq.pop();
        }
    }
    cout<<sum;
}