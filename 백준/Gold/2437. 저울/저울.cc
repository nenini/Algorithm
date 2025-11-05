#include <bits/stdc++.h>
using namespace std;
int N;
vector<int> num;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>N;
    for(int i=0;i<N;i++){
        int n;
        cin>>n;
        num.push_back(n);
    }
    sort(num.begin(),num.end());
    int sum=0;
    for (int i = 0; i < N; i++) {
        if(sum<num[i]-1){
            cout << sum + 1;
            return 0;
        } else {
            sum += num[i];
        }
    }
    cout<<sum+1;
    return 0;
}