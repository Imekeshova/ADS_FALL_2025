#include <iostream>
#include <vector>
using namespace std;

void quick_sort_desc(vector<long long> &a, int l, int r) {
    int i = l;
    int j = r;
    long long p = a[(l + r) / 2];
    while (i <= j) {
        while (a[i] > p) i++;
        while (a[j] < p) j--;
        if (i <= j) {
            long long t = a[i];
            a[i] = a[j];
            a[j] = t;
            i++;
            j--;
        }
    }
    if (l < j) quick_sort_desc(a, l, j);
    if (i < r) quick_sort_desc(a, i, r);
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<long long>> a(n, vector<long long>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    for (int col = 0; col < m; col++) {
        vector<long long> colvec(n);
        for (int row = 0; row < n; row++) {
            colvec[row] = a[row][col];
        }
        if (n > 1) {
            quick_sort_desc(colvec, 0, n - 1);
        }
        for (int row = 0; row < n; row++) {
            a[row][col] = colvec[row];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}