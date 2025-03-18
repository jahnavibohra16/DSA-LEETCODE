class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; // Ensure k is within bounds

        if (k == 0 || n <= 1) return; // No need to rotate if k is 0 or array has only 1 element

        vector<int> temp(k);

        // Store last k elements in temp
        for (int i = 0; i < k; i++) {
            temp[i] = nums[n - k + i];
        }

        // Shift the first n-k elements to the right
        for (int i = n - k - 1; i >= 0; i--) {
            nums[i + k] = nums[i];
        }

        // Copy back the last k elements from temp to the front
        for (int i = 0; i < k; i++) {
            nums[i] = temp[i];
        }
    }
};