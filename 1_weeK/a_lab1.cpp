#include <iostream>
#include <deque>
using namespace std;

int main(){
    int T;
    cin >> T;

    while(T--){
        int n;
        cin >> n;
        deque <int> dq;

        for (int i = n; i >= 1;i--){
            dq.push_front(i);
            for (int j = 0;j < i; j++ ){
                int x = dq.back();
                dq.pop_back();
                dq.push_front(x);
            }

        }

        for (deque<int> :: iterator it = dq.begin(); it != dq.end(); it++){
            cout << *it << " ";
        }

        cout << endl;
    }


    return 0;

}


