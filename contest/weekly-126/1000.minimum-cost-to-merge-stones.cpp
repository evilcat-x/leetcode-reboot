#include <vector>
#include <numeric>
#include <map>
#include <string>
#include <algorithm>
#include <stack>
#include <map>
#include <utility>
using namespace std;

class Solution
{
  private:
	vector<int> s;
	vector<int> prefix;
	map<tuple<int, int, int>, int> m;
	int p;

  public:
	int mergeStones(vector<int> &stones, int K)
	{
		if ((stones.size() - 1) % (K - 1))
			return -1;
		s = stones;
		p = K;
		prefix.push_back(0);
		for (auto &n : stones)
			prefix.push_back(n + prefix.back());
		int result = dp(0, stones.size() - 1, 1);
		return result < INT_MAX ? result : -1;
	}
	int dp(int head, int tail, int pile)
	{
		if ((tail - head + 1 - pile) % (p - 1))
			return INT_MAX;
		if (m.find(make_tuple(head, tail, pile)) != m.end())
			return m[make_tuple(head, tail, pile)];
		if (head == tail)
			return pile == 1 ? 0 : INT_MAX;
		else
		{
			int result;
			if (pile == 1)
				result = dp(head, tail, p) + prefix[tail + 1] - prefix[head];
			else
			{
				result = INT_MAX;
				for (int mid = head, e = tail; mid < tail; mid += p - 1)
				{
					int left = dp(head, mid, 1);
					int right = dp(mid + 1, tail, pile - 1);
					if (left == INT_MAX || right == INT_MAX)
						continue;
					result = min(result, left + right);
				}
			}
			m[make_tuple(head, tail, pile)] = result;
			return result;
		}
	}
};
