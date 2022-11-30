class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> ans;
        // 建立哈希表
        for (const string str: strs)
        {
            string copy_str = str;
            sort(copy_str.begin(), copy_str.end());
            if (groups.find(copy_str) == groups.end())
            {
                groups[copy_str] = {};
            }

            groups[copy_str].push_back(s\);
        }

        for (const pair<string, vector<string>> &group: groups)
        {
            ans.push_back(group.second);
        }

        return ans;
    }

private:
    unordered_map<string, vector<string>> groups;
};
