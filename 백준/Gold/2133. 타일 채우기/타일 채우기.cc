#include<bits/stdc++.h>
using namespace std;
int dp[31];
int N;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>N;
    dp[0]=1;
    dp[1]=0;
    dp[2]=3;
    dp[3]=0;
    for(int i=4;i<=N;i++){
        if(i%2==0){
            dp[i]=dp[i-2]*dp[2];
            for(int j=i-4;j>=0;j-=2){
                dp[i]+=(2*dp[j]);
            }
        }else{
            dp[i]=0;
        }
    }
    cout<<dp[N];  
}