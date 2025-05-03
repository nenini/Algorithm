#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<int> arr1;
vector<int> arr2;
int sum;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        if (num < 0)
            arr1.push_back(num);
        else
            arr2.push_back(num);
    }
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
    for (int i = 0; i < arr1.size();i+=M){
        sum += -arr1[i] * 2;
    }
    for (int i = arr2.size()-1; i >=0; i -= M) {
        sum += arr2[i] * 2;
    }
    int max_num=0;
    if(!arr1.empty()){
        max_num = -arr1.front();
    }
    if(!arr2.empty()){
        max_num = max(max_num, arr2.back());
    }
    sum -= max_num;
    cout << sum;
}