# include "bits/stdc++.h"

using namespace std;

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        n = nums.size();
        int i = 0;
        recur(i, nums);

        return ans;
    }

private:
    int n;
    vector<int> chosen;
    vector<vector<int>> ans;

    void recur(int i, vector<int> &nums)
    {
        if (i == n)
        {
            ans.push_back(chosen);
            return;
        }
        recur(i + 1, nums);

        chosen.push_back(nums[i]);
        recur(i + 1, nums);
        chosen.pop_back();
    }
};
