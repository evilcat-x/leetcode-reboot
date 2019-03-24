class Solution
{
  public:
	int shipWithinDays(vector<int> &weights, int D)
	{
		int sum = 0;
		int capacity = 0;
		int atLeast = 0;
		for (int i = 0, e = weights.size(); i < e; i++)
		{
			sum += weights[i];
			atLeast = max(atLeast, weights[i]);
		}
		capacity = max(1 + (sum - 1) / D, atLeast);
		while (needMore(weights, D, capacity))
		{
			capacity++;
		}

		return capacity;
	}
	bool needMore(vector<int> &w, int d, int c)
	{
		int end = w.size();
		int dayNeeded = 0;
		int i = 0;
		while (i < end)
		{
			int sum = w[i];
			while (sum < c && i + 1 < end && sum + w[i + 1] <= c)
			{
				sum += w[i + 1];
				i++;
			}
			dayNeeded++;
			i++;
		}
		return dayNeeded > d;
	}
};
