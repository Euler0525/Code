# include "bits/stdc++.h"

using namespace std;

class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        this->n = n;
        this->k = k;

        recur(1);

        return ans;
    }

private:
    int n, k;
    vector<int> chosen;
    vector<vector<int>> ans;

    void recur(int i)
    {
        if (chosen.size() > k || chosen.size() + (n - i + 1) < k)
        {
            return;
        }
        if (i == n + 1)
        {
            if (chosen.size() == k)
            {
                ans.push_back(chosen);
            }
            return;
        }
        recur(i + 1);
        chosen.push_back(i);
        recur(i + 1);
        chosen.pop_back();
    }
};
