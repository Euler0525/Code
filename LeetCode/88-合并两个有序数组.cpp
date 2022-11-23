class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        vector<int> result;
        int i = 0, j = 0;
        while (i < m || j < n)
        {
            // i < m: 在i >= m && j < n的情况下会判断nums1[i] < nums2[j]，但报错溢出
            if (j >= n || (i < m && nums1[i] < nums2[j]))
            {
                result.push_back(nums1[i]);
                ++i;
            }
            else
            {
                result.push_back(nums2[j]);
                ++j;
            }
        }
        for (int k = 0; k < nums1.size(); ++k)
        {
            nums1[k] = result[k];
        }
    }
};
