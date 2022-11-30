func findSubstring(s string, words []string) []int {
	// 特殊情况，优先处理，如果输入words数组内容为空，则直接返回空结果
	if len(words) < 1 {
		return []int{}
	}

	// 输入的单词数组的长度
	wordsNum := len(words)
	wordLen := len(words[0])
	// 另一种特殊情况，如果当前单词数*单词长度>字符串的长度，也不合法，直接返回空结果（因为单词长度相同，才有）
	if len(s) < wordsNum*wordLen {
		return []int{}
	}

	var res []int
	// 定义一个map，其中key是字符串，而value是整数
	var map1 = make(map[string]int)
	for _, w := range words {
		//发现某个单词，就将这个单词对应的数字++
		map1[w]++
	}

	// 设定每一个比较的起始位置，这里的上限是，字符串总长度-words单词和单词个数乘积的总长度
	for i := 0; i < len(s)-wordLen*wordsNum+1; i++ {
		var count int
		var map2 = make(map[string]int)
		// 尝试每一个word
		for tryWord := 0; tryWord < wordsNum; tryWord++ {
			// 推演一下，假设第一个
			// start=0;
			// word从s里面截取wordLen
			start := i + tryWord*wordLen
			word := s[start : start+wordLen]
			// 如果当前取出的word在map1中，并且map2中还没有取到和map1中一样的值，说明OK的，直接count++，并且这个元素去过了，在map2中标记一下
			if num, found := map1[word]; found && num > map2[word] {
				map2[word]++
				count++
			} else {
				break
			}
		}
		// 如果总数和words数组一样，当前就是一次合法尝试，加入到结果集中
		if count == wordsNum {
			res = append(res, i)
		}
	}

	return res
}