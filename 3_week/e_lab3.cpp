#include <iostream>
#include <vector>
using namespace std;

bool can(const vector<int>& x2, const vector<int>& y2, int K, int L) {
    int cnt = 0;
    for (int i = 0; i < (int)x2.size(); i++) {
        if (x2[i] <= L && y2[i] <= L) {
            cnt += 1;
        }
    }
    return cnt >= K;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<int> x2(N), y2(N);
    int hi = 0;

    for (int i = 0; i < N; i++) {
        int x1, y1, X2, Y2;
        cin >> x1 >> y1 >> X2 >> Y2;   // x1<X2, y1<Y2, все положительные
        x2[i] = X2;
        y2[i] = Y2;
        if (X2 > hi) { hi = X2; }
        if (Y2 > hi) { hi = Y2; }
    }

    int lo = 1;            // можно и 0; при K>=1 ответ все равно >=1
    int ans = hi;

    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (can(x2, y2, K, mid) == true) {
            ans = mid;
            hi = mid - 1;  // пробуем меньше
        } else {
            lo = mid + 1;  // мало — увеличиваем квадрат
        }
    }

    cout << ans << "\n";
    return 0;
}
