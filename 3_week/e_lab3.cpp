#include <iostream>
#include <vector>
using namespace std;

bool can(const vector<int>& x2, const vector<int> y2, int K, int L){
    int cnt = 0;
    for (int i = 0; i < (int)x2.size(); i++){
        if ((x2[i] <= L) & (y2[i] <= L)){
            cnt = cnt + 1;
        } 
    }
    return (cnt >= K);
}

int main(){
    int N, K;
    cin >> N >> K;

    vector <int> x2(N), y2(N);
    int hi = 0;
    
    for (int i = 0; i < N; i++){
        int x1, y1, X2, Y2;
        cin >> x1 >> y1 >> X2 >> Y2;

        x2[i] = X2;
        y2[i] = Y2;

        hi = max(hi, X2);
        hi = max(hi, Y2);
    }

    int lo = 1;
    int ans = hi;

    while(lo <= hi){
        int mid = lo + (hi - lo)/2;
        if (can(x2, y2, K, mid) == true){
            ans = mid;
            hi = mid - 1;
        }
        else{
            lo = mid + 1;
        }

    }

    cout << ans << endl;
    return 0;
}