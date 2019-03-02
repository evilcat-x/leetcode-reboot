class Solution
{
  public:
	int repeatedNTimes(vector<int> &A)
	{
		int time[10000] = {0};
		for (int i = 0, e = A.size(); i < e; i++)
		{
			time[A[i]]++;
			if (time[A[i]] == e / 2)
				return A[i];
		}
		return 0;
	}
};
