#include <bits/stdc++.h>

using namespace std;

int T,N,M,K;
int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>T;
    for(int i=1;i<=T;i++){
        cin>>N>>M>>K;
        bool check=true;
        vector<int> vct;
        for(int j=0;j<N;j++){
            int n;
            cin>>n;
            vct.push_back(n);
        }
        sort(vct.begin(),vct.end());
        int sum=0;
        for (int i = 0; i < N; ++i) {
            int t = vct[i];          
            int made = (t / M) * K;  
            int need = i + 1;        

            if (made < need) {  
                check = false;
                break;
            }
        }

        cout<<"#"<<i<<" ";
        if(check){
            cout<<"Possible\n";
        }else{
            cout << "Impossible\n";
        }
    }

    

    return 0;  // 정상종료시 반드시 0을 리턴해야합니다.
}