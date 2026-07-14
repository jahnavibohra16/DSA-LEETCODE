class Solution {
public:
    long long totalhours(vector<int>& piles, int hourly){
        long long hrs = 0;
        int n = piles.size();
        for(int i = 0; i < n; i++){
            hrs+=ceil((double)piles[i]/(double)hourly);
        }
        return hrs;
    }

    int maxi(vector<int>& piles){
        int m = INT_MIN;
        for(int i = 0; i<piles.size(); i++){
            m = max(m, piles[i]);
        }
        return m;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = maxi(piles);
        while(low<=high){
            int mid = (low+high)/2;
            long long totalhrs = totalhours(piles, mid);
            if(totalhrs <= h) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};