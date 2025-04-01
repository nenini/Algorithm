#include<iostream>
using namespace std;

int N;
int arr[21]={0};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    string command;
    for (int i = 0; i < N;i++){
        cin >> command;
        int x;
        if (command == "add")
        {
            cin >> x;
            if(arr[x]==0){
                arr[x] = 1;
            }
        }else if(command == "remove"){
            cin >> x;
            if(arr[x]==1){
                arr[x] = 0;
            }
        }else if(command=="check"){
            cin >> x;
            if (arr[x] == 1)
            {
                cout << "1\n";
            }
            else
            {
                cout << "0\n";
            }
        }else if(command=="toggle"){
            cin >> x;
            if (arr[x] == 1)
            {
                arr[x] = 0;
            }
            else
            {
                arr[x] = 1;
            }
        }else if(command=="all"){
            for (int i = 1; i <= 20;i++){
                arr[i] = 1;
            }
            // memset(arr, 1, sizeof(arr));
        }else{
            for (int i = 1; i <= 20;i++){
                arr[i] = 0;
            }
            // memset(arr, 0, sizeof(arr));
        }
    }
}