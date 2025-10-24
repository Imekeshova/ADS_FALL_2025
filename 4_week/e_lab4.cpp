#include <iostream>
#include <queue>
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

    // Вставка по правилам BST
    Node* insert(Node *node, int data) {
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

    // BFS для подсчёта ширины дерева
    int getWidth(Node *node) {
        if (node == NULL) return 0;

        queue<Node*> q;
        q.push(node);
        int maxWidth = 0;

        while (!q.empty()) {
            int levelSize = q.size();
            if (levelSize > maxWidth) {
                maxWidth = levelSize;
            }

            for (int i = 0; i < levelSize; i++) {
                Node *cur = q.front();
                q.pop();

                if (cur->left != NULL) q.push(cur->left);
                if (cur->right != NULL) q.push(cur->right);
            }
        }
        return maxWidth;
    }
};

int main() {
    int n;
    cin >> n;

    BST tree;

    Node* nodes[10005];
    for (int i = 1; i <= n; i++) {
        nodes[i] = new Node(i);
    }

    for (int i = 0; i < n - 1; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        if (z == 0) {
            nodes[x]->left = nodes[y];
        } else {
            nodes[x]->right = nodes[y];
        }
    }

    tree.root = nodes[1];

    cout << tree.getWidth(tree.root) << "\n";
    return 0;
}