class Solution
{
  public:
	int numPairsDivisibleBy60(vector<int> &time)
	{
		if (time.size() <= 1)
			return 0;
		map<int, int> m;
		int result = 0;
		for (int i = 0, e = time.size(); i < e; i++)
		{
			int mod = time[i] % 60;
			if (m.find(mod) == m.end())
				m[mod] = 1;
			else
				m[mod] += 1;
		}
		if (m.find(0) != m.end() && m[0] > 1)
			result += (m[0] * (m[0] - 1)) / 2;
		if (m.find(30) != m.end() && m[30] > 1)
			result += (m[30] * (m[30] - 1)) / 2;
		for (int i = 1; i < 30; i++)
		{
			if (m.find(i) != m.end() && m.find(60 - i) != m.end())
				result += m[i] * m[60 - i];
		}
		return result;
	}
};
