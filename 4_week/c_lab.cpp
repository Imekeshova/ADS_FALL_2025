#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

class BST {
public:
    Node *root;

    BST() {
        root = NULL;
    }

    // Вставка по правилам BST (дубликаты игнорируем)
    Node* insert(Node *node, int x) {
        if (node == NULL) {
            node = new Node(x);
            return node;
        }
        if (x < node->data) {
            node->left = insert(node->left, x);
        } else if (x > node->data) {
            node->right = insert(node->right, x);
        } else {
            // x == node->data — ничего не делаем
        }
        return node;
    }

    // Поиск узла со значением x
    Node* search(Node *node, int x) {
        if (node == NULL || node->data == x) {
            return node;
        }
        if (x < node->data) {
            return search(node->left, x);
        } else {
            return search(node->right, x);
        }
    }

    // Печать поддерева в порядке pre-order: root, left, right
    void preOrder(Node *node) {
        if (node == NULL) {
            return;
        }
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
};

int main() {
    int n;
    if (!(cin >> n)) return 0;

    BST tree;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        tree.root = tree.insert(tree.root, a);
    }

    int k;
    cin >> k;

    Node *start = tree.search(tree.root, k); // гарантируется, что k есть
    tree.preOrder(start);
    return 0;
}