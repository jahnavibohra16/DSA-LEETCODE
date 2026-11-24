class Solution {
public:
    int maxLength(vector<int>& nums) {
        int maxi = 2;
        int prodVal = 1;
        int numsLen = nums.size();
        int left = 0, right = 0;

        while (right < numsLen) {
            while (gcd(prodVal, nums[right]) > 1) {
                prodVal /= nums[left];
                left++;
            }
            prodVal *= nums[right];
            maxi = max(maxi, right - left + 1);
            right++;
        }
        return maxi;
    }
};

/*
for (int r = 0; r < n; r++) {
    conflict = true;

    while (conflict == true) {
        conflict = false;

        for (int i = l; i < r; i++) {
            if (gcd(nums[i], nums[r]) > 1) {
                conflict = true;
            }
        }

        if (conflict == true)
            l++;
    }

    maxi = max(maxi, r - l + 1);
} compare with above code

-----------------------------------------

int maxi = 2, l = 0;
for (int r = 0; r < n; r++) {
    for (int i = r - 1; i >= l; i--) {
        if (gcd(nums[i], nums[r]) > 1) { l = i + 1; break; }
    }
    maxi = max(maxi, r - l + 1);
}
*/