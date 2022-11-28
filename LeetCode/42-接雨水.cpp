// 维护单调递减栈
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int ans = 0;
        for(int h : height)
        {
            int accumulated_width = 0;
            while (!s.empty() && h > s.top().height)
            {
                int bottom = s.top().height;
                accumulated_width += s.top().width;
                s.pop();
                if (s.empty()) continue;
                int up = min(s.top().height, h);
                ans += (up - bottom) * accumulated_width;
            }
            s.push({h, accumulated_width + 1});
        }

        return ans;
    }
private:
    struct Rect
    {
        int height;
        int width;
    };
    stack<Rect> s;
};
