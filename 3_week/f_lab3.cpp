#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    vector<long long> pref(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        pref[i] = pref[i - 1] + a[i - 1];
    }

    int P;
    cin >> P;
    for (int i = 0; i < P; i++) {
        int M;
        cin >> M;
        int cnt = int(upper_bound(a.begin(), a.end(), M) - a.begin()); // ≤ M
        cout << cnt << " " << pref[cnt] << "\n";
    }
    return 0;
}
