#include <string>
#include <stack>
using namespace std;

class Solution
{
  public:
	bool isValid(string S)
	{
		stack<int> st;
		for (int i = 0, e = S.length(); i < e; i++)
		{
			if (!st.empty() && S[i] - 'a' == 2)
			{
				if (st.top() != 1)
					return false;
				else
				{
					st.pop();
					if (st.empty() || st.top() != 0)
						return false;
					st.pop();
				}
			}
			else
				st.push(S[i] - 'a');
		}
		return st.empty();
	}
};
