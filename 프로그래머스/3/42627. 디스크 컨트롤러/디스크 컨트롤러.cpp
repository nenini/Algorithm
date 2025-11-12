#include <bits/stdc++.h>

using namespace std;
int sum=0;
int solution(vector<vector<int>> jobs) {
    int answer = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
    
    sort(jobs.begin(),jobs.end());
    
    int job_count=0, time=0;
    while(job_count<jobs.size()||!pq.empty()){
        if(job_count<jobs.size()&&time>=jobs[job_count][0]){
            pq.push(make_pair(jobs[job_count][1],jobs[job_count][0]));
            job_count++;
            continue;
        }
        if(!pq.empty()){
            time+=pq.top().first;
            sum+=time-pq.top().second;
            pq.pop();
        }else{
            time=jobs[job_count][0];
        }
    }
    answer=sum/jobs.size();
    
    return answer;
}