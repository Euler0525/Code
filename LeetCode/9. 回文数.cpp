class Solution
{
public:
    bool isPalindrome(int x)
    {
        int rev_num = 0;
        if (x < 0 || (x % 10 == 0 && x != 0)) // 小补丁
        {
            return false;
        }

        // 倒序一半长度，防止溢出
        while (x > rev_num)
        {
            rev_num = rev_num * 10 + x % 10;
            x /= 10;
        }

        return x == rev_num || x == rev_num / 10;
    }
};