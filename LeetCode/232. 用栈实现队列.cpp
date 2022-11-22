# include "stack"

using namespace std;

class MyQueue
{
private:
    stack<int> in_stack, out_stack;

    void in2out()
    {
        while (!in_stack.empty())
        {
            out_stack.push(in_stack.top());
            in_stack.pop();
        }

    }

public:

    void push(int x)
    {
            in_stack.push(x);
    }

    int pop()
    {
        while (out_stack.empty())
        {
            in2out();
        }
        int top = out_stack.top();
        out_stack.pop();

        return top;
    }

    int peek()
    {
        while(out_stack.empty())
        {
            in2out();
        }

        return out_stack.top();

    }

    bool empty()
    {
        return out_stack.empty() && in_stack.empty();
    }
};
