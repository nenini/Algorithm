#include<bits/stdc++.h>
using namespace std;
map<int,int> mp;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N,M;
    cin>>N;
    for(int i=0;i<N;i++){
        int A;
        cin>>A;
        mp[A]=1;
    }
    cin>>M;
    for (int i = 0; i < M; i++) {
        int num;
        cin >> num;
        if(mp.find(num)!=mp.end()){
            cout<<"1\n";
        }else{
            cout << "0\n";
        }
    }
}