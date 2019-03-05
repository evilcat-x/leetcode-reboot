/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (37.96%)
 * Total Accepted:    141.3K
 * Total Submissions: 372.2K
 * Testcase Example:  '[9,3,15,20,7]\n[9,15,7,20,3]'
 *
 * Given inorder and postorder traversal of a tree, construct the binary tree.
 *
 * Note:
 * You may assume that duplicates do not exist in the tree.
 *
 * For example, given
 *
 *
 * inorder = [9,3,15,20,7]
 * postorder = [9,15,7,20,3]
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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        if (inorder.empty())
            return nullptr;
        stack<TreeNode *> st;
        auto in = inorder.end() - 1;
        auto post = postorder.end() - 1;
        auto start = postorder.begin();
        TreeNode *root = new TreeNode(*post--);
        TreeNode *cur = root;
        st.push(root);
        while (!st.empty())
        {
            while (st.top()->val != *in)
            {
                cur->right = new TreeNode(*post--);
                cur = cur->right;
                st.push(cur);
            }
            while (!st.empty() && st.top()->val == *in)
            {
                cur = st.top();
                st.pop();
                in--;
            }
            if (post >= start)
            {
                cur->left = new TreeNode(*post--);
                cur = cur->left;
                st.push(cur);
            }
        }
        return root;
    }
};
