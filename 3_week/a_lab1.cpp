#include <iostream>
#include <vector>
using namespace std;

int binSearcahASC(const vector<int>& a, int x){
    int l;
    int r = a.size() - 1;

    while (l <= r){
        int m = l + (r-l) / 2;
        if (a[m] == x){
            return m;
        }
        if (a[m] < x){
            l = m + 1; 
        }
        else{
            r = m - 1;
        }

        return -1;
    }

}

int binSearcahDESC(const vector<int>& a, int x){
    int l;
    int r = a.size() - 1;

    while (l <= r){
        int m = l + (r-l) / 2;
        if (a[m] == x){
            return m;
        }
        if (a[m] < x){
            r = m - 1; 
        }
        else{
            l = m + 1;
        }

        return -1;
    }

}


int main(){
    int t;
    cin >> t;

    vector <int> q(t);
    for (int i = 0; i < t; i++){
        cin >> q[i];
    }

    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));


    return 0;
}