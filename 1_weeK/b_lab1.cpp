#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main (){
    int n;
    cin >> n;
    vector<int> v(n);
    stack<int> st;

    for (int i = 0; i < n; i++){
        cin >> v[i];

        while(!st.empty() and st.top() > v[i]){
            st.pop();
        }

        if (st.empty()){
            cout << "-1" <<" ";
        }
        else{
            cout << st.top() << " ";
        }
    
        st.push(v[i]);
    }

    return 0;
}