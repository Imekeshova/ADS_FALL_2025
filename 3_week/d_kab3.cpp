#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lowerBound(vector<int>& a, int x) {
    int l = 0, r = a.size();
    while (l < r) {
        int m = (l + r) / 2;
        if (a[m] < x) l = m + 1;
        else r = m;
    }
    return l;
}

int upperBound(vector<int>& a, int x) {
    int l = 0, r = a.size();
    while (l < r) {
        int m = (l + r) / 2;
        if (a[m] <= x) l = m + 1;
        else r = m;
    }
    return l;
}

int countInRange(vector<int>& a, int L, int R) {
    if (L > R) return 0;
    return upperBound(a, R) - lowerBound(a, L);
}

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    while (q--) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;

        int c1 = countInRange(a, l1, r1);
        int c2 = countInRange(a, l2, r2);
        int both = countInRange(a, max(l1, l2), min(r1, r2));

        cout << c1 + c2 - both << "\n";
    }
    return 0;
}
