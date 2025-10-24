#include <iostream>
#include <vector>
using namespace std;

bool isVowel(char c){
    if (c == 'a' or c == 'e' or c == 'i' or c == 'u' or c == 'o'){
        return true;
    }
    else{
        return false;
    }

}


void quick_sort_vector(vector <char> &a, int l, int r){
    int i = l;
    int j = r;
    char p = a[(l + r)/ 2];
    while(i < j){
        while(a[i] < p){
            i++;
        }
        while (a[j] > p){
            j--;
        }
        if (i <= j){
            char temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }

        if (l < j){
            quick_sort_vector(a, l, j);
        }
        if (i < r){
            quick_sort_vector(a, i, r);
        }

    }
}


int main(){
    int n;
    string s;
    cin >> n;
    cin >> s;

    vector <char> v;
    vector <char> c;

    for (int i = 0; i < s.size(); i ++){
        if (isVowel(s[i])){
            v.push_back(s[i]);
        }
        else{
            c.push_back(s[i]);
        }
    }

    if (!v.empty()){
        quick_sort_vector(v, 0, v.size() - 1);
    }
    if (!c.empty()){
        quick_sort_vector(c, 0, c.size() - 1);
    }

    for (int i = 0; i  < v.size(); i++){
        cout << v[i];
    }
    for (int i = 0; i  < c.size(); i++){
        cout << c[i];
    }

    return 0;
}