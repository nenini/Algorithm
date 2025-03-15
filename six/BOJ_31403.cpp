#include<iostream>
#include<string>
using namespace std;
int main()
{
    string a;
    string b;
    int c;
    cin >> a;
    cin >> b;
    cin >> c;
    string first = a + b;
    cout << stoi(a) + stoi(b) -c<<"\n";
    cout << stoi(first) - c;
}