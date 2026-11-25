
class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Build Suffix Array
        vector<int> sa(n), rank(n), newRank(n);

        for (int i = 0; i < n; i++) {
            sa[i] = i;
            rank[i] = nums[i];
        }

        for (int k = 1; k < n; k *= 2) {

            sort(sa.begin(), sa.end(), [&](int a, int b) {

                if (rank[a] != rank[b])
                    return rank[a] < rank[b];

                int ra = (a + k < n) ? rank[a + k] : -1;
                int rb = (b + k < n) ? rank[b + k] : -1;

                return ra < rb;
            });

            newRank[sa[0]] = 0;

            for (int i = 1; i < n; i++) {
                int a = sa[i - 1];
                int b = sa[i];

                pair<int, int> p1 = {
                    rank[a],
                    (a + k < n) ? rank[a + k] : -1
                };

                pair<int, int> p2 = {
                    rank[b],
                    (b + k < n) ? rank[b + k] : -1
                };

                newRank[b] = newRank[a] + (p1 != p2);
            }

            rank = newRank;

            if (rank[sa[n - 1]] == n - 1)
                break;
        }

        // Step 2: Build LCP Array using Kasai's Algorithm
        vector<int> pos(n), lcp(n, 0);

        for (int i = 0; i < n; i++)
            pos[sa[i]] = i;

        int h = 0;

        for (int i = 0; i < n; i++) {

            int p = pos[i];

            if (p == 0)
                continue;

            int j = sa[p - 1];

            while (i + h < n && j + h < n &&
                   nums[i + h] == nums[j + h]) {
                h++;
            }

            lcp[p] = h;

            if (h > 0)
                h--;
        }

        // Step 3: Find minimum unique subarray length
        int ans = n;

        for (int i = 0; i < n; i++) {

            int left = lcp[i];
            int right = (i + 1 < n) ? lcp[i + 1] : 0;

            int required = max(left, right) + 1;

            if (required <= n - sa[i])
                ans = min(ans, required);
        }

        return ans;
    }
};
