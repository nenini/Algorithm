#include <bits/stdc++.h>
using namespace std;
int T;
vector<int> vct;
int result;
int N, K;
void dfs(int index,int sum){
    if(sum==K){
        result++;
        return;
    }

    for(int i=index+1;i<N;i++){
        dfs(i,sum+vct[i]);
    }
}
int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    for (int test = 1; test <= T; test++) {
        vct.clear();
        result=0;
        cin >> N >> K;

        for(int i=0;i<N;i++){
            int A;
            cin>>A;
            vct.push_back(A);
        }
        for(int i=0;i<N;i++){
            dfs(i,vct[i]);
        }
        cout << "#" << test << " " << result << "\n";
    }
}