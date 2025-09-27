#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    long long k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // prefix[i] = сумма первых i элементов (prefix[0] = 0)
    vector<long long> prefix(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + a[i - 1];
    }

    int ans = n + 1; // минимальная длина (сделаем заведомо большой)

    for (int i = 0; i < n; i++) {
        int l = i, r = n - 1, best = n; // best = минимальный правый конец

        while (l <= r) {
            int mid = (l + r) / 2;
            long long sum = prefix[mid + 1] - prefix[i];
            if (sum >= k) {
                best = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        if (best < n) {
            int len = best - i + 1;
            if (len < ans) {
                ans = len;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
