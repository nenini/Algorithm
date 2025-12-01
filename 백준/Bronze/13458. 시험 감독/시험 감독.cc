#include<bits/stdc++.h>
using namespace std;

int N,B,C;
int A[1000000];
long long result;
int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    cin>>B>>C;
    for (int i = 0; i < N; i++) {
        int num=A[i];
        num-=B;
        int sub=0;
        if(num>0){
            sub=num/C;
            if(num%C!=0) sub+=1;
        }
        result+=(sub+1);
    }
    cout<<result;
}