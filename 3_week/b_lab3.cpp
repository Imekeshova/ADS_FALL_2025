#include <iostream>
#include <vector>
using namespace std;

bool can(const vector<long long>& a, int k, long long x) {
    int blocks = 1;
    long long s = 0;
    for (int i = 0; i < (int)a.size(); i++) {
        if (a[i] > x) {
            return false;
        }
        if (s + a[i] <= x) {
            s += a[i];
        } else {
            blocks += 1;
            s = a[i];
        }
    }
    return blocks <= k;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<long long> a(n);
    long long lo = 0, hi = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > lo) {
            lo = a[i];
        }
        hi += a[i];
    }

    while (lo < hi) {
        long long mid = (lo + hi) / 2;
        if (can(a, k, mid) == true) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }

    cout << lo << endl;
    return 0;
}