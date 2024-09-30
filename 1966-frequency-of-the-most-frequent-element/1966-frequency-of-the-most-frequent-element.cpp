class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0; // left pointer
        int ans = 0;  // best answer so far
        long curr = 0; // sum of the elements currently in our window

        // iterate right over indeces of nums
        for (int right = 0; right < nums.size(); right++) {
            long target = nums[right]; // so that we do not run in overflow
            curr += target;            // add target to curr

            // use a while loop to shrink our window by incrementing left until
            // k opp are sufficient. while the size of the window is multiplied
            // by target, minus curr < k:
            while ((right - left + 1) * target - curr > k) {
                curr -= nums[left]; // sub nums[left] from curr
                left++;             // incr left
            };
            ans = max (ans, right - left + 1); // update ans with current window size if its larger
        }

        return ans;
    }
};