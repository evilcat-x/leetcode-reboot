class Solution
{
  public:
	bool canThreePartsEqualSum(vector<int> &A)
	{
		int total = accumulate(A.begin(), A.end(), 0);
		int sum1 = 0, sum2 = 0, sum3 = 0;
		if (total % 3 != 0)
			return false;
		for (int i = 0, e = A.size(); i < e; i++)
		{
			if (sum1 != total / 3)
				sum1 += A[i];
			else if (sum2 != total / 3)
				sum2 += A[i];
			else
				sum3 += A[i];
		}
		return sum1 == sum2 && sum2 == sum3 && sum3 == total / 3;
	}
};
