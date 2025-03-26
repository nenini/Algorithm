#include<iostream>
#include<cmath>
using namespace std;
int A, B;
int cnt = 0;
int result = 1000000;
void dfs(int num, int count)
{
    if(num==B){
        result = min(result, count);
    }
    if(num>B)
        return;
    dfs(num * 2, count+1);
    dfs(num * 10 + 1, count+1);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> A >> B;
    dfs(A, 0);
    if(result==1000000){
        cout << -1;
    }
    else{
        cout << result + 1;
    }
}




#include<iostream>
using namespace std;

int A, B;
int result = 1000000;

void dfs(long long num, int count) {
    if (num == B) {
        result = min(result, count);
        return; // 꼭 return 해줘야 불필요한 연산 안 함
    }
    if (num > B) return;

    dfs(num * 2, count + 1);
    dfs(num * 10 + 1, count + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> A >> B;
    dfs(A, 0);

    if (result == 1000000) cout << -1;
    else cout << result + 1; // 문제에서 요구하는 게 경로 길이라면 +1
}


