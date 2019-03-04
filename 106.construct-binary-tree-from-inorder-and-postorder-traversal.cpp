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
        if (inorder.size() == 0)
            return nullptr;
        stack<TreeNode *> st;
        stack<pair<int, int>> sin;
        stack<pair<int, int>> sout;
        TreeNode *root = new TreeNode(0);
        st.push(root);
        sin.push(pair(0, inorder.size() - 1));
        sout.push(pair(0, postorder.size() - 1));
        while (!st.empty())
        {
            TreeNode *cur = st.top();
            st.pop();
            auto in = sin.top();
            sin.pop();
            auto out = sout.top();
            sout.pop();
            cur->val = postorder[out.second];
            int index = find(inorder.begin() + in.first, inorder.begin() + in.second, cur->val) - inorder.begin();
            if (in.first == in.second)
                continue;

            if (index < in.second)
            {
                cur->right = new TreeNode(0);
                st.push(cur->right);
                sin.push(pair(index + 1, in.second));
                sout.push(pair(out.first + (index - in.first - 1) + 1, out.second - 1));
            }
            if (index > in.first)
            {
                cur->left = new TreeNode(0);
                st.push(cur->left);
                sin.push(pair(in.first, index - 1));
                sout.push(pair(out.first, out.first + (index - in.first - 1)));
            }
        }
        return root;
    }
};
