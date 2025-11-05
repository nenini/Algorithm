#include <bits/stdc++.h>

using namespace std;
int raw_size;
int result1, result0;
vector<vector<int>> copy_arr;
void fun(int x, int y, int size){
    bool check1=false;
    bool check0=false;
    for(int i=x;i<x+size;i++){
        for(int j=y;j<y+size;j++){
            if(copy_arr[i][j]==1) check1=true;
            else check0=true;
            if(check0==check1) break;
        }        
        if(check0==check1) break;
    }
    if(check1==check0){
        fun(x,y,size/2);
        fun(x+size/2,y,size/2);
        fun(x,y+size/2,size/2);
        fun(x+size/2,y+size/2,size/2);
    }else{
        if(check1) result1++;
        else result0++;
    }
}
vector<int> solution(vector<vector<int>> arr) { 
    copy_arr=arr;
    vector<int> answer;
    raw_size=arr[0].size();
    fun(0,0,raw_size);

    answer.push_back(result0);
    answer.push_back(result1);
    return answer;
}