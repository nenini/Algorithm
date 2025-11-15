#include<bits/stdc++.h>

using namespace std;
int test;
int N,L;
int T[20];
int K[20];
int result;
void dfs(int index, int score, int calorie){
    if(calorie<=L){
        result=max(result, score);
    }else{
        return;
    }
    for(int i=index;i<N;i++){
         dfs(i+1,score+T[i],calorie+K[i]);

    }
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>test;
    for(int i=0;i<test;i++){
        cin>>N>>L;
        result=0;
        for(int j=0;j<N;j++){
            cin>>T[j]>>K[j];
        }
        dfs(0,0,0);
        cout<<"#"<<i+1<<" "<<result<<"\n";
    }
	return 0;
}