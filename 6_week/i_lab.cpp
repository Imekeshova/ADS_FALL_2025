#include <iostream>
#include <vector>
using namespace std;

void quick_sort(vector<char> &a, int l, int r) {
    int i = l;
    int j = r;
    char p = a[(l + r) / 2];

    while (i <= j) {
        while (a[i] < p) {
            i = i + 1;
        }
        while (a[j] > p) {
            j = j - 1;
        }
        if (i <= j) {
            char t = a[i];
            a[i] = a[j];
            a[j] = t;
            i = i + 1;
            j = j - 1;
        }
    }

    if (l < j) {
        quick_sort(a, l, j);
    }
    if (i < r) {
        quick_sort(a, i, r);
    }
}

int main() {
    string s;
    cin >> s;

    vector<char> a;
    for (int i = 0; i < s.size(); i = i + 1) {
        a.push_back(s[i]);
    }

    if (a.size() > 0) {
        quick_sort(a, 0, a.size() - 1);
    }

    for (int i = 0; i < a.size(); i = i + 1) {
        cout << a[i];
    }

    return 0;
}