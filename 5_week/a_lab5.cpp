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

    long long top() const {
        return a[0];
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

int main(){
    int n;

    if (!(cin >> n)){
        return 0;
    }

    MinHeap h;

    for (int i = 0; i < n; i++){
        long long x;
        cin >> x;
        h.push(x);
    }
    
    if (n <= 1){
        cout << "0" << endl;
        return 0;
    }
    
    long long cost = 0;

    while (h.size() > 1){
        long long x = h.top();
        h.pop();

        long long y = h.top();
        h.pop();

        long long z =  x + y;
        cost += z;
        h.push(z);
    }
    cout << cost << endl;
    return 0;

}