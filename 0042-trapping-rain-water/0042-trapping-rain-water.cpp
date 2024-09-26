class Solution {
public:
    int trap(vector<int>& height) {
        // size of array
        int n = height.size();
        // previous greatest element
        int prev[n];
        prev[0] = -1;
        int max = height[0];
        for (int i = 1; i < n; i++) {
            prev[i] = max;
            if (max < height[i]) {
                max = height[i];
            }
        }
        // next greatest element array
        int next[n];
        next[n - 1] = -1;
        max = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            next[i] = max;
            if (max < height[i]) {
                max = height[i];
            }
        }
        // min elements of the two arrays
        int mini[n];
        for (int i = 0; i < n; i++) {
            mini[i] = min(prev[i], next[i]);
        }
        // height of water using min and height array
        int water = 0;
        for (int i = 1; i < n - 1; i++) {
            if (height[i] < mini[i]) {
                water += (mini[i] - height[i]);
            }
        }
        return water;
    }
};