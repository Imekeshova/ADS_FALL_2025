#include <iostream>
#include <vector>
using namespace std;

struct MaxHeap {
    vector<long long> a;

    // Проверка на пустоту
    bool empty() const {
        return a.empty();
    }

    // Количество элементов
    int size() const {
        return (int)a.size();
    }

    // Индексы в массиве-дереве
    int parent(int i) const {
        return (i - 1) / 2;
    }
    int left(int i) const {
        return 2 * i + 1;
    }
    int right(int i) const {
        return 2 * i + 2;
    }

    // Максимум в куче — это корень
    long long top() const {
        return a[0];
    }

    // Подъём (восстановление вверх)
    void siftUp(int i) {
        while (i > 0) {
            int p = parent(i);
            if (a[p] >= a[i]) {
                break;
            }
            swap(a[p], a[i]);
            i = p;
        }
    }

    // Спуск (восстановление вниз)
    void siftDown(int i) {
        int n = size();
        while (true) {
            int l = left(i);
            int r = right(i);
            int m = i; // индекс наибольшего среди i, l, r

            if (l < n && a[l] > a[m]) {
                m = l;
            }
            if (r < n && a[r] > a[m]) {
                m = r;
            }
            if (m == i) {
                break;
            }
            swap(a[i], a[m]);
            i = m;
        }
    }

    // Вставка элемента
    void push(long long x) {
        a.push_back(x);
        siftUp(size() - 1);
    }

    // Удаление максимума
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
    long long n, x;

    if(!(cin >> n >> x)){
        return 0;
    }

    MaxHeap heap;

    for (long long i = 0; i < n; i++){
        long long k;
        cin >> k;
        if (k > 0){
            heap.push(k);
        }
    }
    
    long long revenue = 0;

    for (long long i = 0; i < x; i++){
        long long k = heap.top();
        heap.pop();

        revenue += k;

        k = k - 1;

        if (k > 0){
            heap.push(k);
        }
    }

    cout << revenue << endl;

    return 0;
}