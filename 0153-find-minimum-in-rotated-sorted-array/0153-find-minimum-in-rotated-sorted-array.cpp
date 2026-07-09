class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size()-1, ans = INT_MAX;
        while(low<=high){
            int mid = (low + high )/2;
            //if search space is already sorted then low is always min
            if(nums[low]<=nums[high]){
                ans = min(ans, nums[low]);
                break;
            }
            if(nums[low]<=nums[mid]){
                ans = min(ans, nums[low]);
                low = mid + 1;
            }
            else{
                
                high = mid - 1;
                ans = min(ans, nums[mid]);
            }
        }
        return ans;
    }
};