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
    void serialize(TreeNode* root, vector<int>& res) {
        if(!root) {
            res.push_back(INT_MIN) ;
            return ;
        }
        res.push_back(root->val) ;
        serialize(root->left, res) ;  
        serialize(root->right, res) ;
    }
    TreeNode* insertBST(TreeNode* node, int key) {
        if(!node) return new TreeNode(key) ;
        if(node->val > key) node->left = insertBST(node->left, key) ;
        else if(node->val  < key) node->right = insertBST(node->right, key) ;
        return node ;
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<int> v(n) ;
        for(int i = 0; i < n; i++) {
            v[i] = i+1 ;
        }
        set<vector<int>> st ;
        vector<TreeNode*> ans ;
        do {
            TreeNode* root = new TreeNode(v[0]) ;
            for(int i = 1; i < n; i++) {
                root = insertBST(root, v[i]) ;
            }
            vector<int> t ;
            serialize(root, t) ;
            if(st.find(t) == st.end()) {
                st.insert(t) ;
                ans.push_back(root) ;
            }
        } while(next_permutation(v.begin(), v.end())) ;

        return ans ;
    }
};
