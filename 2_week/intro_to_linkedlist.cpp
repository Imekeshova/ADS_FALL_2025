#include <iostream>
using namespace std;

// class Node{
//     public:
//     int data;
//     Node *next;

//     Node (int data){
//         this->data = data;
//         this->next = NULL;
//     }

// };

// class Stack{
//     public:
//     Node *top;
//     int sz;

//     Stack(){
//         top = NULL;
//         sz = 0;
//     }

//     void push(int data){
//         Node *node = new Node(data);
//         node->next = top;
//         top = node;
//         sz++;
//     }

//     void pop(){
//         if (top != NULL){
//             top = top->next;
//             sz--;
//         }
//     }

//     int size(){
//         return this->sz;
//     }

//     bool empty() {
//         return (sz == 0);
//     }
// };

// class Node {
//     public:
//     char data;
//     Node *next;

//     Node (char data){
//         this->data = data;
//         this->next = NULL;
//     }
// };

// class Stack {
//     public:
//     Node *top;
//     int sz;

//     Stack(){
//         top = NULL;
//         sz = 0;
//     }

//     void push(char data){
//         Node *node = new Node(data);
//         node->next = top;
//         top = node;
//         sz++;
//     }

//     void pop(){
//         if (sz != NULL){
//             Node *temp = top;
//             top = top->next;
//             delete temp;
//             sz--;
//         }

//     }
    
//     char peek(){
//         if (top != NULL){
//             return top->data;
//         }
//         return '\0';
//     }

//     bool empty( ) {
//         return (sz == 0);
//     }
// };

// bool isBalanced (string s){
//     Stack st;

//     for (int i = 0; i < s.size(); i++){
//         char c = s[i];

//         if (c == '(' || c == '{' || c == '[') {
//             st.push(c);
//         }

//         else if (c == ')' || c == '}' || c == ']'){
//             if (st.empty()){
//                 return false;
//             }

//             char top = st.peek();

//             if ((c == ')' && top == '(' ) or (c == '}' && top == '{') or (c == ']' && top == '[')) {
//                 st.pop();
//             }
//             else {
//                 return false;
//             }
//         }

//     }
//    return st.empty(); 
// }

    

// int main(){
//     string s;
//     cin >> s;

//     if (isBalanced(s)) {
//         cout << "YES";
//     }
//     else {
//         cout << "NO";
//     }

//     return 0;
// }


class Node{
    public:
    int data;
    Node *next, *prev;

    Node (int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

class LinkedList {
    public:
    Node *tail, *front;

    LinkedList() {
        tail = NULL;
        front = NULL;
    }

    void push_back(int data) {
        Node *node = new Node(data);
        if (tail == NULL){
            tail = node;
            front = node;
        }
        else {
            node->prev = tail;
            tail->next = node;
            tail = node;
        }
    }

    void push_front(int data) {
        Node *node = new Node(data);
        if (front == NULL){
            tail = node;
            front = node;
        }
        else {
            front->prev = node;
            node->next = front;
            front = node;
        }
    }

    void pop_back() {
        if (tail != NULL) {
            tail = tail->prev;
            if (tail != NULL){
                tail->next = NULL;
            }
            else{
                front = NULL;
            }
        }
    }

    void pop_front(){
        if (front != NULL){
            front = front->prev;
            if (front != NULL){
                front->prev = NULL;
            }
            else{
                tail = NULL;
            }
        }
    }

    void del_node(Node *node) {
        if (node == tail){
            pop_back;
        }
        else if (node == front){
            pop_front;
        }
        else{
            Node *a = node->prev;
            Node *b = node->next;
            a->next = b;
            b->next = a;
        }
    }

    void print(){
        Node *node = front;
        while (node != NULL){
        cout << node->data << " ";
        node = node->next;
        }
        cout << endl;
    }

    Node* find_node(int data){
        Node *node = front;
        while (node != NULL) {
            if (node->data == data){
                return node;
            }
            node = node->next;
        }
        return NULL;
    }

};

