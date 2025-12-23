#include <bits/stdc++.h>
using namespace std;
int N;
vector<int> vct;
priority_queue<int> pq1;
priority_queue<int,vector<int>,greater<int>> pq2;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        pq1.push(a);
        if(pq1.size()-1!=pq2.size()){
            pq2.push(pq1.top());
            pq1.pop();
        }else{
            if (!pq1.empty() && !pq2.empty()&& pq1.top() > pq2.top() ) {
                int top2=pq2.top();
                pq2.pop();
                int top1=pq1.top();
                pq1.pop();
                pq1.push(top2);
                pq2.push(top1);
            }
        }
        cout<<pq1.top()<<"\n";

    }
}