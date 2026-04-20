#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

int N,M;

struct Node
{
    long long max_num;
    long long min_num;
};


long long arr[100000];
Node tree[400001];

Node tree_init(int node, int start,int end){
    if(start==end){
        tree[node].max_num=arr[start];
        tree[node].min_num=arr[start];
        return tree[node];
    }
    int middle=(start+end)/2;
    Node n1=tree_init(node*2,start,middle);
    Node n2=tree_init(node*2+1,middle+1,end);

    return tree[node]={max(n1.max_num,n2.max_num),min(n1.min_num,n2.min_num)};

}

Node tree_get(int node, int start,int end,int left,int right){
    if(start>right|| end<left) return {0,LLONG_MAX};
    if(left<=start&&end<=right) return tree[node];
     int middle=(start+end)/2;
        Node n1=tree_get(node*2,start, middle,left, right);
        Node n2=tree_get(node*2+1,middle+1, end, left, right);
        return {max(n1.max_num,n2.max_num),min(n1.min_num,n2.min_num)};
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>N>>M;
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    tree_init(1,0,N-1);

    for(int i=0;i<M;i++){
        int a,b;
        cin>>a>>b;
        Node n=tree_get(1,0,N-1,a-1,b-1);
        cout<<n.min_num<<" "<<n.max_num<<"\n";
    }

}