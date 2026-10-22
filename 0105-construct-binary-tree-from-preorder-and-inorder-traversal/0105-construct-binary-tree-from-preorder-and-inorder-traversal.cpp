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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& i, int left, int right){
        if(left>right){
            return NULL;
        }
        int pivot = left;
        while(inorder[pivot]!=preorder[i]){
            pivot++;
        }
        i++;
        TreeNode* newNode = new TreeNode(inorder[pivot]);
        newNode->left=build(preorder, inorder, i, left, pivot-1);
        newNode->right=build(preorder, inorder, i, pivot+1, right);
        return newNode;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder){
        int i = 0;
        return build(preorder, inorder, i, 0, inorder.size()-1);
    }
};