class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {

        //create hash map
        unordered_map<int,int>numtorank;
        //copy arr
        vector<int>sorted(arr);
        int rank=1;
        //sorting
        sort(sorted.begin(),sorted.end());
        for(int i=0;i<sorted.size();i++){
            if(i>0 && sorted[i]>sorted[i-1]){rank++;}
            numtorank[sorted[i]]=rank;
        }
        for(int i=0;i<arr.size();i++){
            arr[i]=numtorank[arr[i]];
        }

        return arr;
    }
};