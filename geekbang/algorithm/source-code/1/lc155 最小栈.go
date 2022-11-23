	// 定义栈和最小栈两个内部辅助数组，利用下标的方式来模拟栈
	type MinStack struct {
		stack    []int
		minStack []int
	}

	// 初始化两个内部数据结构
	func Constructor() MinStack {
		return MinStack{
			stack:    []int{},
			minStack: []int{math.MaxInt64},
		}
	}

	// 同时放入内部栈和内部最小栈
	func (this *MinStack) Push(x int) {
		this.stack = append(this.stack, x)
		top := this.minStack[len(this.minStack)-1]
		this.minStack = append(this.minStack, min(x, top))
	}

	// 同时弹出内部栈和内部最小栈
	func (this *MinStack) Pop() {
		this.stack = this.stack[:len(this.stack)-1]
		this.minStack = this.minStack[:len(this.minStack)-1]
	}

	// 返回内部栈顶元素
	func (this *MinStack) Top() int {
		return this.stack[len(this.stack)-1]
	}

	// 返回内部最小栈顶元素
	func (this *MinStack) GetMin() int {
		return this.minStack[len(this.minStack)-1]
	}

	// 辅助函数
	func min(x, y int) int {
		if x < y {
			return x
		}
		return y
	}