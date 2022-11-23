# [剑指 Offer 03. 数组中重复的数字](https://leetcode.cn/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/)

## 解法1【另存为集合】

### 思路分析

将遍历到的数字存到一个集合中，判断新遍历到的数是否在这个集合中。

### 代码实现

```python
class Solution(object):
    def findRepeatNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        new_set = set()
        for i in nums:
            if i in new_set:
                return i
            new_set.add(i)
```

### 复杂度

- **时间**：执行用时: **32 ms**

- **空间**：内存消耗: **21.2 MB**

## 解法2【排序&遍历】

### 思路分析

先将数组排序，再判断相邻两个数是否相等。

### 代码实现

```python
class Solution(object):
    def findRepeatNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.sort()
        for i in range(len(nums)):
            if nums[i] == nums[i +1]:
                return nums[i]
```

### 复杂度

- **时间**：执行用时: **36 ms**

- **空间**：内存消耗: **19.9 MB**

## 解法3【原地交换】

### 思路分析

题目中限制“在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内”，因此我们可以得出这n-1个数都有与本身相等的对应的下标。遍历数组，如果数值与下标一致，查看下一个元素，不一致则交换到对应下标处，如果交换后与原数相等，则输出。

这种原地交换的方法降低空间的复杂度为$O(1)$

### 代码实现

```python
class Solution:
    def findRepeatNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        i = 0
        while i < len(nums):
            if nums[i] == i:
                i += 1
                continue
            if nums[nums[i]] == nums[i]:
                return nums[i]

            nums[nums[i]], nums[i] = nums[i], nums[nums[i]]
```

### 复杂度

- **时间**：执行用时: **28 ms**

- **空间**：$O(1)$内存消耗: **19.2 MB**