#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node *left;
    Node *right;

    Node(int v) {
        val = v;
        left = right = NULL;
    }
};

class BST {
public:
    Node *root;

    BST() {
        root = NULL;
    }

    // Вставка нового узла
    Node* insert(Node* node, int v) {
        if (node == NULL) {
            return new Node(v);
        }
        if (v < node->val) {
            node->left = insert(node->left, v);
        } else {
            node->right = insert(node->right, v);
        }
        return node;
    }

    void insertValue(int v) {
        root = insert(root, v);
    }

    //  Найти узел по значению
    Node* find(Node* node, int target) {
        if (node == NULL || node->val == target) {
            return node;
        }
        if (target < node->val) {
            return find(node->left, target);
        } else {
            return find(node->right, target);
        }
    }

    Node* findValue(int target) {
        return find(root, target);
    }

  
    int subtreeSize(Node* node) {
        if (node == NULL) return 0;
        return 1 + subtreeSize(node->left) + subtreeSize(node->right);
    }
};

int main() {
    int n;
    cin >> n;

    BST tree;

    
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        tree.insertValue(x);
    }

    int target;
    cin >> target;

    Node* node = tree.findValue(target);
    cout << tree.subtreeSize(node) << endl;

    return 0;
}
