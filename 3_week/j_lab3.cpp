#include <iostream>
#include <vector>
using namespace std;

bool ok(const vector<long long>& a, long long H, long long K) {
    long long need = 0;
    for (int i = 0; i < (int)a.size(); i++) {
        need += (a[i] + K - 1) / K;   
        if (need > H) {               
            return false;
        }
    }
    return need <= H;
}

int main() {
    int N;
    long long H;
    cin >> N >> H;

    vector<long long> a(N);
    long long lo = 1, hi = 0;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        if (a[i] > hi) {
            hi = a[i];                
        }
    }

    long long ans = hi;
    while (lo <= hi) {
        long long mid = (lo + hi) / 2;   
        if (ok(a, H, mid) == true) {
            ans = mid;                   
            hi = mid - 1;
        } else {
            lo = mid + 1;               
        }
    }

    cout << ans << "\n";
    return 0;