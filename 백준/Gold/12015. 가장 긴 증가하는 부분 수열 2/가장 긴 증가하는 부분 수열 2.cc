#include<bits/stdc++.h>
using namespace std;
int N;
int A[1000000];
vector<int> vct;
int change;
void binary(int num) {
    int middle;
    int start = 0;
    int end = vct.size() - 1;
    while(start<=end){
        middle = (start + end) / 2;
        if(vct[middle]>=num){
            end = middle - 1;
            change = middle;
        }else{
            start = middle + 1;
        }
    }
    vct[change] = num;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N;i++){
        cin >> A[i];
    }
    vct.push_back(A[0]);
    for (int i = 1; i < N;i++){
        if(A[i]<=vct[vct.size()-1]){
            binary(A[i]);
        }else{
            vct.push_back(A[i]);
        }
        // for (int j = 0; j < vct.size(); j++) {
        //     cout << vct[j] << " ";
        // }
        // cout << "\n";
    }
    cout << vct.size();
}