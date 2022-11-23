#include<bits/stdc++.h>
using namespace std;

struct Node {
    long long val;
    int idx;
    Node* pre;
    Node* next;
};

const int SIZE = 100005;
int a[SIZE], ans[SIZE], rk[SIZE];
Node* pos[SIZE];
int n;


// 双链表插入模板，在node后面插入新结点
Node* AddNode(Node* node, int idx) {
    Node* newNode = new Node();
    newNode->val = a[idx];
    newNode->idx = idx;
    node->next->pre = newNode; newNode->next = node->next;
    newNode->pre = node; node->next = newNode;
    return newNode;
}

// 双链表删除模板
void DeleteNode(Node* node) {
    node->pre->next = node->next;
    node->next->pre = node->pre;
    delete node;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        rk[i] = i;
    }
    // rk的含义：rank[i]表示排第i名的是谁（是哪个下标）？
    // 有序序列是：a[rk[1]]，a[rk[2]]，... a[rk[n]]
    // a = [1, 5, 3, 4, 2]
    // rk = [1,   5,   3,   4,   2]
    //      a[1] a[5] a[3] a[4] a[2]
    // a[rk] = [1, 2,   3,   4,   5]
    sort(rk + 1, rk + n + 1, [&](int rki, int rkj) { return a[rki] < a[rkj]; });
    // 保护结点
    Node head;
    Node tail;
    head.next = &tail;
    tail.pre = &head;
    head.val = (long long)-1e10;
    tail.val = (long long)1e10;
    for (int i = 1; i <= n; i++) {
        // 数值：a[rk[i]]，下标：rk[i]
        pos[rk[i]] = AddNode(tail.pre, rk[i]);
    }
    for (int i = n; i > 1; i--) {
        Node* curr = pos[i];
        if (a[i] - curr->pre->val <= curr->next->val - a[i]) {
            ans[i] = curr->pre->idx;
        } else {
            ans[i] = curr->next->idx;
        }
        DeleteNode(curr);
    }
    for (int i = 2; i <= n; i++)
        printf("%d %d\n", abs(a[ans[i]] - a[i]), ans[i]);
}