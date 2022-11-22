class Solution
{
public:
    static string reverseLeftWords(const string& str, int n)
    {
        string s = str.substr(n, str.size());
        return s + str.substr(0, n);
    }
};