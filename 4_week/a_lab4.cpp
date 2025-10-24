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

    // вставка узла — O(log n) в среднем
    Node *insert(Node *node, int data) {
        if (node == NULL) {
            node = new Node(data);
            return node;
        }

        if (data < node->data) {
            node->left = insert(node->left, data);
        } else if (data > node->data) {
            node->right = insert(node->right, data);
        }
        return node;
    }

    // проверяем, существует ли путь по строке из L и R
    bool pathExists(const string &path) {
        Node *cur = root;
        for (int i = 0; i < path.size(); i++) {
            if (cur == NULL) {
                return false;
            }
            if (path[i] == 'L') {
                cur = cur->left;
            } else if (path[i] == 'R') {
                cur = cur->right;
            }
        }
        return cur != NULL;
    }
};

int main() {
    int N, M;
    cin >> N >> M;

    BST tree;

    // строим BST
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        tree.root = tree.insert(tree.root, x);
    }

    // проверяем каждый путь
    for (int i = 0; i < M; i++) {
        string s;
        cin >> s;
        if (tree.pathExists(s)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}