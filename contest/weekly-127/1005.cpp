class Solution
{
  public:
	int largestSumAfterKNegations(vector<int> &A, int K)
	{
		if (K == 0)
		{
			int sum = 0;
			for (int i = 0, e = A.size(); i < e; i++)
			{
				sum += A[i];
			}
			return sum;
		}
		int index = 0;
		for (int i = 0, e = A.size(); i < e; i++)
		{
			if (A[i] < A[index])
				index = i;
		}
		A[index] = -A[index];
		int negative = 0;
		for (int i = 0, e = A.size(); i < e; i++)
		{
			if (A[i] < 0)
				negative++;
		}
		if (negative == 0 && K - 1 > 1)
			return largestSumAfterKNegations(A, (K - 1) % 2);
		return largestSumAfterKNegations(A, K - 1);
	}
};
