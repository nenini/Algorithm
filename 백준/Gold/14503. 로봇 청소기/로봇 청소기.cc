#include<bits/stdc++.h>
using namespace std;
int N,M;
int r,c,d;
int result;
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
int arr[50][50];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>N>>M;
    cin>>r>>c>>d;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>arr[i][j];
        }
    }
    while(true){
        if(arr[r][c]==0){
            arr[r][c]=-1;
            result++;
        }
        bool check=false;
        for(int i=0;i<4;i++){
            int nr=r+dx[i];
            int nc=c+dy[i];
            if(nr<0||nc<0||nr>=N||nc>=M) continue;
            if(arr[nr][nc]==0){
                check=true; //청소 안한곳 있음
                break;
            }
        }
        if (check) {  // 청소 안한 곳 있음
            d = d - 1;
            if (d < 0) d += 4;
            int nr = r + dx[d];
            int nc = c + dy[d];
            if (nr < 0 || nc < 0 || nr >= N || nc >= M) continue;
            if (arr[nr][nc] == 0) {
                r = nr;
                c = nc;
            }
        }else{
            int back = d + 2;
            if (back >= 4) {
                back = d - 2;
            }
            r = r + dx[back];
            c = c + dy[back];
            if (r < 0 || c < 0 || r >= N || c >= M || arr[r][c] == 1) {
                cout << result;
                return 0;
            }
        }
    }
}