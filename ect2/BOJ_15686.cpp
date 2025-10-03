#include<bits/stdc++.h>
using namespace std;
int arr[51][51];
vector<pair<int, int> > house;
vector<pair<int, int> > chicken;
vector<pair<int, int> > vct;
int N, M;
int answer=(int)1e9;
void dfs(int num, vector<pair<int, int>> &vct1) {
    if(vct1.size()==M){
        int total = 0;
        for (int i = 0; i < house.size();i++){
            int min_num = (int)1e9;
            for (int j = 0; j < vct1.size();j++){
                int dist = abs(house[i].first - vct1[j].first) + abs(house[i].second - vct1[j].second);
                min_num = min(min_num, dist);
            }
            total += min_num;
        }
        answer = min(answer, total);
        return;
    }
    for (int i = num; i < chicken.size();i++){
        vct1.push_back(chicken[i]);
        dfs(i + 1, vct1);
        vct1.pop_back();
    }
}
int main() { 
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N;j++){
            int num;
            cin >> num;
            if (num == 1) house.push_back(make_pair(i, j));
            else if(num == 2){
                chicken.push_back(make_pair(i, j));
            }
        }
    }
    dfs(0, vct);
    cout << answer;
}