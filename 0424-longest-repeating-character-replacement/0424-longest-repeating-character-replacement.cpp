class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxlen = 0, l = 0, r = 0, maxf = 0;
        vector<int> hash(26,0);
        int n = s.size();
        while(r<n){
            hash[s[r]-'A']++;
            maxf = max(maxf, hash[s[r]-'A']);
            if((r-l+1)-maxf > k){
                hash[s[l]-'A']--;  
                l++;
            }
            if((r-l+1)-maxf <=k){
                maxlen = max(maxlen, r-l+1);
            }
            r++;
        }
        return maxlen;
    }
};