#include <iostream>
#include<climits>
#include<algorithm>
using namespace std;

int arr[10][10];
int result=INT_MAX;
int one_count=0;
int cnt[5];
bool check_range(int x,int y,int size){
    if(x+size>=10|| y+size>=10) return false;
    return true;
}

bool check_paper(int x,int y,int size){
    if(cnt[size]==5) return false;
    for(int i=x;i<=x+size;i++){
        for(int j=y;j<=y+size;j++){
            if(arr[i][j]==0) return false;
        }
    }
    return true;
}

void fill_paper(int x,int y,int size,int num){
    for (int i = x; i <= x + size; i++) {
        for (int j = y; j <= y + size; j++) {
            arr[i][j]=num;
        }
    }
}


void dfs(int count, int remain){
    if(count>=result) return;
    if(remain==0){
        result=min(result,count);
        return;
    }
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if (arr[i][j] == 1) {
                for (int p = 4; p >=0; p--) {
                    if (check_range(i, j, p) && check_paper(i, j, p)) {
                        cnt[p]++;
                        fill_paper(i, j, p, 0);
                        dfs(count + 1, remain - ((p + 1) * (p + 1)));
                        fill_paper(i, j, p, 1);
                        cnt[p]--;
                    }
                }
                return ;
            }
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cin>>arr[i][j];
            if(arr[i][j]==1) one_count++;
        }
    }

    dfs(0, one_count);
    if(result==INT_MAX) cout<<-1;
    else cout<<result;
}