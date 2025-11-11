#include <bits/stdc++.h>
#include <vector>

using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> number;
    for(int i=0;i<numbers.size();i++){
        number.push_back(to_string(numbers[i]));
    }
    sort(number.begin(),number.end(),[](string& a, string& b){
        return a + b > b + a;
    });
    for(int i=0;i<number.size();i++){
       answer+=number[i];
    }
    if(answer[0]=='0') return "0";
    
    return answer;
}