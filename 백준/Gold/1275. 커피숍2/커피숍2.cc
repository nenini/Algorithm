#include<bits/stdc++.h>

using namespace std;

int N,Q;
long long tree[400001];
long long arr[100001];
// 세그트리 초기화
long long init(int node, int start, int end){
    if(start==end) return tree[node]=arr[start];
    int middle=(start+end)/2;
    return tree[node]=init(node*2, start, middle)+init(node*2+1, middle+1, end);
}

//세그트리 change
void change(int node, int index, int start, int end, long long diff){
    if(index<start||index>end) return ;
    tree[node]=tree[node]+diff;
    if(start!=end){
        int middle=(start+end)/2;
        change(node*2, index, start, middle, diff);
        change(node*2+1, index, middle+1, end,diff);
    }
    
}
//세그트리 sum

long long sum(int node, int start, int end, int left, int right){
    if(end<left||start>right) return 0;
    if(left<=start&&right>=end) return tree[node];
    int middle=(start+end)/2;
    return sum(node*2, start, middle, left,right)+sum(node*2+1,middle+1, end, left, right);
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>N>>Q;
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    init(1,0,N-1);

    for(int i=0;i<Q;i++){
        int x,y,a,b;
        cin>>x>>y>>a>>b;
        if(x>y) swap(x,y);

        cout<<sum(1, 0,N-1,x-1,y-1)<<"\n";

        long long diff=b-arr[a-1];
        arr[a-1]=b;
        change(1,a-1,0,N-1,diff);
        
    }

}