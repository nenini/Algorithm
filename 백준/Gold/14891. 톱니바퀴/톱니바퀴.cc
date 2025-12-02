#include <bits/stdc++.h>
using namespace std;
int arr[4][8];
int K, result;
int index1[4];  // 0,1,2,3
void fun(int num, int dir) {
    int temp_index = index1[num - 1];
    // 시계, 반시계 돌림
    if (dir == -1) {
        temp_index += 1;
        if (temp_index >= 8) {
            temp_index -= 8;
        }
    } else {
        temp_index -= 1;
        if (temp_index < 0) {
            temp_index += 8;
        }
    }
    // 오른쪽 회전 톱니 확인
    int r_dir = dir;
    int r_index = index1[num - 1];
    for (int i = num; i < 4; i++) {
        if (r_index + 2 >= 8)
            r_index = r_index + 2 - 8;
        else
            r_index += 2;
        int comp = index1[i] - 2;
        if (comp < 0) comp += 8;
        if (arr[i - 1][r_index] != arr[i][comp]) {
            // 현재 기록
            if (r_dir == 1)
                r_dir = -1;
            else
                r_dir = 1;
            r_index = index1[i];
            // 이동
            if (r_dir == -1) {
                index1[i] += 1;
                if (index1[i] >= 8) {
                    index1[i] -= 8;
                }
            } else {
                index1[i] -= 1;
                if (index1[i] < 0) {
                    index1[i] += 8;
                }
            }
        } else {
            // 톱니 같음
            break;
        }
    }

    int l_dir = dir;
    int l_index = index1[num - 1];
    for (int i = num - 2; i >= 0; i--) {
        if (l_index - 2 < 0)
            l_index = l_index - 2 + 8;
        else
            l_index -= 2;
        int comp = index1[i] + 2;
        if (comp >= 8) comp -= 8;
        if (arr[i + 1][l_index] != arr[i][comp]) {
            if (l_dir == 1)
                l_dir = -1;
            else
                l_dir = 1;
            l_index = index1[i];
            if (l_dir == -1) {
                index1[i] += 1;
                if (index1[i] >= 8) {
                    index1[i] -= 8;
                }
            } else {
                index1[i] -= 1;
                if (index1[i] < 0) {
                    index1[i] += 8;
                }
            }
        } else {
            break;
        }
    }
    index1[num-1]=temp_index;
}

int main() {
    ios::sync_with_stdio(false);
    for (int i = 0; i < 4; i++) {
        string str;
        cin>>str;
        index1[i]=0;
        for (int j = 0; j < 8; j++) {
            
            arr[i][j]=str[j]-'0';
        }
    }
    cin >> K;
    for (int i = 0; i < K; i++) {
        int num, dir;
        cin >> num >> dir;
        fun(num, dir);
    }
    for (int i = 0; i < 4; i++) {
            if (arr[i][index1[i]] == 1) {
                if (i == 0) {
                    result += 1;
                } else if (i == 1) {
                    result += 2;
                } else if (i == 2) {
                    result += 4;
                } else {
                    result += 8;
                }
            }
        
    }
    cout<<result;
}