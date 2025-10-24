#include <iostream>
#include <vector>
using namespace std;

int findBlock(vector <long long>& pref, long long x){
    int l = 0;
    int r = pref.size() - 1;
    while (l < r){
        int m = l + (r - l)/2;
        if (pref[m] < x){
            l = m + 1;
        }
        else{
            r = m;
        }
    }
    return l + 1;
}

int main(){
    int N, M;
    cin >> N >> M;

    vector <long long> pref(N);
    cin >> pref[0];
    for (int i = 0; i < N; i++){
        long long x;
        cin >> x;
        pref[i] = pref[i - 1] + x;
    }

    for (int i = 0; i < M; i++){
        long long line;
        cin >> line;

        cout << findBlock(pref, line);
    }

}