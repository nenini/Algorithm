//벡터에 중복값 제거하는 erase, uniqe
//lower_bount 사용법
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> v1;
vector<int> v2;
int N,X;
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0; i < N;i++){
        cin >> X;
        v1.push_back(X);
        v2.push_back(X);
    }
    sort(v1.begin(),v1.end() );
    v1.erase(unique(v1.begin(), v1.end()), v1.end());
    for (int i = 0; i < N;i++){
        cout << lower_bound(v1.begin(), v1.end(), v2[i]) - v1.begin()<<" ";
    }
}