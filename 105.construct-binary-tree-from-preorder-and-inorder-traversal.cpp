/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (39.48%)
 * Total Accepted:    201.5K
 * Total Submissions: 510.2K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 *
 * Note:
 * You may assume that duplicates do not exist in the tree.
 *
 * For example, given
 *
 *
 * preorder = [3,9,20,15,7]
 * inorder = [9,3,15,20,7]
 *
 * Return the following binary tree:
 *
 *
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 *
 */
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
  public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        if (inorder.empty())
            return nullptr;
        stack<TreeNode *> st;
        auto in = inorder.begin();
        auto pre = preorder.begin();
        auto end = preorder.end();
        TreeNode *root = new TreeNode(*pre++);
        TreeNode *cur = root;
        st.push(root);
        while (!st.empty())
        {
            while (st.top()->val != *in)
            {
                cur->left = new TreeNode(*pre++);
                cur = cur->left;
                st.push(cur);
            }
            while (!st.empty() && st.top()->val == *in)
            {
                cur = st.top();
                st.pop();
                in++;
            }
            if (pre < end)
            {
                cur->right = new TreeNode(*pre++);
                cur = cur->right;
                st.push(cur);
            }
        }
        return root;
    }
};
