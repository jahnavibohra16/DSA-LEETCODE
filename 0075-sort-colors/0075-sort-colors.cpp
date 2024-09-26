class Solution {
public:
    void sortColors(vector<int>& nums) {
        int mid=0;
         int n=nums.size();
        int high=n-1;
        int low=0;
        while(mid<=high){
         if(nums[mid]==2){
            int temp=nums[mid];
            nums[mid]=nums[high];
            nums[high]=temp;
            high--;
        }
         else if(nums[mid]==0){
           int temps=nums[mid];
            nums[mid]=nums[low];
            nums[low]=temps;
            low++;
            mid++;
        }
        else if(nums[mid]==1){
            mid++;
        }
    }
    return ;
    }
};