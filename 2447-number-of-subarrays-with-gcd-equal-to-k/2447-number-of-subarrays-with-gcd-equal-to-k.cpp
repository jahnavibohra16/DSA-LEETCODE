class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int count = 0;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            int g = 0;            
            for (int j = i; j < n; j++) {
                g = gcd(g, nums[j]);
                if (g % k != 0) break;
                if (g == k) count++;
            }
        }
        return count;
    }
};