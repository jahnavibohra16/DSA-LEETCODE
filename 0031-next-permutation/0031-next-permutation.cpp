class Solution {
public:
    /*void reversep(vector<int>& nums, int i, int j){
        while(i<j){
            int temp=nums[i];
            nums[i]=nums[j];
            nums[j]=temp;
        }
    }*/
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int idx=-1;//pivot index
        //check pivot
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                idx=i;
                break;
            }
        }
        if(idx==-1){
            reverse(nums.begin(),nums.end());
            return ;//for reverse in built stls fn
            }
            //sorting the array in descending order after idx pivot index
        reverse(nums.begin()+idx+1,nums.end());
        //find just greater number than idx
        int j=-1;
        for(int i=idx+1;i<n;i++){
            if(nums[i]>nums[idx]){
                j=i;
                break;
            }
        }

        //swapping idx and j
        int temp=nums[idx];
        nums[idx]=nums[j];
        nums[j]=temp;
        return ;
    }
};