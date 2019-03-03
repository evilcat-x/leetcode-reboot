#include <vector>
#include <numeric>
#include <map>
#include <string>
using namespace std;

class Solution
{
  public:
	vector<string> commonChars(vector<string> &A)
	{
		int m[26];
		fill(m, m + 26, INT_MAX);
		vector<string> result;
		for (auto &s : A)
		{
			int n_count[26] = {0};
			for (auto &c : s)
				n_count[c - 'a']++;
			for (int i = 0; i < 26; i++)
				m[i] = min(m[i], n_count[i]);
		}
		for (int i = 0; i < 26; i++)
			if (m[i] != INT_MAX)
				for (int j = 0, e = m[i]; j < e; j++)
					result.push_back(string(1, (char)(i + 'a')));
		return result;
	}
};
