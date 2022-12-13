class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            q.push({nums[i], i});
            if (i >= k - 1) {
                // [i-k+1, i] 这一段的max
                // 懒惰删除
                while (q.top().second <= i - k) q.pop();
                ans.push_back(q.top().first);
            }
        }
        return ans;
    }

private:
    // <关键码，下标>
    priority_queue<pair<int, int>> q;
};