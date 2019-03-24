/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
  public:
	TreeNode *bstFromPreorder(vector<int> &preorder)
	{
		return bstP(preorder, 0, preorder.size() - 1);
	}
	TreeNode *bstP(vector<int> &v, int start, int end)
	{
		cout << start << " " << end << " : " << endl;
		TreeNode *root = new TreeNode(v[start]);
		if (start == end)
			return root;
		int target = v[start];
		int rightStart = start + 1;
		int leftStart = start + 1;
		while (rightStart <= end && v[rightStart] < target)
			rightStart++;
		cout << leftStart << " " << rightStart << endl;
		if (rightStart <= end)
			root->right = bstP(v, rightStart, end);
		if (leftStart <= rightStart - 1)
			root->left = bstP(v, leftStart, rightStart - 1);
		return root;
	}
};
