class Solution
{
  public:
	bool queryString(string S, int N)
	{
		set<int> exist;
		set<int> prev;
		for (int i = 0, e = S.length(); i < e; i++)
		{
			set<int> cur;
			exist.insert(S[i] - '0');
			prev = getPrevNum(S, i - 1);
			for (auto num : prev)
			{
				if (num <= INT_MAX / 2)
				{
					int in = num * 2 + (S[i] - '0');
					cur.insert(in);
					exist.insert(in);
				}
			}
			cur.swap(prev);
		}
		for (int i = 1; i <= N; i++)
		{
			if (exist.find(i) == exist.end())
				return false;
		}
		return true;
	}
	set<int> getPrevNum(string &S, int end)
	{
		set<int> result;
		if (end <= 0)
			return result;
		int num = S[end] - '0';
		result.insert(num);
		for (int i = 1; end - i >= 0 && i < 31; i++)
		{
			num = ((S[end - i] - '0') << i) + num;
			result.insert(num);
		}
		return result;
	}
};
