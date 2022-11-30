class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> h;
        for (int i = 0; i < nums.size(); i++) {
            // Python: (target - nums[i]) in h
            // Java: h.containsKey(target - nums[i])
            // C++: 找不到的话返回h.end()
            if (h.find(target - nums[i]) != h.end()) {
                return { h[target - nums[i]], i };
            }
            h[nums[i]] = i;
        }
        return {};
    }
};