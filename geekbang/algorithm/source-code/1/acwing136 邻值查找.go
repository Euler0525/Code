package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"sort"
	"strconv"
	"strings"
)

// 双链表节点
type DoubleNode struct {
	val  int
	idx  int
	pre *DoubleNode
	next *DoubleNode
}

func main() {
	//原始数组节点
	a := []int{}
    originala := []int{}
	// // 结果数组
	var ans [100005]int
	// 记录a数组中的下表
	var rk [100005]int
	// // pos数组，基于rk确定下标，用于快速定位位置
	var pos [100005]*DoubleNode
	var n int;
 
	var inputLines int
	var commands [2]string
	var commandsInt [100005]int64
	// 用来保存a的原始值和位置的信息
	var innerMap map[int]int

	input := bufio.NewScanner(os.Stdin)

    fmt.Printf("Please type in something:\n")

	// 逐行扫描
    for input.Scan() {
        commands[inputLines] = input.Text()
		inputLines ++

        // 输入bye时 结束
        if inputLines == 2 {
			fmt.Println("Input finish, Compute!")
            break
        }
    }
	// 获取输入，进行计算
	// fmt.Println(commands[0]);
	// fmt.Println(commands[1]);
    number,_ := strconv.ParseInt(commands[0], 10, 0)
	n = int(number)
	
	commandTwoElement := strings.Split(commands[1], " ")
	for i:=0; i<len(commandTwoElement); i++{
		commandsInt[i],_ = strconv.ParseInt(commandTwoElement[i], 10, 0)
	} 
	
	// 将输入的commandsInt放入数组a
    a = append(a, 0)
	originala = append(originala, 0)
	for i:=1; i<=n; i++ {
		// 将输入元素保存到a中
		// a[i] = int(commandsInt[i-1])
		a = append(a, int(commandsInt[i-1]))
		// 备份
		originala = append(originala, int(commandsInt[i-1]))
		rk[i] = i
	}

	// 需要将a进行从小到达排序，然后将排完序的每个元素的位置，更新到新的rk数组中，所以这里最好将a的原始位置，先记下来，后续可以基于排序后的值来找位置
	innerMap = make(map[int]int, n+1)
	for i:=1; i<=n; i++ {
		// 将a里面a[i]的值保存下来了
		innerMap[a[i]] = i;
	}
	// 对a进行排序，go语言中需要使用切面进行排序
	sort.Ints(a)

	for i:=1; i<=n; i++ {
		rk[i] = innerMap[a[i]]
		// fmt.Println(rk[i])
	}

	// 保护节点
	head := &DoubleNode{};
	tail := &DoubleNode{};
	head.next = tail
	tail.pre = head
	head.val = -1e10
	tail.val = 1e10

	for i:=1; i<=n; i++ {
		// 分别复制 pos[1], pos[3], pos[2]
		pos[rk[i]] = AddNode(tail.pre, rk[i], originala)
	}
   
	//调式信息
	for i:=n; i>1; i-- {
		curr := pos[i]
		if (originala[i] - curr.pre.val <= curr.next.val - originala[i]) {
			ans[i] = curr.pre.idx
		} else {
			ans[i] = curr.next.idx
		}
		DeleteNode(curr);
	}

	for i:=2; i<=n; i++ {
		fmt.Print(math.Abs(float64(originala[ans[i]]) - float64(originala[i])))
		fmt.Print(" ")
		fmt.Print(ans[i])
		fmt.Print("\n")
	}
}

// 双向链表插入模板
func AddNode(node *DoubleNode, idx int, a []int) *DoubleNode {
	newNode := &DoubleNode{}
	newNode.val = a[idx]
	newNode.idx = idx
	node.next.pre = newNode
	newNode.next = node.next
	newNode.pre = node
	node.next = newNode
	return newNode
}

func DeleteNode(node *DoubleNode) {
	node.pre.next = node.next
	node.next.pre = node.pre	
}