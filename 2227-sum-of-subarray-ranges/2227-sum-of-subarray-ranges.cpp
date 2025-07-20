class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        stack<int> st1;
        stack<int> st2;
        stack<int> st3;
        stack<int> st4;
        int n = nums.size();
        // int mod = 1e9 + 7;
        long long sum = 0;
        vector<int> nse(n);
        vector<int> pse(n);
        vector<int> nge(n);
        vector<int> pge(n);

        // previous smaller
        for (int i = 0; i < n; i++) {
            while (!st1.empty() && nums[st1.top()] >= nums[i]) {
                st1.pop();
            }
            pse[i] = st1.empty() ? -1 : st1.top();
            st1.push(i);
        }

        // next smaller
        for (int i = n - 1; i >= 0; --i) // back traversal for next
        {
            while (!st2.empty() && nums[st2.top()] > nums[i]) {
                st2.pop();
            }
            nse[i] = st2.empty() ? n : st2.top();
            st2.push(i);
        }

        long long left, right;
        long long sumSmall = 0;
        long long sumLarge = 0;

        for (int i = 0; i < n; i++) {
            left = i - pse[i];
            right = nse[i] - i;
            sumSmall = sumSmall + (1LL * left * right * nums[i]) ;
        }

        // previous greater
        for (int i = 0; i < n; i++) {
            while (!st3.empty() && nums[st3.top()] <= nums[i]) {
                st3.pop();
            }
            pge[i] = st3.empty() ? -1 : st3.top();
            st3.push(i);
        }

        // next greater
        for (int i = n - 1; i >= 0; --i) // back traversal for next
        {
            while (!st4.empty() && nums[st4.top()] < nums[i]) {
                st4.pop();
            }
            nge[i] = st4.empty() ? n : st4.top();
            st4.push(i);
        }

        for (int i = 0; i < n; i++) {
            left = i - pge[i];
            right = nge[i] - i;
            sumLarge = sumLarge + (1LL * left * right * nums[i]);
        }

        sum = sumLarge - sumSmall ; 
                   
        return sum;
    }
};
