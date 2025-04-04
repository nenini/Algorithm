#include<iostream>
#include<algorithm>
using namespace std;
int N;
int arr[50];
int sum = 0;
int negative[50];
int negative_num = 0;
int positive_num = 0;
int positive[50];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        if(num<=0){
            negative[negative_num]=num;
            negative_num++;
        } else {
            positive[positive_num] = num;
            positive_num++;
        }
        // cin >> arr[i];
    }
    sort(negative, negative + negative_num);
    sort(positive, positive+positive_num, greater<int>());
    for (int i = 0; i < negative_num; i++) {
        if (i==negative_num-1){
            sum += negative[i];
            break;
        }
        sum += negative[i] * negative[i + 1];
        i++;
    }
    for (int i = 0; i < positive_num ; i++) {
        if (i == positive_num - 1) {
            sum += positive[i];
            break;
        }
        if(positive[i]==1||positive[i+1]==1){
            sum += positive[i];
        }else{
            sum += positive[i] * positive[i + 1];
            i++;
        }
    }

    cout << sum;
}