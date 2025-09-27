#include <iostream> 
using namespace std;
 
struct Node{
    int val;
    Node* next;
    Node(): val(0), next(nullptr) {}
    Node(int x): val(x), next(nullptr) {}
    Node(Node* next): val(0), next(next) {}
    Node(int x, Node* next): val(x), next(next) {}
};
 
Node* insert(Node* head, Node* node, int p){
    if(p == 0){ 
        node->next = head; 
        return node; 
    }
    Node* cur = head;
    for(int i = 0; i < p-1; i++){
        cur = cur->next;
    }
    node->next = cur->next;
    cur->next = node;
    return head;
}
 
Node* remove(Node* head, int p){
    if(p == 0){
        return head->next;
    }
    Node* cur = head;
    for(int i = 0; i < p-1; i++){
        cur = cur->next;
    }
    cur->next = cur->next->next;
    return head;
}
 
Node* replace(Node* head, int p1, int p2){
    if(p1 == p2) return head;
    Node* prev1 = nullptr;
    Node* cur1 = head;
    for(int i = 0; i < p1; i++){
        prev1 = cur1;
        cur1 = cur1->next;
    }
    if(prev1 == nullptr){
        head = cur1->next;
    } else {
        prev1->next = cur1->next;
    }
    cur1->next = nullptr;
    head = insert(head, cur1, p2);
    return head;
}
 
Node* reverse(Node* head){
    Node* prev = nullptr;
    Node* cur = head;
    while(cur != nullptr){
        Node* nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    return prev;
}
 
void print(Node* head){
    if(head == nullptr){
        cout << -1 << endl;
        return;
    }
    Node* cur = head;
    while(cur != nullptr){
        cout << cur->val;
        if(cur->next != nullptr) cout << " ";
        cur = cur->next;
    }
    cout << endl;
}
 
Node* cyclic_left(Node* head, int x){
    if(head == nullptr) return head;
    int len = 0;
    Node* tail = head;
    while(tail->next != nullptr){
        tail = tail->next;
        len++;
    }
    len++;
    x = x % len;
    if(x == 0) return head;
    tail->next = head;
    Node* new_tail = head;
    for(int i = 1; i < x; i++){
        new_tail = new_tail->next;
    }
    Node* new_head = new_tail->next;
    new_tail->next = nullptr;
    return new_head;
}
 
Node* cyclic_right(Node* head, int x){
    if(head == nullptr) return head;
    int len = 0;
    Node* tail = head;
    while(tail->next != nullptr){
        tail = tail->next;
        len++;
    }
    len++;
    x = x % len;
    if(x == 0) return head;
    int left = len - x;
    tail->next = head;
    Node* new_tail = head;
    for(int i = 1; i < left; i++){
        new_tail = new_tail->next;
    }
    Node* new_head = new_tail->next;
    new_tail->next = nullptr;
    return new_head;
}
 
int main(){
    Node* head = nullptr;
    while (true)
    {
        int command; cin >> command;
        if (command == 0){
            break;
        }else if(command == 1){
            int x, p; cin >> x >> p;
            head = insert(head, new Node(x), p);
        }else if (command == 2){
            int p; cin >> p;
            head = remove(head, p);
        }else if (command == 3){
            print(head);
        }else if (command == 4){
            int p1, p2; cin >> p1 >> p2;
            head = replace(head, p1, p2);
        }else if (command == 5){
            head = reverse(head);
        }else if (command == 6){
            int x; cin >> x;
            head = cyclic_left(head, x);
        }else if (command == 7){
            int x; cin >> x;
            head = cyclic_right(head, x);
        }   
    }
    return 0;
}