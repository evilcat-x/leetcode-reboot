class Solution
{
  public:
	int numDupDigitsAtMostN(int N)
	{
		if (N < 10)
			return 0;
		int result = 0;
		int d = 1;
		int len = 1;
		int rangeFrom = d;
		int rangeTo = d;
		set<int> used;
		while (rangeTo <= N)
		{
			if (rangeTo != rangeFrom)
				result += numDup(rangeFrom, rangeTo, len, used);
			d *= 10;
			rangeFrom = d;
			rangeTo = d * 10 - 1;
			len++;
		}
		// while (rangeFrom != N)
		// {
		// }
		return result;
	}
	int numDup(int rangeFrom, int rangeTo, int len, set<int> used)
	{

		int shift = len - used.size() - 1;
		int d = pow(10, shift);
		cout << rangeFrom << " " << rangeTo << " " << len << " " << d << endl;
		int total = (rangeTo / d) % 10 - (rangeFrom / d) % 10 + 1;
		int noDup = 0;
		for (int i = (rangeFrom / d) % 10; i <= (rangeTo / d) % 10; i++)
		{
			if (used.find(i) == used.end())
				noDup++;
		}

		int numUsed = used.size() + 1;
		cout << shift << " " << total << " " << noDup << " " << numUsed << endl;
		for (int i = 0; i < shift; i++)
		{
			total *= 10;
			noDup *= 10 - numUsed - i;
		}
		cout << total << " " << noDup << endl;
		return total - noDup;
	}
};
