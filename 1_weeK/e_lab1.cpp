#include <iostream>
#include <queue>
using namespace std;

int main(){
    queue <int> boris, nursik;
    int moves = 0;

    for (int i = 0; i < 5; i++){
        int b;
        cin >> b;
        boris.push(b);
    }

    for (int i = 0; i < 5; i++){
        int n;
        cin >> n;
        nursik.push(n);
    }

    while(true){
        if (moves == 1000000){
            cout << "blin nichya";
            break;
            return 0;
        }
 
        if (boris.size() == 0 or nursik.size() == 0){
            break;
        }


        int bfront = boris.front();
        int nfront = nursik.front();
        boris.pop();
        nursik.pop();

        if (bfront == 9 and nfront == 0){
            nursik.push(bfront);
            nursik.push(nfront);
        }

        else if (nfront == 9 and bfront == 0){
            boris.push(bfront);
            boris.push(nfront);
        }

        else if (nfront < bfront){
            boris.push(bfront);
            boris.push(nfront);
        }

        else if (bfront < nfront){
            nursik.push(bfront);
            nursik.push(nfront);
        }

        ++moves;
    }

    if (boris.size() == 0){
        cout << "Nursik " << moves; 
    }
    else {
        cout << "Boris " << moves;
    }

    return 0;

}