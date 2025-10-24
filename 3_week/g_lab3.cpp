#include <iostream>
#include <vector>
using namespace std;


int main(){
    int n, f;
    cin >> n >> f;

    vector <int> c(n);
    int maxC = 0;
    for (int i = 0; i < n; i++){
        cin >> c[i];
        if (c[i] > maxC){
            maxC = c[i];
        }
    }

    int low = 1, high = maxC;
    while(low < high){
        int mid = low + (high - low)/2;
        int flights = 0;
        for (int i = 0; i < c.size(); i++){
            int x = c[i];
            flights += (x + mid - 1)/mid;
        }
        if (flights <= f){
            high = mid;
        }
        else{
            low = mid + 1;
        }
    }
    cout << low << endl;
}