class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size(), n = nums2.size();
        if (m == 0 && n == 1)
        {
            return nums2[0];
        }
        if (n == 0 && m == 1)
        {
            return nums1[0];
        }
        vector<int> merged(m+n);
        int idx = 0;
        int i = 0, j = 0;
        while (i < m && j < n)
        {
            if (nums1[i] <= nums2[j])
            {
                merged[idx] = nums1[i];
                ++i;
            }
            else
            {
                merged[idx] = nums2[j];
                ++j;
            }
            ++idx;
        }
        while (i < m)
        {
            merged[idx] = nums1[i];
            ++idx, ++i;
        }
        while (j < n)
        {
            merged[idx] = nums2[j];
            ++idx, ++j;
        }
        double mid = merged[(m + n)/2];
        double mid1 = merged[(m + n)/2 -1];
        if ((m + n) % 2 == 0)
        {
            return (mid + mid1) / 2.0;
        }
        else
        {
            return mid;
        }
    }
};
