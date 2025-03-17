class Solution {
public:
    bool check(vector<int>& nums) {
        int size = nums.size();

        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        for (int off = 0; off < size; off++) {
            bool isMatch = true;
            for (int i = 0; i < size; i++) {
                if (nums[(i + off) % size] != sorted[i]){
                    isMatch = false;
                    break;
                }
            }
            if (isMatch){
                return true;
            }
        }
        return false;
    }
};

// first we make a sorted copy of the given array, then compare it after each rotations.