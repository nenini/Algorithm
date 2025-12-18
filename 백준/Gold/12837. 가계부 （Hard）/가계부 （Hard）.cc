#include<iostream>
using namespace std;
int N,Q;
long long tree[4000001];
long long arr[1000001];

void plus_tree(int node, int start, int end, int index, long long diff){
    if(index<start||index>end) return ;
    tree[node]=tree[node]+diff;
    if(start!=end){
        int middle=(start+end)/2;
        plus_tree(node*2, start, middle,index, diff);
        plus_tree(node*2+1, middle+1,end,index, diff);
    }
}

long long tree_sum(int node, int start, int end, int left, int right){
    if(end<left||start>right) return 0;
    if(left<=start&&right>=end) return tree[node];
    int middle=(start+end)/2;
    return(tree_sum(node*2,start,middle, left,right)+tree_sum(node*2+1,middle+1,end,left, right));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>N>>Q;
    for(int i=0;i<Q;i++){
        int num,p,q;
        cin>>num;
        if(num==1){
            cin>>p>>q;
            plus_tree(1,0,N-1,p-1,q);
        }else{
            cin>>p>>q;
            cout<<tree_sum(1,0,N-1,p-1,q-1)<<"\n";
        }
        
    }
}

// 1: 생후 p일과 관련된 모든 노드에 x추가
// 2: p부터 q까지 변화한 양-> p부터 q까지의 합