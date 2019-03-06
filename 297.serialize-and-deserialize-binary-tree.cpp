/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
 *
 * https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/
 *
 * algorithms
 * Hard (39.40%)
 * Total Accepted:    161.6K
 * Total Submissions: 410K
 * Testcase Example:  '[1,2,3,null,null,4,5]'
 *
 * Serialization is the process of converting a data structure or object into a
 * sequence of bits so that it can be stored in a file or memory buffer, or
 * transmitted across a network connection link to be reconstructed later in
 * the same or another computer environment.
 *
 * Design an algorithm to serialize and deserialize a binary tree. There is no
 * restriction on how your serialization/deserialization algorithm should work.
 * You just need to ensure that a binary tree can be serialized to a string and
 * this string can be deserialized to the original tree structure.
 *
 * Example: 
 *
 *
 * You may serialize the following tree:
 *
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   3
 * ⁠    / \
 * ⁠   4   5
 *
 * as "[1,2,3,null,null,4,5]"
 *
 *
 * Clarification: The above format is the same as how LeetCode serializes a
 * binary tree. You do not necessarily need to follow this format, so please be
 * creative and come up with different approaches yourself.
 *
 * Note: Do not use class member/global/static variables to store states. Your
 * serialize and deserialize algorithms should be stateless.
 *
 */
#include <string>
#include <queue>
#include <sstream>
using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Codec
{
public:
  // Encodes a tree to a single string.
  string serialize(TreeNode *root)
  {
    queue<TreeNode *> q;
    string result = "";
    if (root)
      q.push(root);
    while (!q.empty())
    {
      int size = q.size();
      int hasDeepTree = 0;
      while (size--)
      {
        TreeNode *cur = q.front();
        result += cur ? to_string(cur->val) : "n";
        result += ',';
        q.pop();
        if (cur)
        {
          q.push(cur->left);
          hasDeepTree += cur->left ? 1 : 0;
          q.push(cur->right);
          hasDeepTree += cur->right ? 1 : 0;
        }
      }
      if (!hasDeepTree)
        break;
    }
    return result;
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(string data)
  {
    if (data.empty())
      return nullptr;
    string token;
    istringstream s(data);
    queue<TreeNode *> q;
    getline(s, token, ',');
    TreeNode *root = new TreeNode(stoi(token));
    q.push(root);
    while (!q.empty())
    {
      TreeNode *cur = q.front();
      q.pop();
      if (!getline(s, token, ','))
        break;
      if (token != "n")
      {
        cur->left = new TreeNode(stoi(token));
        q.push(cur->left);
      }
      if (!getline(s, token, ','))
        break;
      if (token != "n")
      {
        cur->right = new TreeNode(stoi(token));
        q.push(cur->right);
      }
    }
    return root;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
