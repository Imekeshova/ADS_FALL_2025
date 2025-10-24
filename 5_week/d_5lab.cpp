#include <iostream>
#include <vector>
using namespace std;

struct MinHeap {
    vector<long long> a;

    bool empty() const {
        return a.empty();
    }

    int size() const {
        return (int)a.size();
    }

    int parent(int i) const {
        return (i - 1) / 2;
    }

    int left(int i) const {
        return 2 * i + 1;
    }

    int right(int i) const {
        return 2 * i + 2;
    }

    long long top() const {
        return a[0];
    }

    void siftUp(int i) {
        while (i > 0) {
            int p = parent(i);
            if (a[p] <= a[i]) {
                break;
            }
            swap(a[p], a[i]);
            i = p;
        }
    }

    void siftDown(int i) {
        int n = size();
        while (true) {
            int l = left(i);
            int r = right(i);
            int m = i;
            if (l < n && a[l] < a[m]) {
                m = l;
            }
            if (r < n && a[r] < a[m]) {
                m = r;
            }
            if (m == i) {
                break;
            }
            swap(a[i], a[m]);
            i = m;
        }
    }

    void push(long long x) {
        a.push_back(x);
        siftUp(size() - 1);
    }

    void pop() {
        int n = size();
        swap(a[0], a[n - 1]);
        a.pop_back();
        if (!a.empty()) {
            siftDown(0);
        }
    }
};

int main() {
    long long n, m;

    if(!(cin >> n >> m)){
        return 0;
    }

    MinHeap h;

    for(long long i = 0; i < n; i++){
        long long x;
        cin >> x;
        h.push(x);
    }

    long long ops = 0;

    while(!h.empty() and h.top() < m){
        long long a = h.top();
        h.pop();

        long long b = h.top();
        h.pop();

        long long c = a + 2 * b;
        h.push(c);

        ops = ops + 1;

    }

    if (h.size() < 2){
        cout << "-1" << endl;
    }
    else{
        cout << ops << endl;
    }
}