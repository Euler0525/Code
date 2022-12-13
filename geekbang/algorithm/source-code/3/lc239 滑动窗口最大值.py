class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        q = []
        ans = []
        for i in range(len(nums)):
            # (关键码，下标)
            # 把关键码乘-1，使小根堆具有大根堆的行为
            heapq.heappush(q, (-nums[i], i))
            if i >= k - 1:
                # [i-k+1, i] 这一段的max
                # 懒惰删除
                val, idx = heapq.heappop(q)
                while idx <= i - k:
                    val, idx = heapq.heappop(q)
                ans.append(-val)
                # 此值仍有意义，放回堆中
                # Python没有相对应C++和Java的top()或peek()函数，只能pop()或poll()
                heapq.heappush(q, (val, idx))
        return ans