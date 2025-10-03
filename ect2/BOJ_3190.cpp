#include <bits/stdc++.h>
using namespace std;
int N, K, L;
bool arr[101][101];
bool body[101][101];
int result;
int direction = 2;  // 0-L,1-D,2-R,3-U
pair<int, int> tail;
pair<int, int> head;
vector<pair<int, char> > direct;
deque<pair<int, int> > snake;
bool fun(int num) {
    if (num == 0)      head = make_pair(head.first,     head.second - 1); // L
    else if (num == 1) head = make_pair(head.first + 1, head.second    ); // D
    else if (num == 2) head = make_pair(head.first,     head.second + 1); // R
    else               head = make_pair(head.first - 1, head.second    ); // U

    if (head.first < 1 || head.first > N || head.second < 1 || head.second > N) return false;

    bool eats = arr[head.first][head.second]; //사과 있음
    if (body[head.first][head.second]) {
        // cout << "충돌" << "\n";
        return false;
        // pair<int, int> tailCell = snake.back();
        // bool enteringMovingTail = (!eats) && (head == tailCell);
        // if (!enteringMovingTail) {
        //     cout << "충돌" << "\n";
        //     return false;}
    }

    snake.push_front(head);
    body[head.first][head.second] = true;

    if (eats) {
        //사과 먹음
        arr[head.first][head.second] = false;
    } else {
        //사과 못먹음
        pair<int, int> t = snake.back();
        body[t.first][t.second] = false;
        snake.pop_back();
    }

    tail = snake.back();
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> K;
    body[1][1] = true;
    for (int i = 0; i < K; i++) {
        int x, y;
        cin >> x >> y;
        arr[x][y] = true;
    }
    cin >> L;
    tail = make_pair(1, 1);
    head = make_pair(1, 1);
    snake.push_front(make_pair(1, 1));
    for (int i = 0; i < L; i++) {
        int X;
        char C;
        cin >> X >> C;
        direct.push_back(make_pair(X, C));
    }
    for (int i = 0; i < direct.size(); i++) {
        int X = direct[i].first;
        char C = direct[i].second;
        int step = X - result;
        for (int j = 0; j < step; j++) {
            result++;
            if (!fun(direction)) {
                cout << result;
                return 0;
            }
            // cout << X << "\n";
            // cout << "1. " << head.first << "-" << head.second << "\n";
            // cout << "2. " << tail.first << "-" << tail.second << "\n";
        }
        // cout << X << "\n";
        // cout << "1. " << head.first << "-" << head.second << "\n";
        // cout << "2. " << tail.first << "-" << tail.second << "\n";
        if (C == 'L')
            direction = (direction + 1) % 4;  // 왼쪽은 +1
        else
            direction = (direction + 3) % 4;  // 오른쪽(D)은 -1
    }
    while (true) {
        result++;
        if (!fun(direction)) {
            cout << result;
            return 0;
        }
    }
}