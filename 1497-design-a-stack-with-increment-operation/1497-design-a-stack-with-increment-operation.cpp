class CustomStack {
public:
    vector<int> stack;        // Stores the stack elements
    vector<int> incrementArr; // Lazy increment array
    int maxSize;              // Maximum size of the stack
    int top;                  // Top pointer
    
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
        stack.resize(maxSize);
        incrementArr.resize(maxSize);
        top = -1;
    }

    void push(int x) {
        if (top < maxSize - 1) { // Only push if stack is not full
            top++;
            stack[top] = x;
        }
    }

    int pop() {
        if (top == -1) return -1; // If stack is empty, return -1
        int res = stack[top] + incrementArr[top]; // Add any pending increment

        if (top > 0) { 
            incrementArr[top - 1] += incrementArr[top]; // Pass down the increment to the next element
        }
        incrementArr[top] = 0; // Reset the current increment
        top--;
        
        return res;
    }

    void increment(int k, int val) {
        if (top >= 0) {
            incrementArr[min(k - 1, top)] += val; // Mark the lazy increment
        }
    }
};
