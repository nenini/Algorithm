#include <bits/stdc++.h>

using namespace std;

int T,N;
int arr[49][49];
int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>T;
    for (int test = 1; test <= T; test++) {
        int sum=0;
        cin>>N;
        for(int i=0;i<N;i++){
            string str;
            cin>>str;
            for(int j=0;j<N;j++){
                arr[i][j]=str[j]-'0';
            }
        }
        int middle=N/2;
        for (int i = 0; i < N; i++) {
            if(i<=middle){
                for (int j = middle - i; j <= middle + i; j++) {
                    sum += arr[i][j];
                }
            }else{
                int size=N-i-1;
                for (int j = middle - size; j <= middle + size; j++) {
                    sum += arr[i][j];
                }
            }
        }
        cout<<"#"<<test<<" "<<sum<<"\n";
    }

    return 0;  // 정상종료시 반드시 0을 리턴해야합니다.
}