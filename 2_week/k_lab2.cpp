#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node *next;

    Node(char data) {
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

    void push(char data) {
        Node *node = new Node(data);
        if (rear == NULL) {
            front = node;
            rear = node;
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

    char frontElement() {
        if (front != NULL) {
            return front->data;
        } else {
            return '#'; // специальный символ
        }
    }

    bool empty() {
        if (sz == 0) {
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        int freq[26] = {0};
        Queue q;

        for (int i = 0; i < n; i++) {
            char c;
            cin >> c;

            freq[c - 'a']++;
            q.push(c);

            while (!q.empty() && freq[q.frontElement() - 'a'] > 1) {
                q.pop();
            }

            if (!q.empty()) {
                cout << q.frontElement() << " ";
            } else {
                cout << -1 << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
