#include <bits/stdc++.h>
using namespace std;
pair<int, int> p[26];
int N;
void preorder(char node) {
    if (node == '.') return;
    cout << node;
    preorder(p[node - 'A'].first);
    preorder(p[node - 'A'].second);
}
void inorder(char node) {
    if (node == '.') return;
    inorder(p[node - 'A'].first);
    cout << node;
    inorder(p[node - 'A'].second);
}
void postorder(char node) {
    if (node == '.') return;
    postorder(p[node - 'A'].first);
    postorder(p[node - 'A'].second);
    cout << node;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        char middle, left, right;
        cin >> middle >> left >> right;
        p[middle - 'A'].first = left;
        p[middle - 'A'].second = right;
    }
    preorder('A');
    cout << "\n";
    inorder('A');
    cout << "\n";
    postorder('A');
}