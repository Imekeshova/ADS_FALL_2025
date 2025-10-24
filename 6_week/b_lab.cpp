#include <iostream>
#include <vector>
using namespace std;

void quick_sort_vector(vector <long long> &a, int l, int r){
    int i = l;
    int j = r;
    long long p = a[(l+r)/ 2];
    while (i < j){
        while(a[i] < p){
            i++;
        }
        while(a[j] > p){
            j--;
        }
        if (i <= j){
            long long temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    vector <long long> v1(n), v2(m);

    for(int i = 0; i < n; i++){
        cin >> v1[i];
    }

    for(int i = 0; i < m; i++){
        cin >> v2[i];
    }

    if (!v1.empty()){
        quick_sort_vector(v1, 0, (int)v1.size() - 1);
    }

    if (!v2.empty()){
        quick_sort_vector(v2, 0, (int)v2.size() - 1);
    }

    size_t i = 0;
    size_t j = 0;

    while (i < v1.size() and j < v2.size()){
        if (v1[i] == v2[j]){
            cout << v1[i] << " ";
            i++;
            j++;
        }
        else if (v1[i] < v2[j]){
            i++;
        }
        else{
            j++;
        }
    }

 
    return 0;
}