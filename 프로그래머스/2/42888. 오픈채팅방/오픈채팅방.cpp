#include <bits/stdc++.h>
#define ENTER 1
#define LEAVE 2
#define CHANGE 3
using namespace std;

map<string, string> user;
vector<pair<int,string> > output; // 상태, 유저아이디 저장

string ent="님이 들어왔습니다.";
string lv="님이 나갔습니다.";

vector<string> split(string str, char deli){
    vector<string> line;
    stringstream ss(str);
    string input;
    while(getline(ss,input,deli)){
        line.push_back(input);
    }
    return line;
}

void enter(vector<string> line){
    user[line[1]]=line[2];
    output.push_back(make_pair(ENTER, line[1]));
}

void leave(vector<string> line){
    output.push_back(make_pair(LEAVE, line[1]));
}

void change(vector<string> line){
    user[line[1]]=line[2];
}


vector<string> solution(vector<string> record) {
    vector<string> answer;
    for(int i=0;i<record.size();i++){
        vector<string> line = split(record[i], ' ');
        if(line[0]=="Enter"){
            enter(line);
        }else if(line[0]=="Leave"){
            leave(line);
        }else if(line[0]=="Change"){
            change(line);
        }
    }
    for(int i=0;i<output.size();i++){
        string name=user.at(output[i].second);

        if(output[i].first==ENTER){
            answer.push_back(name+ent);
        }else{
            answer.push_back(name+lv);
        }
    }
    return answer;
}

