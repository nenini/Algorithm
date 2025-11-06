#include <bits/stdc++.h>
using namespace std;
int N;
vector<int> vct;
void binary(int num){
    int start=0;
    int end=vct.size()-1;
    int middle;
    int result=0;
    while(start<=end){
        middle= (start+end)/2;
        if(vct[middle]>=num){
            end=middle-1;
            result=middle;
        }else{
            start=middle+1;
        }
    }
    vct[result]=num;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>N;
    for(int i=0;i<N;i++){
        int num;
        cin>>num;
        if(!vct.empty() && vct[vct.size()-1]>=num){
            binary(num);
        }else vct.push_back(num);
    }
    cout<<vct.size();
}