class Solution
{
  public:
	int bitwiseComplement(int N)
	{
		if (N == 0)
			return 1;
		int b = 1;
		int result = 0;
		while (N != 0)
		{
			result += (1 - (N % 2)) * b;
			N = N >> 1;
			b = b << 1;
		}
		return result;
	}
};
