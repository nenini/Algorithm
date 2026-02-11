#include <math.h>
#include<queue>
#include <iostream>
#include<cstring>
using namespace std;
int N, Q;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};
int arr[64][64];
int temp[64][64];
int size_arr;
int sum_result;
int max_ice=0;
bool visited[64][64];
void rotation(int a, int b, int part_size) {
    for (int i = 0; i < part_size; i++) {
        for (int j = 0; j < part_size; j++) {
            temp[a + j][b + part_size - i - 1] = arr[a + i][b + j];
        }
    }
}
void firestorm() {
    for (int i = 0; i < size_arr; i++) {
        for (int j = 0; j < size_arr; j++) {
            int dir_sum = 0;
            for (int d = 0; d < 4; d++) {
                int nx = i + dx[d];
                int ny = j + dy[d];
                if (nx < 0 || ny < 0 || nx >= size_arr || ny >= size_arr) continue;
                if (arr[nx][ny] > 0) {
                    dir_sum++;
                }
            }
            if (dir_sum < 3) {
                temp[i][j] = arr[i][j] - 1;
            } else {
                temp[i][j] = arr[i][j];
            }
        }
    }
    memcpy(arr, temp, sizeof(temp));
}
void find_sum() {
    for (int i = 0; i < size_arr; i++) {
        for (int j = 0; j < size_arr; j++) {
            if(arr[i][j]<0){
                arr[i][j]=0;
            }
            sum_result += arr[i][j];
        }
    }
}
int bfs(int x,int y){
    int sum=0;
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    visited[x][y]=true;
    while(!q.empty()){
        sum++;
        int currx=q.front().first;
        int curry=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nextx=currx+dx[i];
            int nexty=curry+dy[i];
            if(nextx<0||nexty<0||nextx>=size_arr||nexty>=size_arr) continue;
            if(!visited[nextx][nexty]&&arr[nextx][nexty]>0){
                visited[nextx][nexty]=true;
                q.push(make_pair(nextx,nexty));
            }
        }
    }
    return sum;
    

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> Q;
    size_arr = pow(2, N);
    for (int i = 0; i < size_arr; i++) {
        for (int j = 0; j < size_arr; j++) {
            cin >> arr[i][j];
        }
    }
    for (int k = 0; k < Q; k++) {
        int num;
        cin >> num;
        int part_size = pow(2, num);
        for (int i = 0; i < size_arr; i += part_size) {
            for (int j = 0; j < size_arr; j += part_size) {
                rotation(i, j, part_size);
            }
        }
        memcpy(arr, temp, sizeof(temp));
        firestorm();
    }
    find_sum();
    for(int i=0;i<size_arr;i++){
        for(int j=0;j<size_arr;j++){
            if(!visited[i][j]&&arr[i][j]>0){
                max_ice = max(max_ice, bfs(i, j));
            }
        }
    }
    cout<<sum_result<<"\n"<<max_ice;
}