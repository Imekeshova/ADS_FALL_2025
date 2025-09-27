# include <iostream>
# include <algorithm>
using namespace std;

struct Node {
    int val;
    Node *next;

    Node() {
        val = 0;
        next = NULL;
    }
};

int findMaxSum(int n, Node *head) {
    int best = head->val;       // лучшая сумма пока
    int cur = head->val;        // текущая сумма
    Node *p = head->next;       // идём дальше по списку

    while (p != NULL) {
        if (cur + p->val > p->val) {
            cur = cur + p->val;   // продолжаем старую подпоследовательность
        } else {
            cur = p->val;         // начинаем новую с этого элемента
        }

        if (cur > best) {
            best = cur;           // обновляем лучший результат
        }

        p = p->next;
    }

    return best;
}

int main() {
    int n;
    cin >> n;

    Node *head, *tail;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        Node *cur = new Node();
        cur->val = x;

        if (i == 1) {
            head = tail = cur;
        } else {
            tail->next = cur;
            tail = cur;
        }
    }

    cout << findMaxSum(n, head) << "\n";
    return 0;
}
