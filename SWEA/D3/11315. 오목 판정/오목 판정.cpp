#include <bits/stdc++.h>
using namespace std;
// 22:23
int T;
int N;
int dx[4]={1,0,1,1};
int dy[4] = {0, 1, 1, -1};
char arr[20][20];
bool dfs(int x,int y,int depth, int index){
    if(depth==5){
        return true;
    }
    int nx=x+dx[index];
    int ny=y+dy[index];
    if(nx<0||ny<0||nx>=N||ny>=N) return false;
    if(arr[nx][ny]=='o'){
        if (dfs(nx, ny, depth + 1, index)) {
            return true;
        } else {
            return false;
        }
    }
    return false;

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    for (int test = 1; test <= T; test++) {
        bool result=false;
        cin>>N;
        memset(arr,'\0',sizeof(arr));
        for(int i=0;i<N;i++){
            string input;
            cin>>input;
            for(int j=0;j<N;j++){
                arr[i][j]=input[j];
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if(arr[i][j]=='o'){
                    for(int k=0;k<4;k++){
                        if(dfs(i,j,1,k)){
                            result=true;
                            break;
                        }
                    }
                }
                if(result) break;
            }
            if (result) break;
        }
        cout << "#" << test << " ";
        if(result){
            cout<< "YES" << "\n";
        }
        else{
            cout << "NO" << "\n";
        }
    }
}