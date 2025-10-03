#include <bits/stdc++.h>
using namespace std;
int N;
bool visited[9];
vector<int> vct;
void fun() {
    if (vct.size() == N) {
        for (int j = 0; j < N; j++) {
            cout << vct[j] << " ";
        }
        cout << "\n";
        return;
    }
    for (int j = 1; j <= N; j++) {
        if (!visited[j]) {
            vct.push_back(j);
            visited[j] = true;
            fun();
            visited[j] = false;
            vct.pop_back();
        }
    }
}
int main() {
    cin >> N;
    fun();
}