#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main (){
    queue <int> s_que, k_que;

    int n;
    cin >> n;

    string s;
    cin >> s;

    for (int i = 0; i < n; i++){
        if (s[i] =='S'){
            s_que.push(i);
        }
        else{
            k_que.push(i);
        }
    }

    while (!s_que.empty() and !k_que.empty()) {
        int s_front = s_que.front();
        s_que.pop();

        int k_front = k_que.front();
        k_que.pop();

        if(s_front < k_front){
            s_que.push(s_front + n);
        }
        else{
            k_que.push(k_front + n);
        }
    }

    if (!s_que.empty()){
        cout << "SAKAYANAGI";
    }
    else{
        cout << "KATSURAGI";
    }



    return 0;
}
