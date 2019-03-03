#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
  public:
	int longestOnes(vector<int> &A, int K)
	{
		int head = 0;
		int zero_c = 0;
		int m = 0;
		for (int i = 0, e = A.size(); i < e; i++)
		{
			if (A[i] == 0)
			{
				if (zero_c == K)
				{
					while (head < e && zero_c == K)
					{
						if (A[head] == 0)
							zero_c--;
						head++;
					}
				}
				zero_c++;
			}
			m = max(m, i - head + 1);
		}
		return m;
	}
};
