#include<iostream>
#include<algorithm>
using namespace std;
int L, C;
char arr[15];
char password[15];
int vowel = 0, consonant = 0;
void pw(int num, int index)
{
    if(vowel>=1&&consonant>=2&&num==L){
        for (int i = 0; i < L;i++){
            cout << password[i];
        }
        cout << "\n";
        return;
    }
    for (int i = index; i < C;i++){
        if(arr[i]=='a'||arr[i]=='e'||arr[i]=='i'||arr[i]=='o'||arr[i]=='u'){
            vowel++;
            password[num] = arr[i];
            pw(num + 1, i + 1);
            vowel--;
        }
        else
        {
            consonant++;
            password[num] = arr[i];
            pw(num + 1, i + 1);
            consonant--;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> L >> C;
    for (int i = 0; i < C;i++){
        cin >> arr[i];
    }
    sort(arr, arr + C);
    pw(0, 0);
}