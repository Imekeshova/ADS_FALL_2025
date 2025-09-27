#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class Queue {
public:
    Node *front, *rear;
    int sz;

    Queue() {
        front = rear = NULL;
        sz = 0;
    }

    void push(int data) {
        Node* node = new Node(data);
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
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.push(x);
    }

    int val, pos;
    cin >> val >> pos;

    Queue newQ;
    int idx = 0;

    while (!q.empty()) {
        if (idx == pos) newQ.push(val);
        newQ.push(q.frontElement());
        q.pop();
        idx++;
    }

    if (pos == n) newQ.push(val);

    Node* cur = newQ.front;
    while (cur != NULL) {
        cout << cur->data << " ";
        cur = cur->next;
    }
}
