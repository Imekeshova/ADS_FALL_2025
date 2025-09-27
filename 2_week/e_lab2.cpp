#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string data;
    Node *next;
    Node(string data) {
        this->data = data;
        this->next = NULL;
    }
};

class Stack {
public:
    Node *top;
    int sz;

    Stack() {
        top = NULL;
        sz = 0;
    }

    void push(string data) {
        Node *node = new Node(data);
        node->next = top;
        top = node;
        sz++;
    }

    void pop() {
        if (top != NULL) {
            top = top->next;
            sz--;
        }
    }

    string topElement() {
        if (top != NULL) return top->data;
        return "";
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

    Stack s;
    string prev = "";

    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        if (name != prev) {
            s.push(name);
            prev = name;
        }
    }

    cout << "All in all: " << s.size() << endl;
    cout << "Students:" << endl;

    while (!s.empty()) {
        cout << s.topElement() << endl;
        s.pop();
    }

    return 0;
}