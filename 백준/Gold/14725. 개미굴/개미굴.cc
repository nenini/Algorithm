#include<iostream>
#include<vector>
#include<map>

using namespace std;

struct Node{
    map<string,int> child;
};

int N;
vector<Node> trie(1);

void insert(int K){
    int cur=0;
    for(int i=0;i<K;i++){
        string t;
        cin>>t;
        if(trie[cur].child.find(t)==trie[cur].child.end()){
            trie[cur].child[t]=trie.size();
            trie.push_back(Node());
        }
        cur=trie[cur].child[t];
    }
}

void dfs(int cur,int depth){
    for(auto c:trie[cur].child){
        for(int i=0;i<depth;i++) cout<<"--";
        cout<<c.first<<"\n";
        dfs(c.second,depth+1);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>N;
    for(int i=0;i<N;i++){
        int K;
        cin>>K;
        insert(K);
    }
    dfs(0,0);
}