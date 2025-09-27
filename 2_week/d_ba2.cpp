#include <iostream>
#include <algorithm>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class Queue {
public:
    Node *front;
    Node *rear;
    int sz;

    Queue() {
        front = rear = NULL;
        sz = 0;
    }

    void push(int data) {
        Node *node = new Node(data);
        if (rear == NULL) {
            front = rear = node;
        } else {
            rear->next = node;
            rear = node;
        }
        sz++;
    }

    void pop() {
        if (front != NULL) {
            front = front->next;
            sz--;
            if (front == NULL) rear = NULL;
        }
    }

    int frontElement() {
        if (front != NULL) return front->data;
        return -1;
    }

    bool empty() {
        return sz == 0;
    }
};

int main() {
    int n;
    cin >> n;

    Queue q;
    int a[1005] = {0};

   
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.push(x);
        a[i] = x; 
    }

    
    int freq[1001] = {0};
    for (int i = 0; i < n; i++) {
        freq[a[i]]++;
    }

    
    int maxFreq = 0;
    for (int i = 1; i <= 1000; i++) {
        if (freq[i] > maxFreq) maxFreq = freq[i];
    }

    
    for (int i = 1000; i >= 1; i--) {
        if (freq[i] == maxFreq) cout << i << " ";
    }
    cout << endl;

    return 0;
}