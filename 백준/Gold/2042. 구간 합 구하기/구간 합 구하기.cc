#include <bits/stdc++.h>
using namespace std;
long long arr[1000000];
long long tree[4000001];
int N, M, K;

long long tree_init(int node, int start, int end) {
    if (start == end) return tree[node] = arr[start];

    int middle = (start + end) / 2;

    return tree[node] = tree_init(node * 2, start, middle) + tree_init(node * 2 + 1, middle + 1, end);
}

long long tree_sum(int node,int start, int end, int left, int right){
    if(end<left||start>right) return 0;

    if(left<=start&&right>=end) return tree[node];
    int middle=(start+end)/2;

    return tree_sum(node * 2, start, middle, left, right) + tree_sum(node * 2+1, middle+1, end, left, right) ;
}

void change(int node, int start, int end, int index, long long diff) {
    if(index<start||index>end) return;
    tree[node]=tree[node]+diff;
    if(start!=end){
        int middle=(start+end)/2;
        change(node*2,start,middle,index,diff);
        change(node * 2+1, middle+1, end, index, diff);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    // 트리 초기화
    tree_init(1, 0, N - 1);

    for (int i = 0; i < M + K; i++) {
        long long a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            //b번째 수를 c로 바꿈
            long long diff = c - arr[b - 1];
            arr[b-1]=c;
            change(1,0,N-1,b-1,diff);
        } else {
            long long sum=tree_sum(1,0,N-1,b-1,c-1);
            cout<<sum<<"\n";

        }
    }
}