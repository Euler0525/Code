# Python 3
class Node:
    def __self__():
        self.val = 0
        self.idx = 0
        self.pre = None
        self.next = None

a = []
n = 0

# 双链表插入模板，在node后面插入新结点
def AddNode(node, idx):
    newNode = Node()
    newNode.val = a[idx]
    newNode.idx = idx
    node.next.pre = newNode; newNode.next = node.next
    newNode.pre = node; node.next = newNode
    return newNode

def DeleteNode(node):
    node.pre.next = node.next
    node.next.pre = node.pre
    return

if __name__ == "__main__":
    n = int(input())
    a = [0] + list(map(int, input().split()))
    ans = [0] * (n + 1)
    rk = [0] * (n + 1)
    pos = [0] * (n + 1)
    for i in range(1, n + 1):
        rk[i] = i
    '''
    // rk的含义：rank[i]表示排第i名的是谁（是哪个下标）？
    // 有序序列是：a[rk[1]]，a[rk[2]]，... a[rk[n]]
    // a = [1, 5, 3, 4, 2]
    // rk = [1,   5,   3,   4,   2]
    //      a[1] a[5] a[3] a[4] a[2]
    // a[rk] = [1, 2,   3,   4,   5]
    // 从1到n排序
    '''
    rk[1:n+1] = sorted(rk[1:n+1], key=lambda x: a[x])
    # 保护结点
    head = Node()
    tail = Node()
    head.next = tail
    tail.pre = head
    head.val = -1e10
    tail.val = 1e10
    for i in range(1, n + 1):
        # 数值：a[rk[i]]，下标：rk[i]
        pos[rk[i]] = AddNode(tail.pre, rk[i])
    for i in range(n, 1, -1):
        curr = pos[i]
        if a[i] - curr.pre.val <= curr.next.val - a[i]:
            ans[i] = curr.pre.idx
        else:
            ans[i] = curr.next.idx
        DeleteNode(curr)
    for i in range(2, n + 1):
        print(abs(a[ans[i]] - a[i]), ans[i])
    