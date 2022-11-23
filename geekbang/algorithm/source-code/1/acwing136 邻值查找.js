class Node {
    constructor() {
        this.val = 0;
        this.idx = 0;
        this.pre = null;
        this.next = null;
    }
}

var a = [], ans = [], rk = [], pos = [], n;


// 双链表插入模板，在node后面插入新结点
var AddNode = function(node, idx) {
    let newNode = new Node();
    newNode.val = a[idx];
    newNode.idx = idx;
    node.next.pre = newNode; newNode.next = node.next;
    newNode.pre = node; node.next = newNode;
    return newNode;
};

// 双链表删除模板
var DeleteNode = function(node) {
    node.pre.next = node.next;
    node.next.pre = node.pre;
};

var Solve = function() {
    for (let i = 1; i <= n; i++) {
        rk[i] = i;
    }
    // rk的含义：rank[i]表示排第i名的是谁（是哪个下标）？
    // 有序序列是：a[rk[1]]，a[rk[2]]，... a[rk[n]]
    // a = [1, 5, 3, 4, 2]
    // rk = [1,   5,   3,   4,   2]
    //      a[1] a[5] a[3] a[4] a[2]
    // a[rk] = [1, 2,   3,   4,   5]
    // 从1到n排序
    rk = [0].concat(rk.slice(1, n + 1).sort((rki, rkj) => { return a[rki] - a[rkj]; }));
    // 保护结点
    let head = new Node();
    let tail = new Node();
    head.next = tail;
    tail.pre = head;
    head.val = -1e10;
    tail.val = 1e10;
    for (let i = 1; i <= n; i++) {
        // 数值：a[rk[i]]，下标：rk[i]
        pos[rk[i]] = AddNode(tail.pre, rk[i]);
    }
    for (let i = n; i > 1; i--) {
        let curr = pos[i];
        if (a[i] - curr.pre.val <= curr.next.val - a[i]) {
            ans[i] = curr.pre.idx;
        } else {
            ans[i] = curr.next.idx;
        }
        DeleteNode(curr);
    }
    for (let i = 2; i <= n; i++)
        console.log(Math.abs(a[ans[i]] - a[i]), ans[i]);
};

let buf = '';
process.stdin.on('readable', function () {
    let chunk = process.stdin.read();
    if (chunk) buf += chunk.toString();
});
let getInputNums = line => line.split(' ').filter(s => s !== '').map(x => parseInt(x));
let getInputStr = line => line.split(' ').filter(s => s !== '');

process.stdin.on('end', function () {
    buf.split('\n').forEach(function (line, lineIdx) {
        if (lineIdx === 0) {
            n = getInputNums(line)[0];
        } else if (lineIdx === 1) {
            a = getInputNums(line);
            a.unshift(0); // make index start from 1
            Solve();
        }
    });
});