#include <bits/stdc++.h>
using namespace std;
int arr[9][9];
int visited[9][9];
int N, M;
int cnt;
int result;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};
void bfs() {
    queue<pair<int, int> > q;
    cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            visited[i][j] = arr[i][j];
            if (arr[i][j] == 2) {
                q.push(make_pair(i, j));
            }
        }
    }
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<0||ny<0||nx>=N||ny>=M) continue;
            if (visited[nx][ny]==0) {
                visited[nx][ny] = 2;
                q.push(make_pair(nx, ny));
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (visited[i][j] == 0) {
                cnt++;
            }
        }
    }
    result = max(result, cnt);
}
void wall(int count) {
    if (count == 3) {
        bfs();
        return;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j] == 0) {
                arr[i][j] = 1;
                wall(count + 1);
                arr[i][j] = 0;
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j] == 0) {
                arr[i][j] = 1;
                wall(1);
                arr[i][j] = 0;
            }
        }
    }
    cout << result;
}

// #include<iostream>
// #include<queue>
// using namespace std;
// int N, M;
// int arr[9][9];
// int temp[9][9];
// int dx[4] = {0, 0, 1, -1};
// int dy[4] = {1, -1, 0, 0};
// int result = 0;
// int answer = 0;
// void bfs()
// {
//     int temp1[9][9];
//     queue<pair<int, int> > q;
//     for (int i = 0; i < N; i++){
//         for (int j = 0; j < M;j++){
//             temp1[i][j] = temp[i][j];
//             if (temp1[i][j] == 2)
//             {
//                 q.push(make_pair(i, j));
//             }
//         }
//     }
//     while(!q.empty()){
//         int x1 = q.front().first;
//         int y1 = q.front().second;
//         q.pop();
//         for (int i = 0; i < 4;i++){
//             int nx = x1 + dx[i];
//             int ny = y1 + dy[i];
//             if(nx<0||ny<0||nx>=N||ny>=M){
//                 continue;
//             }
//             if(temp1[nx][ny]==0){
//                 temp1[nx][ny] = 2;
//                 q.push(make_pair(nx, ny));
//             }
//         }
//     }
//     result = 0;
//     for (int i = 0; i < N; i++)
//     {
//         for (int j = 0; j < M;j++){
//             if(temp1[i][j]==0){
//                 result++;
//             }
//         }
//     }
//     if(answer<result){
//         answer = result;
//     }

// }
// void wall(int count){
//     if(count==3){
//         bfs();
//         return;
//     }
//     else
//     {
//         for (int i = 0; i < N;i++){
//             for (int j = 0; j < M;j++){
//                 if(temp[i][j]==0){
//                     temp[i][j] = 1;
//                     wall(count + 1);
//                     temp[i][j] = 0;
//                 }
//             }
//         }
//     }
// }
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     cin >> N >> M;
//     int x;
//     for (int i = 0; i < N; i++)
//     {
//         for (int j = 0; j < M;j++){
//             cin >> arr[i][j];
//             temp[i][j] = arr[i][j];

//         }
//     }
//     for (int i = 0; i < N;i++){
//         for (int j = 0; j < M;j++){
//             if(temp[i][j]==0){
//                 temp[i][j] = 1;
//                 wall(1);
//                 temp[i][j] = 0;
//             }
//         }
//     }
//     cout << answer;
// }