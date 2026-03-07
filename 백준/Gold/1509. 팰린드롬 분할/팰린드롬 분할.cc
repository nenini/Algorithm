#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

string str;
bool is_palindrome[2501][2501];
int dp[2501];

void palindrome(){
    for(int len=1;len<=str.size();len++){
        for(int j=0;j<str.size()-len+1;j++){
            if(len==1){
                is_palindrome[j][j]=true;
            }else if(len ==2){
                if(str[j]==str[j+len-1]){
                    is_palindrome[j][j+len-1]=true;
                }
            }else{
                if(str[j]==str[j+len-1]&&is_palindrome[j+1][j+len-2]){
                    is_palindrome[j][j+len-1]=true;
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>str;
    
    palindrome();
    dp[0]=1;
    for (int i = 1; i < str.size(); i++) {
        if(is_palindrome[0][i]) {
            dp[i]=1;
            continue;
        }
        dp[i]=dp[i-1]+1;
        for (int m = 0; m < i; m++) {
            if(is_palindrome[m+1][i])
                dp[i] = min(dp[i], dp[m] + 1);
            
        }
    }
     cout<<dp[str.size()-1];
    
}