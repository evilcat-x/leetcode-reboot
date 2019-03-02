class Solution
{
  public:
	int maxWidthRamp(vector<int> &A)
	{
		int max = 0;
		vector<int> B(A);
		sort(B.begin(), B.end());
		unordered_map<int, int> left;
		unordered_map<int, int> right;
		for (int i = 0, e = A.size(); i < e; i++)
		{
			if (left.find(A[i]) == left.end())
			{
				left[A[i]] = i;
			}
			right[A[i]] = i;
		}
		int lmost = -1;
		for (int i = 0, e = B.size(); i < e; i++)
		{
			if (lmost == -1)
			{
				lmost = left[B[i]];
			}
			else
			{
				int r = right[B[i]];
				int l = left[B[i]];
				int dis = r - lmost;
				if (dis > max)
					max = dis;
				if (l < lmost)
					lmost = l;
			}
		}
		return max;
	}
};
