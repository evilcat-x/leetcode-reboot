#include <vector>
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
	int sum;

  public:
	int countUnivalSubtrees(TreeNode *root)
	{
		sum = 0;
		traverseSubtrees(root);
		return sum;
	}
	bool traverseSubtrees(TreeNode *root)
	{
		if (!root)
			return true;
		if (!root->left && !root->right)
		{
			sum++;
			return true;
		}
		if (traverseSubtrees(root->left) && traverseSubtrees(root->right))
		{
			if (root->val == (root->left ? root->left->val : root->val) && root->val == (root->right ? root->right->val : root->val))
			{
				sum++;
				return true;
			}
		}
		return false;
	}
};
