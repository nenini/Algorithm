#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int h, m, s, q;
    cin >> h >> m >> s;
    cin >> q;

    // 시간을 초 단위로 변환
    long long total_seconds = h * 3600 + m * 60 + s;

    for (int i = 0; i < q; i++) {
        int T, c;
        cin >> T;

        if (T == 1) {
            cin >> c;
            total_seconds = (total_seconds + c) % 86400; // 24시간 초과 방지
        }
        else if (T == 2) {
            cin >> c;
            total_seconds = (total_seconds - c % 86400 + 86400) % 86400; // 24시간 아래로 떨어지지 않게 보정
        }
        else if (T == 3) {
            int hh = total_seconds / 3600;
            int mm = (total_seconds % 3600) / 60;
            int ss = total_seconds % 60;
            cout << hh << " " << mm << " " << ss << "\n";
        }
    }

    return 0;
}
