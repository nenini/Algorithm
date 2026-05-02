#include <string>
#include <vector>
#include <set>

using namespace std;

vector<string> users;
vector<string> bans;
set<set<string>> result;
set<string> selected;
bool visited[8];

bool check(string user,string ban){
    if (user.size() != ban.size()) return false;

    for (int i = 0; i < user.size(); i++) {
        if (ban[i] == '*') continue;
        if (user[i] != ban[i]) return false;
    }

    return true;
}

void dfs(int depth){
    if(depth==bans.size()){
        result.insert(selected);
        return ;
    }
    
    for(int i=0;i<users.size();i++){
        if(visited[i]) continue;
        if(!check(users[i],bans[depth])) continue;
        visited[i]=true;
        selected.insert(users[i]);
        dfs(depth+1);
        visited[i]=false;
        selected.erase(users[i]);
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    users=user_id;
    bans=banned_id;
    dfs(0);
    answer=result.size();
    return answer;
}