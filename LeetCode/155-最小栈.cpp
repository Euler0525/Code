class MinStack
{
public:
    MinStack()
    = default;

    void push(int val)
    {
        s.push(val);
        if (pre_min.empty()) pre_min.push(val);
        else
        {
            pre_min.push(min(pre_min.top(), val));
        }

    }

    void pop()
    {
        s.pop();
        pre_min.pop();
    }

    int top()
    {
        return s.top();
    }

    int getMin()
    {
        return pre_min.top();
    }

private:
    stack<int> s;
    stack<int> pre_min;
};
