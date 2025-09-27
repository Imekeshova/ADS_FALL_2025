#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    string s;
    cin >> s;

    int balance = 0;
    stack<char> st;

    for (char c: s){
        if (!st.empty() and st.top() == c){
            st.pop();
            balance--;
        }
        else{
            st.push(c);
            balance++;
        }
    }

    if (balance == 0){
        cout << "YES";
    }
    else{
        cout << "NO";
    }


    return 0;
}