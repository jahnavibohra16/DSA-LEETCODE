#include <iostream>
#include <vector>

class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        // Three pointers
        int p1 = m - 1;  // Pointer for the end of the valid part of nums1
        int p2 = n - 1;  // Pointer for the end of nums2
        int p = m + n - 1;  // Pointer for the end of nums1

        // Merge from the back of nums1 to avoid overwriting
        while (p1 >= 0 && p2 >= 0) {
            if (nums1[p1] > nums2[p2]) {
                nums1[p] = nums1[p1];
                p1--;
            } else {
                nums1[p] = nums2[p2];
                p2--;
            }
            p--;
        }

        // If any elements are left in nums2, copy them
        while (p2 >= 0) {
            nums1[p] = nums2[p2];
            p2--;
            p--;
        }
    }
};
