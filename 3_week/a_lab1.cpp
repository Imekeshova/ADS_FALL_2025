#include <iostream>
#include <vector>
using namespace std;

int binSearchAsc(const vector<int>& a, int x) {
    int l = 0;
    int r = (int)a.size() - 1;

    while (l <= r) {
        int m  = (l + r) / 2;

        if (a[m] == x) {
            return m;
        }

        if (a[m] < x) {              // если серединное число меньше, чем x
            l = m + 1;               // отбрасываем левую часть, идём вправо
        } else {                     // иначе (a[m] > x)
            r = m - 1;               // отбрасываем правую часть, идём влево
        }
    }

    return -1;
}


int binSearchDesc(const vector <int>& a, int x) {
    int l = 0;
    int r = (int)a.size() - 1;

    while(l <= r) {
        int m = (l + r) / 2;

        if (a[m] == x) {
            return m;
        }

        if (a[m] < x) {
            r = m - 1;
        }
        else {
            l = m + 1;
        }
    }
    return -1;
}

int main(){
    int t;
    cin >> t;

    vector <int> q(t);
    for (int i = 0; i < t; i++) {
        cin >> q[i];
    }

    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    for (int qi = 0; qi < t; qi++) {
        int x = q[qi];
        bool found = false;

        for (int i = 0; i < n; i++) {
            int j;

            if (i % 2 == 1) {
                j = binSearchAsc(a[i], x);
            }
            else {
                j = binSearchDesc(a[i], x);
            }

            if (j != -1) {
                cout << i << " " << j << endl;
                found = true;
                break;
            }
        }

        if (found == false) {
            cout << "-1" << endl;
            

        }
    }

    return 0;
}