/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Medium (55.01%)
 * Total Accepted:    410.8K
 * Total Submissions: 746.4K
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the inorder traversal of its nodes' values.
 *
 * Example:
 *
 *
 * Input: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 *
 * Output: [1,3,2]
 *
 * Follow up: Recursive solution is trivial, could you do it iteratively?
 *
 */
/**
 * Definition for a binary tree node.
 */
#include <vector>
#include <stack>
#include <set>
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
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> result;
        stack<TreeNode *> s;
        if (root)
            s.push(root);
        while (!s.empty())
        {
            while (s.top()->left)
                s.push(s.top()->left);
            while (!s.empty())
            {
                TreeNode *cur = s.top();
                result.push_back(cur->val);
                s.pop();
                if (cur->right)
                {
                    s.push(cur->right);
                    break;
                }
            }
        }
        return result;
    }
};
