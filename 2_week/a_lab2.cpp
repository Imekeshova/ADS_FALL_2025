#include <iostream>
#include <climits>
#include <cstdlib>
using namespace std;

class Node{
public:
    long long data;
    Node *next;
    
    Node(long long data){
        this->data = data;
        this->next = NULL;
    }
};
class Queue{
public:
    Node *front, *rear;
    int sz;

    Queue(){
        front = rear = NULL;
        sz = 0;
    }

    void push(long long data){
        Node* node = new Node(data);
        if (rear == NULL){
            front = node;
            rear  = node;
        }
        else{
            rear-> next = node;
            rear        = node;
        }
        sz++;
    }

    void pop(){
        if (front != NULL){
            front = front->next;
            sz--;
            if (front == NULL){
                rear = NULL;
            }
        }
        
    }
    long long frontElement(){
        if (front != NULL){
            return front->data;
        }
        else{
          return -1;  
        }
    }

    int size(){
        return sz;
    }

    bool empty(){
        return sz == 0;
    }

};

int main(){
    int n;
    cin >> n;

    Queue q;

    for (int  i = 0; i < n; i++){
        long long x;
        cin >> x;
        q.push(x);
    }

    long long k;
    cin >> k;

    long long bestDiff = LLONG_MAX;
    
    int bestIdx = 0;
    int idx = 0;
    
    while (!q.empty()){
        long long x = q.frontElement();
        q.pop();

        long long diff = llabs(x - k);
        if (diff < bestDiff){
            bestDiff = diff;
            bestIdx = idx;
        }
        idx++;

    }

    cout << bestIdx << endl;
    return 0;
}