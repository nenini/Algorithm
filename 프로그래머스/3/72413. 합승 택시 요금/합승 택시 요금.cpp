#include <bits/stdc++.h>
#define INF (int)1e9
using namespace std;
//n: 지점, s: 출발지점, a: A의 도착, b: B의 도착, 
// fares: 요금(c,d,f)->f원(양방향)
vector<pair<int,int> > vct[201];
int result[201];
int N;
int dijkstra(int start, int end){
    for(int i=1;i<=N;i++){
        result[i]=INF;
    }
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
    result[start]=0;
    pq.push(make_pair(0,start));
    while(!pq.empty()){
        
        int curr=pq.top().second;
        int weight=pq.top().first;
        pq.pop();
        if(curr==end) break;
        if(result[curr]<weight) continue;
        
        for(int i=0;i<vct[curr].size();i++){
            int n_curr=vct[curr][i].second;
            int n_weight=vct[curr][i].first+weight;
            if(n_weight<result[n_curr]){
                result[n_curr]=n_weight;
                pq.push(make_pair(n_weight,n_curr));
            }
        }
    }
    return result[end];
    
    
}
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;
    N=n;
    for(int i=0;i<fares.size();i++){
        int c=fares[i][0];
        int d= fares[i][1];
        int f=fares[i][2];
        vct[c].push_back(make_pair(f,d));
        vct[d].push_back(make_pair(f,c));
    }
    for(int i=1;i<=n;i++){
        int stoi=dijkstra(s,i);
        int itoa=dijkstra(i,a);
        int itob=dijkstra(i,b);
        if(stoi==INF||itoa==INF||itob==INF) continue;
        answer=min(answer, stoi+itoa+itob);
    }
    
    
    return answer;
}