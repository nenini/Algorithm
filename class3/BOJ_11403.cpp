//플로이드-와샬
#include<iostream>
using namespace std;
int N;
int arr[101][101];
int main()
{
    cin >> N;
    for (int i = 0; i < N;i++){
        for (int j = 0; j < N;j++){
            cin>>arr[i][j];
        }
    }
    //거쳐가는 노드
    for (int i = 0; i < N;i++){
        //출발 노드
        for (int j = 0; j < N;j++){
            //도착 노드
            for (int k = 0; k < N;k++){
                if(arr[j][i]==1&&arr[i][k]==1){
                    arr[j][k] = 1;
                }
            }
        }
    }
    for (int i = 0; i < N;i++){
        for (int j = 0; j < N;j++){
            if(j+1==N){
                cout << arr[i][j];
            }else{
                cout<< arr[i][j]<<" ";
            }
        }
        cout << "\n";
    }
}