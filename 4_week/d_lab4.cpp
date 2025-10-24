#include <iostream>
#include <vector>
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
    vector<long long> levelSum;
    int maxLevel;

    BST() {
        root = NULL;
        maxLevel = 0;
    }

    // вставка по правилам BST
    Node* insert(Node *node, int val) {
        if (node == NULL) {
            node = new Node(val);
            return node;
        }
        if (val < node->data) {
            node->left = insert(node->left, val);
        } else {
            node->right = insert(node->right, val);
        }
        return node;
    }

    // удобная обёртка для вставки
    void insertValue(int val) {
        root = insert(root, val);
    }

    // DFS: считаем суммы на каждом уровне
    void computeLevelSums(Node *node, int lvl) {
        if (node == NULL) {
            return;
        }
        if (lvl >= (int)levelSum.size()) {
            levelSum.resize(lvl + 1, 0);
        }
        levelSum[lvl] += node->data;
        if (lvl > maxLevel) {
            maxLevel = lvl;
        }
        computeLevelSums(node->left, lvl + 1);
        computeLevelSums(node->right, lvl + 1);
    }

    void calculate() {
        computeLevelSums(root, 0);
    }

    void printResult() {
        cout << maxLevel + 1 << "\n";
        for (int i = 0; i <= maxLevel; i++) {
            cout << levelSum[i] << " ";
        }
        cout << "\n";
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

    tree.calculate();     
    tree.printResult();   

    return 0;
}