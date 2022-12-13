/*
本题目采用DFS在图里的找环模板来实现
主要思路如下：
1）使用map存储图结构
2）使用visited数组来辅助判断某个点是否已经被访问过
3）使用hasCycle变量来判断图中是否有环
4）如果有环，将最近一次使图中出现环的边，进行返回
*/
func findRedundantConnection(edges [][]int) []int {
	// 存储图的结构
	to := make(map[int][]int)
	// 存储某个节点是否被使用过
	visited := make(map[int]bool)
	var hasCycle bool
	// 遍历所有的边
	for _, val := range edges {
		x := val[0]
		y := val[1]
		// 将val[0]和val[1]互相对指，将无向边依次加入to的map中存储
		add(x, y, visited, to)
		add(y, x, visited, to)
		hasCycle = false
		dfs(x, 0, to, visited, &hasCycle)
		if hasCycle == true {
			return val
		}
	}
	return []int{}

}
func add(num1, num2 int, visited map[int]bool, to map[int][]int) {
	// 将nums的元素，加入nums1这个key对应的int切面中
	to[num1] = append(to[num1], num2)
}

// 找环模板
func dfs(x int, fa int, to map[int][]int, visited map[int]bool, hasCycle *bool) {
	visited[x] = true
	for _, y := range to[x] {
		if y == fa {
			continue
		}
		if !visited[y] {
			dfs(y, x, to, visited, hasCycle)
		} else {
			*hasCycle = true
		}
	}
	visited[x] = false
}