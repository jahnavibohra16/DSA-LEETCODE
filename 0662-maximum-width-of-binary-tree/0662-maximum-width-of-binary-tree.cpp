/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        long long ans = 0;
        queue <pair<TreeNode*, long long>> q;
        q.push({root, 0});
        while(!q.empty()){
            int qsize = q.size();
            long long mmin = q.front().second;
            long long first, last;
            for(int i = 0; i <qsize; i++){
                long long index = q.front().second - mmin; //to prevent overflow
                TreeNode* node = q.front().first;
                q.pop();
                if(i == 0) first = index;
                if(i == qsize - 1) last = index;
                if(node->left) q.push({node->left, index*2+1}); //left index
                if(node->right) q.push({node->right, index*2+2}); //right index
            }
            ans = max(ans, last - first + 1);
        }
        return ans;
    }
};