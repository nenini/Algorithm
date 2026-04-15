#include<iostream>
#include<vector>
#include<cstring>
#include<climits>
#include<algorithm>
#include<queue>
using namespace std;

int N, M;
int arr[50][50];
vector<pair<int,int>> virus;
int result = INT_MAX;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { -1,1,0,0 };
int dist[50][50];

void bfs(vector<pair<int, int>> activate_virus) {
	
	memset(dist, -1, sizeof(dist));

	queue<pair<int, int>> q;
	for (int i = 0; i < activate_virus.size(); i++) {
		q.push(activate_virus[i]);
		int x = activate_virus[i].first;
		int y = activate_virus[i].second;
		dist[x][y] = 0;
	}

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		if (dist[cx][cy] >= result&&arr[cx][cy]==0) return;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (arr[nx][ny] == 1) continue;
			if (dist[nx][ny] != -1) continue;
			dist[nx][ny] = dist[cx][cy] + 1;
			q.push({ nx,ny });
		}
	}

	

	int max_time = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == 0 && dist[i][j] == -1) {
				return;
			}
			else {
				if(arr[i][j]!=2&&arr[i][j]!=1)
					max_time = max(max_time, dist[i][j]);
			}
		}
	}
	result = min(result, max_time);
}

void dfs(vector<pair<int,int>> activate_virus,int index) {
	if (activate_virus.size() == M) {
		bfs(activate_virus);
		return;
	}
	for (int i = index; i < virus.size(); i++) {
		activate_virus.push_back(virus[i]);
		dfs(activate_virus, i + 1);
		activate_virus.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);	
	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				virus.push_back({ i,j });
			}
		}
	}
	vector<pair<int, int>> activate_virus;
	dfs(activate_virus, 0);

	if (result == INT_MAX) cout << -1;
	else cout << result;
}