#include <bits/stdc++.h>
using namespace std;
int N;
int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};
bool arr[101][101];
int result;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x, y, d, g;
        cin >> x >> y >> d >> g;
        vector<int> vct;
        vct.push_back(d);
        for (int j = 0; j < g; j++) {
            int size = vct.size();
            for (int k = size - 1; k >= 0; k--) {
                vct.push_back((vct[k] + 1) % 4);
            }
        }
        int cx=x;
        int cy=y;
        arr[cx][cy]=true;
        for(int j=0;j<vct.size();j++){
            cx=cx+dx[vct[j]];
            cy=cy+dy[vct[j]];
            arr[cx][cy] = true;
        }
    }
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            if(arr[i][j]&&arr[i+1][j]&&arr[i][j+1]&&arr[i+1][j+1]) result++;
        }
    }
    cout<<result;
}