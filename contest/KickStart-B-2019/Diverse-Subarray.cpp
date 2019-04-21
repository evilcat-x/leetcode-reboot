#include <iostream>
#include <vector>
#include <climits>
#include <utility>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <string>
using namespace std;

int getMaxTrinkets(vector<int> T, int N, int S)
{
	int maxTotal = 1;
	for (int l = 0; l < N; l++)
	{
		unordered_set<int> overLimit;
		unordered_map<int, int> m;
		int numOfT = 1;
		int maxRow = 1;
		for (int r = l; r < N; r++)
		{
			int typeT = T[r];
			if (r == l)
			{
				m[typeT] = 1;
				continue;
			}
			if (m.find(typeT) == m.end())
			{
				m[typeT] = 1;
				numOfT++;
			}
			else
			{
				m[typeT]++;
				if (m[typeT] <= S)
					numOfT++;
				else if (overLimit.find(typeT) == overLimit.end())
				{
					numOfT -= m[typeT] - 1;
					overLimit.insert(typeT);
				}
			}
			maxRow = max(maxRow, numOfT);
			//cout << "L: " << l << " R: " << i << " max:" << maxRow << endl;
		}
		//cout << "rowmax :" << maxRow << endl;
		maxTotal = max(maxTotal, maxRow);
	}
	return maxTotal;
}

int main()
{
	int numOfCase;
	char c;
	cin >> numOfCase;
	for (int nCase = 0; nCase < numOfCase; nCase++)
	{
		int N, S, t;
		cin >> N >> S;
		vector<int> T;
		for (int i = 0; i < N; i++)
		{
			cin >> t;
			T.push_back(t);
		}
		int maxT = getMaxTrinkets(T, N, S);
		cout << "Case #" << nCase + 1 << ": " << maxT << endl;
	}
	return 0;
}
