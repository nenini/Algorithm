#include <string>
#include <vector>
#include<algorithm>
#include<climits>
using namespace std;

int result=INT_MAX;
bool visited[50];

bool check_str(string str1, string str2){
    int cnt=0;
    for(int i=0;i<str1.size();i++){
        if(str1[i]!=str2[i]){
            cnt++;
        }
    }
    if(cnt==1){
        return true;
    }else return false;
}

void dfs(string str, string target, vector<string> words,int depth){
    if(result<=depth) return;
    if(str==target){
        result=min(result,depth);
        return;
    }
    
    for(int i=0;i<words.size();i++){
        string nstr=words[i];
        if(!visited[i]&&check_str(str, nstr)){
            visited[i]=true;
            dfs(nstr,target,words,depth+1);
            visited[i]=false;
        }
    }
    
}

int solution(string begin, string target, vector<string> words) {
    
    if(find(words.begin(),words.end(),target)!=words.end()){
        dfs(begin,target,words,0);
        return result;
    }else{
        return 0;
    }
    
}