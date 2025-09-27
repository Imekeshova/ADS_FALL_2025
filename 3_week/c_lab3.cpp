#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end()); // сортируем один раз

    auto countIn = [&](long long L, long long R) -> int {
        if (L > R) {
            return 0;
        }
        int left = int(lower_bound(a.begin(), a.end(), L) - a.begin());
        int right = int(upper_bound(a.begin(), a.end(), R) - a.begin());
        return right - left; // сколько чисел в [L, R]
    };

    while (q--) {
        long long l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;

        int c1 = countIn(l1, r1);
        int c2 = countIn(l2, r2);
        long long L = max(l1, l2);
        long long R = min(r1, r2);
        int cBoth = countIn(L, R); // пересечение

        cout << (c1 + c2 - cBoth) << "\n";
    }
    return 0;
}
