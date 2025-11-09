#include <bits/stdc++.h>
#define N_MAX 1001

using namespace std;
int N, M;
vector<int> worker[N_MAX];
int result = 0;
bool visited[N_MAX]; // 이 일을 확인한 적 있는지
int work[N_MAX]; //해야할 일을 담당하고 있는 직원 기록
bool dfs(int num) {
    for(int i=0;i<worker[num].size();i++){
        int curr=worker[num][i];
        if(visited[curr]) continue;
        visited[curr]=true;
        if (work[curr]==0 || dfs(work[curr])) {
            work[curr]=num;
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        int work;
        cin >> work;
        for (int j = 0; j < work; j++) {
            int num;
            cin >> num;
            worker[i].push_back(num);
        }
    }
    for (int i = 1; i <= N; i++) {
        fill(visited, visited+M+1,false); 
        if (dfs(i)) result++;
    }
    cout<<result;
}