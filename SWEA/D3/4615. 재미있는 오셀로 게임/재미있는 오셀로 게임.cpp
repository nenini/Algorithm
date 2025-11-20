#include <bits/stdc++.h>
using namespace std;

int T;
char arr[9][9];
int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[8] = {-1, 1, 0, 0, -1, 1, -1, 1};
char colors[3] = {'\0', 'B', 'W'};
int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    for (int test = 1; test <= T; test++) {
        int bcount=0, wcount=0;
        int N, M;
        cin >> N >> M;
        memset(arr,0,sizeof(arr));
        arr[N / 2][N / 2] = 'W';
        arr[N / 2][N / 2 + 1] = 'B';
        arr[N / 2 + 1][N / 2] = 'B';
        arr[N / 2 + 1][N / 2 + 1] = 'W';

        for (int i = 0; i < M; i++) {
            int x, y, color;
            cin >> x >> y >> color;
            arr[x][y]=colors[color];
            for (int j = 0; j < 8; j++) {
                vector<pair<int, int>> vct;
                int nx = x ;
                int ny = y ;
                while (true) {
                    // cout<<"d";
                    // 똑같은 색을 만날때까지
                    nx = nx + dx[j];
                    ny = ny + dy[j];
                    if (nx < 1 || ny < 1 || nx > N || ny > N) break;
                    if (arr[nx][ny] == colors[color]) {
                        for(int size=0;size<vct.size();size++){
                            int vx=vct[size].first;
                            int vy=vct[size].second;
                            arr[vx][vy]=colors[color];
                        }
                        break;
                    }else{
                        if(arr[nx][ny]!='\0'){
                            vct.push_back(make_pair(nx,ny));
                        }else{
                            break;
                        }
                    }
                }
            }
        }
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                if(arr[i][j]=='B'){
                    bcount++;
                }else if(arr[i][j]=='W'){
                    wcount++;
                }
            }
        }
        cout<<"#"<<test<<" "<<bcount<<" "<<wcount<<"\n";
    }
}