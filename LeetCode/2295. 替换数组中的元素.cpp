class Solution
{
public:
    static vector<int> arrayChange(vector<int> &nums, vector<vector<int>> &operations)
    {
        unordered_map<int, int> hash;
        reverse(operations.begin(), operations.end());  // 值是后面的键
        for (auto &op: operations)
        {
            if (!hash[op[1]])  // 如果不存在，正常赋值;
            {
                hash[op[0]] = op[1];
            }
            else
            {
                hash[op[0]] = hash[op[1]];  // 值是后面的键
            }
        }

        for (auto &n: nums)
        {
            if (hash[n])
            {
                n = hash[n];
            }
        }

        return nums;
    }
};
