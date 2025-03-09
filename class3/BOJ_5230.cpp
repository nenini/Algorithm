
#include<iostream>
#include<string>
#include<deque>
#include<algorithm>
#include<sstream>
using namespace std;
int T;
string p;
int n;
string x;
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    for (int j = 0; j < T;j++){
        deque<int> d;
        cin >> p;
        cin >> n;
        cin >> x;
        x = x.substr(1, x.length() - 2);
        stringstream ss(x);
        string num;
        while(getline(ss,num,',')){
            d.push_back(stoi(num));
        }

        bool isReverse = false;
        bool isError = false;
        for (int i = 0; i < p.length();i++){
            if(p[i]=='R'){
                if(isReverse==false){
                    isReverse = true;
                }else{
                    isReverse = false;
                }
            }
            if(p[i]=='D'){
                if(d.empty()){
                    isError = true;
                    break;
                }
                if(isReverse==false){
                    d.pop_front();
                }
                else
                {
                    d.pop_back();
                }
            }
        }
        if(isReverse&& !isError){
            reverse(d.begin(), d.end());
        }
        if(isError){
            cout << "error"<<"\n";
        }
        else{
            cout << "[";
            for (int i = 0; i < d.size();i++){
                if(i!=d.size()-1){
                    cout << d[i] << ",";
                }else{
                    cout << d[i];
                }
            }
            cout << "]"<<"\n";
        }
        
    }
    
}