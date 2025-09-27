#include <iostream>
#include <vector>
using namespace std;


bool binary_search(vector<int>& a,int x ){
    int left = 0;
    int right = a.size() - 1;

    while(left <= right) {
        int mid = (left + right) / 2;

        if (a[mid] == x) {
            return true;
        }
        else if (a[mid] < x) {
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    return false;
}



int main() {
    int n;
    cin >> n;

    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int x;
    cin >> x;

    if (binary_search(a, x)) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }

    return 0;
}