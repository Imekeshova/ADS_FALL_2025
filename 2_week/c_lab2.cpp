#include <iostream>
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
        front = NULL;
        rear = NULL;
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
            if (front == NULL) {
                rear = NULL;
            }
        }
    }

    
    int frontElement() {
        if (front != NULL) {
            return front->data;
        }
        return -1; // если очередь пуста
    }

    
    bool empty() {
        return sz == 0;
    }

    
    int size() {
        return sz;
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

    int idx = 1;

    
    while (!q.empty()) {
        int val = q.frontElement();
        q.pop();

        if (idx % 2 != 0) { // если элемент нечётный по счёту
            cout << val << " ";
        }
        idx++;
    }

    cout << endl;
    return 0;
}