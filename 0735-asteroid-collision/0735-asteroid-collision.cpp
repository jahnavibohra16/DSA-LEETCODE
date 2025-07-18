class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int n = asteroids.size();
        for (int i = 0; i < n; i++) {
            if (asteroids[i] > 0) {
                st.push(asteroids[i]); // put positive element in stack.
            } else {
                while (!st.empty() && st.top() > 0 &&
                       st.top() < abs(asteroids[i])) {
                    st.pop(); // until the top is not a negative element, equal
                              // to the abs value of i or greater than i, keep
                              // popping em out of stack.
                }
                if (!st.empty() && st.top() == abs(asteroids[i])) {
                    st.pop(); // remove positive element equal to the negative
                              // element from stack. Don't add those negative
                              // element in stack

                } else if (st.empty() || st.top() < 0) {
                    st.push(
                        asteroids[i]); // put negative in stack only if either
                                       // the stack is empty or top is negative.
                }
            }
        }

        vector <int> result(st.size());
        for(int i = st.size() - 1; i >=0; --i)//popping from a stack from top to bottom, but  storing it in the result from left to right — this reverses the intended order. So reverse the result at the end, as stack pops in reverse order.
        {
            result[i] = st.top();
            st.pop();
        }
        return result;
    }
};