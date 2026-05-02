#include <string>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

bool check(int middle,vector<int> stones, int k){
    int count=0;
    int max_count=0;
    for(int i=0;i<stones.size();i++){
        if((stones[i]-middle+1)<=0){
            count++;
            max_count=max(count,max_count);
        }else{
            
            count=0;
        }
    }
    if(max_count>=k) return false;
    return true;
}

long long binary_search(vector<int> stones, int k){
    int answer;
    long long start=1;
    long long end=200000000;
    while(start<=end){
        int middle=(start+end)/2;
        
        if(check(middle,stones,k)){
            start=middle+1;
            answer=middle;
        }else{
            end=middle-1;
        }
    }
    return answer;
}

int solution(vector<int> stones, int k) {
    int answer = 0;
    answer=binary_search(stones,k);
    return answer;
}