class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mini = INT_MAX, maxi = INT_MIN;
        int n = nums.size();
        int g = 0;

        for (int i = 0; i < n; i++) {
            mini = min(mini, nums[i]);
            maxi = max(maxi, nums[i]);
        }

        for (int i = 1; i <= mini; i++) {
            if (mini % i == 0 && maxi % i == 0) {
                g = i;
            }
        }

        return g;
    }
};