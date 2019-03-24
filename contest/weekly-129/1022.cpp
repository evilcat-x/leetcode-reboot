class Solution
{
  public:
	int smallestRepunitDivByK(int K)
	{
		if (K % 2 == 0 || K % 5 == 0)
			return -1;
		int result = 1;
		int mod = 1 % K;
		while (mod)
		{
			mod = (mod + (mod * 9 + 1)) % K;
			result++;
		}
		return result;
	}
};
