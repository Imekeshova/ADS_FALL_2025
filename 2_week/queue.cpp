#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node *next;


    Node (int data){
        this->data = data;
        this->next = NULL;
    }


};

class Queue{
public: 
    Node *head;
    Node *tail;

    int sz;


    Queue() {
        head = tail = NULL;
        sz = 0;

    }

    void push(int data) {
        Node *node = new Node(data);

        if (tail == NULL){
            head = tail = node;
        }
        else{
            tail->next = node;
            tail = node;
        }

        sz++;
    }

    void pop() {
        if (head != NULL){
            Node *temp = head;
            head = head-> next;

            if (head == NULL){
                tail = NULL;
            }
            delete temp;
            sz--;
        }
    }


    int size (){
        return sz;
    }

    bool empty (){
        if (sz == 0){
            return true;
        }
        else{
            return false;
        }
    }

    int peek (){
        if (head != NULL){
            return head->data;
        }
        else{
            return -1;
        }
    }



    };


int main () {

    
    
    return 0;
}
