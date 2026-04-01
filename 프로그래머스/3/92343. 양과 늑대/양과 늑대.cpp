#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <vector>
#include <cstring>

using namespace std;

vector<int> edge[17];
int result=0;
bool available[17];
void dfs(vector<int> info, int sheep,int wolf){
    result = max(result, sheep);
    for(int i=0;i<info.size();i++){
        if (!available[i]) continue;
        int nsheep=sheep;
        int nwolf=wolf;
        if(info[i]==0){
            nsheep++;
        }else{
            nwolf++;
        }
        
        if (nsheep <= nwolf) continue;
        
        bool temp[17];
        memcpy(temp,available,sizeof(available));
        available[i]=false;
        for(int idx=0;idx<edge[i].size();idx++){
            int child=edge[i][idx];
            available[child]=true;
        }
        dfs(info,nsheep,nwolf);
        memcpy(available,temp,sizeof(temp));

        
    }
}


int solution(vector<int> info, vector<vector<int>> edges) {
    
    for(int row=0;row<edges.size();row++){
        int parent=edges[row][0];
        int child=edges[row][1];
        edge[parent].push_back(child);
    }
    
    available[0]=true;
    dfs(info,0,0);
    
    return result;
}
