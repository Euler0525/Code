// 这道题目是一道使用分治思路的很好的模板题目
func myPow(x float64, n int) float64 {
	// 这里需要分清楚，n是正数和负数的情况
	if n >= 0 {
		return quickMul(x, n)
	}
	return 1.0 / quickMul(x, -n)
}

func quickMul(x float64, n int) float64 {
	// 递归终止条件，如果n是0，直接返回1
	if n == 0 {
		return 1
	}
	// 子问题拆分，如果需要解决n的问题域，则只需要解决n/2的问题域，然后把解决的问题merge起来即可
	y := quickMul(x, n/2)
	// 分别将分治的子问题的结果，合并起来，这边要注意奇偶
	if n%2 == 0 {
		return y * y
	}
	return y * y * x
}