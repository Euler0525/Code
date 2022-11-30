// 这种X数之和的问题，需要优先想到，可以使用空间换时间的思想，将X-1层的计算先缓存起来
func twoSum(nums []int, target int) []int {
	// 使用hash表的目的是可以把基于key的查询的复杂度降到1，这里的key使用的是已经遍历过的师叔祖元素
	hashTable := map[int]int{}
	for i, x := range nums {
		// 【2，7，11，15】，需要找和为9，举例，到7，发现9-7=2已经在哈希表中了，说明两数之和可以匹配
		if p, ok := hashTable[target-x]; ok {
			return []int{p, i}
		}
		// 否则就放入hash表样本中，等待后续尝试即可
		hashTable[x] = i
	}
	return nil
}