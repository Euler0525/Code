// BFS拓扑排序模板题
func findOrder(numCourses int, prerequisites [][]int) []int {
	var (
		// 存储边的信息
		edges = make([][]int, numCourses)
		// 关键点，存储每个节点的入度信息
		indeg = make([]int, numCourses)
		// 结果
		result []int
	)

	for _, info := range prerequisites {
		// 初始化课程的所有边和所有课程节点的入度信息
		edges[info[1]] = append(edges[info[1]], info[0])
		indeg[info[0]]++
	}

	q := []int{}
	for i := 0; i < numCourses; i++ {
		// 遍历所有课程，如果当前课程的入度为0，说明这门课的先序课程为0
		if indeg[i] == 0 {
			q = append(q, i)
		}
	}

	for len(q) > 0 {
		// queue的对头出队
		u := q[0]
		q = q[1:]
		result = append(result, u)
		for _, v := range edges[u] {
			// 广度搜索u的所有相邻节点
			indeg[v]--
			if indeg[v] == 0 {
				// 如果v的入度为0，直接加入q即可
				q = append(q, v)
			}
		}
	}
	if len(result) != numCourses {
		return []int{}
	}
	return result
}