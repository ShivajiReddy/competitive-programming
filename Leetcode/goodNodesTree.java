/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

/*
 int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }
    
    int dfs(TreeNode* root, int maxVal) {
        if(root == NULL) return 0;
        
        maxVal = max(root->val, maxVal);
        
        
        return (root->val >= maxVal ? 1 : 0) + dfs(root->left, maxVal) + dfs(root->right, maxVal);
        
    }
*/
class Solution {
    public int goodNodes(TreeNode root) {
        return dfs(root, root.val);
    }
    
    private int dfs(TreeNode root, int maxVal) {
        if(root == null) {
            return 0;
        }
        
        maxVal = Math.max(root.val, maxVal);
        
        return (root.val >= maxVal ? 1 : 0) + dfs(root.left, maxVal) + dfs(root.right, maxVal);
    }
}