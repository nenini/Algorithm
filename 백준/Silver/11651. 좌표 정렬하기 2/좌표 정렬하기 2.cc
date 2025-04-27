#include <vector>
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
int main(void)
{
    vector<pair<int, int>> v;
    int n, a, b;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        v.push_back(pair<int, int>(b, a));
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        printf("%d %d\n", v[i].second, v[i].first);
    }
}