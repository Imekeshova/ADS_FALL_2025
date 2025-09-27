#include <iostream>
#include <string>
using namespace std;

string fix(string s){
    string res = "";
    for (char c : s){
        if (c == '#'){
            if (!res.empty()){
                res.pop_back();
            }
        }
        else{
            res.push_back(c);
        }
    }
    return res;
}

int main() {
    string a,b;
    cin >> a >> b;

    if (fix(a) == fix(b)){
        cout << "Yes";
    }
    else{
        cout << "No";
    }
    
}