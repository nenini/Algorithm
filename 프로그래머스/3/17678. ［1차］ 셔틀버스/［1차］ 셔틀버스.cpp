#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> crewtime;
int timetoint(string t){
    int hour=stoi(t.substr(0,2));
    int minute=stoi(t.substr(3,2));
    return hour*60+minute;
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    int result;
    for(int i=0;i<timetable.size();i++){
        int t=timetoint(timetable[i]);
        crewtime.push_back(t);
    }
    
    sort(crewtime.begin(),crewtime.end());
    
    int crew_idx=0;
    for(int i=0;i<n;i++){
        int bus_time=60*9+i*t;
        int count=0;
        while(crew_idx<crewtime.size()&&crewtime[crew_idx]<=bus_time&&count<m){
            crew_idx++;
            count++;
        }
        if(i==n-1){
            if(count<m){
                result=bus_time;
            }else{ 
                result=crewtime[crew_idx-1]-1;
            }
        }
    }
    string hour=to_string(result/60);
    string minute=to_string(result%60);
    if(hour.size()==1){
        hour="0"+hour;
    }
    if(minute.size()==1){
        minute="0"+minute;
    }
    
    answer=hour+":"+minute;
    
    return answer;
}