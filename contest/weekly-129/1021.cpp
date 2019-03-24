class Solution
{
  public:
	int maxScoreSightseeingPair(vector<int> &A)
	{
		vector<int> B = A;
		vector<int> C = A;
		for (int i = 0, e = A.size(); i < e; i++)
		{
			B[i] += i;
			C[i] -= i;
		}
		int maxJ = C.back();
		int maxSum = 0;
		for (int i = A.size() - 2; i >= 0; i--)
		{
			maxSum = max(maxSum, B[i] + maxJ);
			maxJ = max(maxJ, C[i]);
		}
		return maxSum;
	}
};
