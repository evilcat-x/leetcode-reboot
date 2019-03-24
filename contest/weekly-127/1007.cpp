class Solution
{
  public:
	int minDominoRotations(vector<int> &A, vector<int> &B)
	{
		int m = INT_MAX;
		for (int i = 1; i <= 6; i++)
		{
			m = min(m, minX(A, B, i));
		}
		return m == INT_MAX ? -1 : m;
	}
	int minX(vector<int> &A, vector<int> &B, int target)
	{
		int countA = 0;
		int countB = 0;
		for (int i = 0, e = A.size(); i < e; i++)
		{
			if (A[i] != target && B[i] != target)
				return INT_MAX;
			if (A[i] == target && B[i] != target)
				countB++;
			if (B[i] == target && A[i] != target)
				countA++;
		}
		return min(countA, countB);
	}
};
