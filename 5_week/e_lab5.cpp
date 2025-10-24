#include <iostream>
#include <vector>
#include <string>
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

int main (){
    int q;
    long long k;

    if(!(cin >> q >> k)){
        return 0;
    }

    MinHeap heap;

    long long sum = 0;
    
    for (int i = 0; i < q; i++){
        string cmd;
        cin >> cmd;

        if (cmd == "insert"){
            long long n;
            cin >> n;
            
            if (heap.size() < k){
                heap.push(n);
                sum = sum + n;

            }
            else if (n > heap.top()){
                sum = sum - heap.top();
                heap.pop();
                heap.push(n);
                sum = sum + n;
            }
        }
        else if( cmd == "print"){
            cout << sum << endl;
        }
    }

    return 0;

}