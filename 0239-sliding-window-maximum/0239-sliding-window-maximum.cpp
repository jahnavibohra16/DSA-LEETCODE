class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        int n = nums.size();
        vector<int> res;            // n-k size
        for (int i = 0; i < n; i++) // traver 0 to n-1
        {
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front(); // remove element from the front if it is
                                // outside the window
            }
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back(); // smaller element than i, remove from back
            }
            dq.push_back(i); // push element from back
            if (i >= k - 1)  // if window size is reached
            {
                res.push_back(nums[dq.front()]);
                // add front to resultant vector -> front is max as the deque is
                // monotonic in decreasing order.
            }
        }
        return res;
    }
};