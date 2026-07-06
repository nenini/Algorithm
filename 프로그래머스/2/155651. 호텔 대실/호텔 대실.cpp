#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
using namespace std;

priority_queue<int, vector<int> ,greater<int>> pq;
int result=0;
struct Compare{
    bool operator()(const vector<string>& a, const vector<string>& b){
        return a[0]<b[0];
    }
};

int to_minute(string t){
    return stoi(t.substr(0,2))*60+stoi(t.substr(3,5));
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    sort(book_time.begin(), book_time.end(), Compare());
    for(int i=0;i<book_time.size();i++){
        
        int start=to_minute(book_time[i][0]);
        int end=to_minute(book_time[i][1]);
        
        if(!pq.empty()&&pq.top()<=start){
            pq.pop();
        }
        
        pq.push(end+10);
    }
    return pq.size();
}