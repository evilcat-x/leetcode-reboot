/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
 *
 * https://leetcode.com/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (42.72%)
 * Total Accepted:    360.5K
 * Total Submissions: 843.9K
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric
 * around its center).
 *
 *
 * For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
 *
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠/ \ / \
 * 3  4 4  3
 *
 *
 *
 * But the following [1,2,2,null,3,null,3]  is not:
 *
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠  \   \
 * ⁠  3    3
 *
 *
 *
 *
 * Note:
 * Bonus points if you could solve it both recursively and iteratively.
 *
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
    bool isSymmetric(TreeNode *root)
    {
        stack<TreeNode *> pre;
        set<TreeNode *> v;
        stack<TreeNode *> post;
        pre.push(root);
        post.push(root);
        while (!pre.empty())
        {
            TreeNode *n1 = pre.top();
            TreeNode *n2 = post.top();

            if (!n1 && !n2)
            {
                pre.pop();
                post.pop();
                continue;
            }
            if ((!n1 && n2) || (n1 && !n2) || (n1->val != n2->val))
                return false;
            v.insert(n1);
            v.insert(n2);
            pre.pop();
            post.pop();
            if (v.find(n1->right) == v.end())
                pre.push(n1->right);
            if (v.find(n1) == v.end())
                pre.push(n1);
            if (v.find(n1->left) == v.end())
                pre.push(n1->left);
            if (v.find(n2->left) == v.end())
                post.push(n2->left);
            if (v.find(n2) == v.end())
                post.push(n2);
            if (v.find(n2->right) == v.end())
                post.push(n2->right);
        }
        return true;
    }
};
