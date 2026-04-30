#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <cmath>
#include <utility>

using namespace std;

unordered_map<int, pair<int,int>> enter_time;
map<int, int> total_time;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;

    for(int i = 0; i < records.size(); i++){
        int hour = stoi(records[i].substr(0,2));
        int minute = stoi(records[i].substr(3,2));
        int num = stoi(records[i].substr(6,4));
        string oper = records[i].substr(11);

        if(oper == "IN"){
            enter_time[num] = {hour, minute};
        } else {
            pair<int,int> t = enter_time[num];

            int inTime = t.first * 60 + t.second;
            int outTime = hour * 60 + minute;
            int time = outTime - inTime;

            total_time[num] += time;
            enter_time.erase(num);
        }
    }

    int endTime = 23 * 60 + 59;

    for(auto car : enter_time){
        int num = car.first;
        pair<int,int> t = car.second;

        int inTime = t.first * 60 + t.second;
        total_time[num] += endTime - inTime;
    }

    for(auto car : total_time){
        int time = car.second;

        int fee = fees[1];

        if(time > fees[0]){
            fee += ceil((double)(time - fees[0]) / fees[2]) * fees[3];
        }

        answer.push_back(fee);
    }

    return answer;
}