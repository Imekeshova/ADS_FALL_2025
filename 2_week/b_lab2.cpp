#include <iostream>
#include <string>
using namespace std;

class Node{
public:
    string data;
    Node *next;

    Node(string data){
        this->data = data;
        this->next = NULL;

    }
};

class Queue{
public:
    Node* front;
    Node* rear;
    int sz;

    Queue(){
        front = NULL;
        rear = NULL;
        sz = 0;

    }
    void push(string data){
        Node *node = new Node(data);
        if (rear == NULL){
            front = rear = node;
        }
        else{
            rear->next   = node;
            rear         = node;
        }
        sz++;
    }

    string pop() {
        if (front == NULL){
            return "";
        }
        Node *t = front;
        string value= t->data;
        front = front->next;
        if (front == NULL){
            rear = NULL;
        }
        delete t;
        sz--;
        return value;
    }
    bool empty(){
        return sz == 0;
    }

};



int main(){
    int n, k;

    cin >> n >> k;

    Queue q;
    for(int i = 0; i < n; i++){
        string word;
        cin >> word;
        q.push(word);
    }
    k = k % n;
    for (int i = 0; i < k; i++){
        string first = q.pop();
        q.push(first);
    }

    while(!q.empty()){
        string x = q.pop();
        cout << x;
        if (!q.empty()){
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}
