#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
    deque <int> dq;
    string command;

    while(cin >> command){
        if (command == "+"){
            int x;
            cin >> x;
            dq.push_front(x);
        }
        else if(command == "-"){
            int x;
            cin >> x;
            dq.push_back(x);
        }
        else if (command == "*"){
            if (dq.empty()){
                cout << "error";
            }
            else{
                int sum;
                if (dq.size() == 1){
                    sum = 2 * dq.front();
                    dq.pop_front();
                }
                else{
                    sum = dq.front() + dq.back();
                    dq.pop_front();
                    dq.pop_back();
                }
                cout << sum << endl;

            }
        
        }

        else if(command == "!"){
            break;
        }

    
    }
    return 0;
}
