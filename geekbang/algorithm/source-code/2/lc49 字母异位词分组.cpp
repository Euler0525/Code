class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
/*
{
    "aet": ["eat", "tea", "ate"],
    "ant": ["tan", "nat"],
    "abt": ["bat"]
}
*/
        unordered_map<string, vector<string>> groups;
        for (string& s : strs) {
            string copy = s;
            sort(copy.begin(), copy.end());
            if (groups.find(copy) == groups.end()) {
                groups[copy] = {};
            }
            groups[copy].push_back(s);
        }
        vector<vector<string>> ans;
        for (const pair<string, vector<string>>& group : groups) {
            ans.push_back(group.second);
        }
        return ans;
    }
};