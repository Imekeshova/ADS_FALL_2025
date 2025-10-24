#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int data;
    int count; 
    Node *left;
    Node *right;

    Node(int data) {
        this->data = data;
        count = 1;
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

    // Вставка: если значение уже есть, увеличиваем кратность
    Node* insert(Node *node, int val) {
        if (node == NULL) {
            node = new Node(val);
            return node;
        }

        if (val < node->data) {
            node->left = insert(node->left, val);
        }
        else if (val > node->data) {
            node->right = insert(node->right, val);
        }
        else {
            node->count = node->count + 1;
        }

        return node;
    }

    // Удаление: уменьшаем count или удаляем узел полностью
    Node* remove(Node *node, int val) {
        if (node == NULL) {
            return NULL;
        }

        if (val < node->data) {
            node->left = remove(node->left, val);
        }
        else if (val > node->data) {
            node->right = remove(node->right, val);
        }
        else {
            if (node->count > 1) {
                node->count = node->count - 1;
                return node;
            }

            if (node->left == NULL && node->right == NULL) {
                delete node;
                return NULL;
            }
            else if (node->left == NULL) {
                Node *temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == NULL) {
                Node *temp = node->left;
                delete node;
                return temp;
            }
            else {
                Node *succ = node->right;
                while (succ->left != NULL) {
                    succ = succ->left;
                }

                node->data = succ->data;
                node->count = succ->count;
                succ->count = 1;
                node->right = remove(node->right, succ->data);
            }
        }
        return node;
    }

    // Получение кратности элемента
    int countValue(Node *node, int val) {
        if (node == NULL) {
            return 0;
        }

        if (val < node->data) {
            return countValue(node->left, val);
        }
        else if (val > node->data) {
            return countValue(node->right, val);
        }
        else {
            return node->count;
        }
    }
};

int main() {
    int q;
    cin >> q;

    BST tree;

    for (int i = 0; i < q; i++) {
        string cmd;
        int x;
        cin >> cmd >> x;

        if (cmd == "insert") {
            tree.root = tree.insert(tree.root, x);
        }
        else if (cmd == "delete") {
            tree.root = tree.remove(tree.root, x);
        }
        else if (cmd == "cnt") {
            cout << tree.countValue(tree.root, x) << "\n";
        }
    }

    return 0;
}