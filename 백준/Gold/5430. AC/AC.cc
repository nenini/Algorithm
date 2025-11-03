// #include<iostream>
// #include<string>
// #include<algorithm>
// using namespace std;
// int T;
// string p;
// int n;
// string x;
// // 입력 형식이 올바른지 확인하는 함수
// bool isValidFormat(const string &s) {
//     if (s.front() != '[' || s.back() != ']') return false;
//     if(s.length()>3){
//         for (size_t i = 2; i < s.length() - 1; i++) {
//             if (s[i] != ',') {
//                 return false;
//             }
//             i++;
//         }
//     }
//     return true;
// }
// int main(void)
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     cin >> T;
//     for (int i = 0; i < T;i++){
//         bool check = true;
//         cin >> p;
//         cin >> n;
//         cin >> x;
//         // 입력 형식 검증
//         if (!isValidFormat(x)) {
//             cout << "error\n";
//             continue;
//         }
//         x.erase(remove(x.begin(), x.end(), ','), x.end());
//         x.erase(remove(x.begin(), x.end(), '['), x.end());
//         x.erase(remove(x.begin(), x.end(), ']'), x.end());
//         for (int j = 0; j < p.length();j++){
//             if(p[j]=='R'){
//                 reverse(x.begin(), x.end());
//             }
//             if(p[j]=='D'){  
//                 if(x.length()==0){
//                     cout << "error";
//                     check=false;
//                 }else{
//                     x.erase(0, 1);
//                 }
//             }
//         }
//         if(check==true){
//             cout << "[";
//             for (int i = 0; i < x.length();i++){
//                 cout << x[i];
//                 if(i+1!=x.length()){
//                     cout << ",";
//                 }
//             }
//             cout << "]"<<"\n";
//         }
//     }
// }
#include<iostream>
#include<string>
#include<deque>
#include<algorithm>
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
        int num=0;
        for (int i = 0; i < x.length();i++){
            if (x[i] == '[' || x[i] == ']')
                continue;
            if(x[i]==','){
                d.push_back(num);
                num = 0;
            }
            else
            {
                num = num * 10+ x[i] - '0';
            }
        }
        if(num!=0){
            d.push_back(num);
        }
        //             cout << ">>";
        // for (int i = 0; i < d.size();i++){
        //     cout << d[i];
        // }

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