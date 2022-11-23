func merge(nums1 []int, m int, nums2 []int, n int) {
	// 转换思路，从末尾开始往前
	index := len(nums1) - 1
	// 分别从两个输入数组的末尾开始遍历
	m = m - 1
	n = n - 1
	for m >= 0 && n >= 0 {
		num1 := nums1[m]
		num2 := nums2[n]
		if num1 > num2 {
			nums1[index] = num1
			m--
		} else {
			nums1[index] = num2
			n--
		}
		index--
	}
	// 如果最后nums2有剩余，直接拷贝到nums1即可
	if n >= 0 {
		copy(nums1[0:n+1], nums2[0:n+1])
	}
}