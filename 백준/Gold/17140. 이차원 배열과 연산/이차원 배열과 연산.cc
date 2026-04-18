#include <math.h>

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int r, c, k;
vector<vector<int>> arr;
int max_row = 3;
int max_col = 3;

struct cmp {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second != b.second) return a.second < b.second;
        return a.first < b.first;
    }
};

vector<int> make_line(vector<int> temp) {
    vector<int> nums;
    for (int i = 0; i < temp.size(); i++) {
        if (temp[i] != 0) nums.push_back(temp[i]);
    }

    vector<int> result;
    if (nums.empty()) return result;

    sort(nums.begin(), nums.end());

    int cur = nums[0];
    int cnt = 1;
    vector<pair<int, int>> vct;

    for (int i = 1; i < nums.size(); i++) {
        if (cur != nums[i]) {
            vct.push_back({cur, cnt});
            cur = nums[i];
            cnt = 1;
        } else {
            cnt++;
        }
    }
    vct.push_back({cur, cnt});

    sort(vct.begin(), vct.end(), cmp());

    for (int i = 0; i < vct.size(); i++) {
        result.push_back(vct[i].first);
        if (result.size() == 100) break;
        result.push_back(vct[i].second);
        if (result.size() == 100) break;
    }

    return result;
}

void col_sort() {
    vector<vector<int>> new_arr;
    int m_row = 0;

    for (int i = 0; i < max_col; i++) {
        vector<int> temp;
        for (int j = 0; j < max_row; j++) {
            temp.push_back(arr[j][i]);
        }

        vector<int> line = make_line(temp);
        new_arr.push_back(line);
        m_row = max(m_row, (int)line.size());
    }

    if (m_row > 100) m_row = 100;

    vector<vector<int>> result(m_row, vector<int>(max_col, 0));

    for (int i = 0; i < max_col; i++) {
        for (int j = 0; j < new_arr[i].size() && j < 100; j++) {
            result[j][i] = new_arr[i][j];
        }
    }

    arr = result;
    max_row = m_row;
}

void row_sort() {
    int m_col = 0;
    vector<vector<int>> new_arr;

    for (int i = 0; i < max_row; i++) {
        vector<int> line = make_line(arr[i]);
        new_arr.push_back(line);
        m_col = max(m_col, (int)line.size());
    }

    if (m_col > 100) m_col = 100;

    for (int i = 0; i < new_arr.size(); i++) {
        while (new_arr[i].size() < m_col) {
            new_arr[i].push_back(0);
        }
        if (new_arr[i].size() > 100) new_arr[i].resize(100);
    }

    arr = new_arr;
    max_col = m_col;
}

void simulation() {
    if (max_row >= max_col) {
        row_sort();
    } else {
        col_sort();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> r >> c >> k;
    for (int i = 0; i < 3; i++) {
        vector<int> row;
        for (int j = 0; j < 3; j++) {
            int n;
            cin >> n;
            row.push_back(n);
        }
        arr.push_back(row);
    }

    for (int t = 0; t <= 100; t++) {
        if (r - 1 < max_row && c - 1 < max_col && arr[r - 1][c - 1] == k) {
            cout << t;
            return 0;
        }

        if (t == 100) break;
        simulation();
    }

    cout << -1;
}