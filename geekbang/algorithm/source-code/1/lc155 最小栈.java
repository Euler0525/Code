class MinStack {

    public MinStack() {
        s = new Stack<>();
        preMin = new Stack<>();
    }
    
    public void push(int val) {
        s.push(val);
        if (preMin.empty()) preMin.push(val);
        else preMin.push(Math.min(preMin.peek(), val));
    }
    
    public void pop() {
        s.pop();
        preMin.pop();
    }
    
    public int top() {
        return s.peek();
    }
    
    public int getMin() {
        return preMin.peek();
    }

    Stack<Integer> s;
    Stack<Integer> preMin;
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */