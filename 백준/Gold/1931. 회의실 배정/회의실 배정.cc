#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N;
int cnt = 0;
vector<pair<int, int> > v;
int x, y;
int main()
{
    cin >> N;
    for (int i = 0; i < N;i++){
        cin >> x >> y;
        v.push_back(make_pair(y, x));
    }
    sort(v.begin(), v.end());
    int start = v[0].first;
    cnt++;
    for (int i = 1; i <= N; i++)
    {
        if(start<=v[i].second){
            cnt++;
            start = v[i].first;
        }
    }
    cout << cnt;
}