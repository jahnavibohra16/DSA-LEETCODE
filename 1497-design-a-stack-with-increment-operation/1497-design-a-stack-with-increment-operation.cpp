class CustomStack {
public:
    vector<int> stack;
    int maxSize;
    int top;

    CustomStack(int maxSize) {
        this->maxSize = maxSize;
        stack.resize(maxSize);
        top = -1;
    }

    void push(int x) {
        if (top < maxSize - 1) {  // Check if stack is not full
            top++;
            stack[top] = x;
        }
    }

    int pop() {
        if (top != -1) {  // If stack is not empty
            return stack[top--];  // Return top element and decrement top
        }
        return -1;  // Stack is empty
    }

    void increment(int k, int val) {
        int limit = min(k, top + 1);  // Only increment up to the top of the stack
        for (int i = 0; i < limit; i++) {
            stack[i] += val;
        }
    }
};
