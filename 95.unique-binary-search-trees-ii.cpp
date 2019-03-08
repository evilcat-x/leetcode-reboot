/*
 * @lc app=leetcode id=95 lang=cpp
 *
 * [95] Unique Binary Search Trees II
 *
 * https://leetcode.com/problems/unique-binary-search-trees-ii/description/
 *
 * algorithms
 * Medium (34.83%)
 * Total Accepted:    129.1K
 * Total Submissions: 370.5K
 * Testcase Example:  '3'
 *
 * Given an integer n, generate all structurally unique BST's (binary search
 * trees) that store values 1 ... n.
 *
 * Example:
 *
 *
 * Input: 3
 * Output:
 * [
 * [1,null,3,2],
 * [3,2,null,1],
 * [3,1,null,null,2],
 * [2,1,3],
 * [1,null,2,null,3]
 * ]
 * Explanation:
 * The above output corresponds to the 5 unique BST's shown below:
 *
 * ⁠  1         3     3      2      1
 * ⁠   \       /     /      / \      \
 * ⁠    3     2     1      1   3      2
 * ⁠   /     /       \                 \
 * ⁠  2     1         2                 3
 *
 *
 */
#include <vector>
#include <utility>
#include <map>
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
  private:
    map<pair<int, int>, vector<TreeNode *>> cache;

  public:
    vector<TreeNode *> generateTrees(int n)
    {
        vector<TreeNode *> res;
        cache[pair(0, 0)] = res;
        res.push_back(new TreeNode(1));
        cache[pair(1, 0)] = res;
        for (int i = 0; i <= n; i++)
            generateTreesFrom(i, 0);
        return cache[pair(n, 0)];
    }
    TreeNode *cloneTree(TreeNode *root, int base)
    {
        if (!root)
            return nullptr;
        TreeNode *clone = new TreeNode(root->val + base);
        clone->left = cloneTree(root->left, base);
        clone->right = cloneTree(root->right, base);
        return clone;
    }
    vector<TreeNode *> cloneAndCache(int n, int base)
    {
        vector<TreeNode *> res;
        for (auto &node : cache[pair(n, 0)])
            res.push_back(cloneTree(node, base));
        cache[pair(n, base)] = res;
        return res;
    }
    vector<TreeNode *> generateTreesFrom(int n, int base)
    {
        vector<TreeNode *> res;
        if (cache.find(pair(n, base)) != cache.end())
            return cache[pair(n, base)];
        if (cache.find(pair(n, 0)) != cache.end())
            return cloneAndCache(n, base);
        for (int i = 1; i <= n; i++)
        {
            vector<TreeNode *> left = generateTreesFrom(i - 1, 0);
            vector<TreeNode *> right = generateTreesFrom(n - i, i);
            if (i == 1)
                left.push_back(nullptr);
            if (i == n)
                right.push_back(nullptr);
            for (int il = 0, el = left.size(); il < el; il++)
            {
                for (int ir = 0, er = right.size(); ir < er; ir++)
                {
                    TreeNode *node = new TreeNode(i);
                    node->left = left[il];
                    node->right = right[ir];
                    res.push_back(node);
                }
            }
        }
        cache[pair(n, base)] = res;
        return res;
    }
};
