#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int x){
    if (x < 2){
        return false;
    }
    for (int i = 2; i * i <= x; i++){
        if (x % i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    int n;
    cin >> n;

    int num = 2;
    vector <int> primes;

    while (primes.size() < 10000){
        if (isPrime(num)){
            primes.push_back(num);
        }
        num++;
    }

    vector <int> superpuperprimes;

    for (int i = 0; i < primes.size(); i++){
        if (isPrime(i + 1)){
            superpuperprimes.push_back(primes[i]);
        }
    }

    cout << superpuperprimes[n-1] << endl;
    return 0;
}