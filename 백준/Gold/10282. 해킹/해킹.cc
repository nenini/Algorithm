#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int TC;
int n,d,c;
vector<pair<int,int>> vct[10001];
int dist[10001];
void dijkstra(int start){
    priority_queue<pair<int,int>> pq;
    pq.push({0,start});
    dist[start]=0;
    while(!pq.empty()){
        int c=pq.top().second;
        int w=-pq.top().first;
        pq.pop();
        if (dist[c] < w) continue;
        for(int i=0;i<vct[c].size();i++){
            int n=vct[c][i].first;
            int nw=w+vct[c][i].second;
            if(dist[n]>nw){
                dist[n]=nw;
                pq.push({-nw,n});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>TC;
    for(int t=0;t<TC;t++){
        for (int i = 1; i <= 10000; i++) {
            vct[i].clear();
        }
        cin>>n>>d>>c;
        for(int i=0;i<d;i++){
            int a,b,s;
            cin>>a>>b>>s;
            vct[b].push_back({a,s});
        }
        fill(dist,dist+10001,(int)1e9);
        dijkstra(c);
        int count=0;
        int result=0;
        for(int i=0;i<10001;i++){
            if (dist[i] != (int)1e9){
                count++;
                result = max(result, dist[i]);
            }
            
        }
        cout<<count<<" "<<result<<"\n";
    }
}

