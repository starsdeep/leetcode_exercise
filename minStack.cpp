class MinStack {
public:
	
	std::stack<int> mystack;
	std::stack<int> minstack;
	
	
    void push(int x) {
        if(minstack.empty() || x <= minstack.top()) {
        	minstack.push(x);	
        }
        mystack.push(x);
    }

    void pop() {
        int t = mystack.top();
        mystack.pop();
        if(t == minstack.top())
        	minstack.pop();
    }

    int top() {
        return mystack.top();
    }

    int getMin() {
        return minstack.top();
    }
};