class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> hashm;
        for(int num:nums){
            if(hashm[num]>=1){
                return true;
            }
            hashm[num]++;
        }
        return false;
    }
};