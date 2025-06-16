#include<bits/stdc++.h>
#define INF (int)1e9
using namespace std;
int T;
int main() { 
    cin >> T; 
    while(T--){
        int min_num = INF;
        int max_num = 0;
        int K;
        vector<int> vct[26];
        string str;
        cin >> str;
        cin >> K;
        for (int i = 0; i < str.length(); i++) {
            vct[str[i] - 'a'].push_back(i);//알파벳에 인덱스 넣기 aaba라면, a는 0,1,3저장
        }
        for (int i = 0; i < 26;i++){
            if(vct[i].size()<K) continue;
            for (int j = 0; j <= vct[i].size() - K;j++) {
                int length = vct[i][j + K - 1] - vct[i][j]+1;
                min_num = min(min_num, length);
                max_num = max(max_num, length);
            }
        }
        if (min_num==INF) {
            cout << -1<<"\n";
        }else{
            cout << min_num<<" ";
            cout << max_num << "\n";
        }
    }
}