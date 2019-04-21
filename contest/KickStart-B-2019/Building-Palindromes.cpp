#include <iostream>
#include <vector>
#include <climits>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<vector<int>> buildMap(string &str, int len)
{
	vector<vector<int>> result;
	for (int c = 'A'; c <= 'Z'; c++)
	{
		int count = 0;
		vector<int> charCount;
		for (int i = 0; i < len; i++)
		{
			if (str[i] == c)
				count++;
			charCount.push_back(count);
		}
		result.push_back(charCount);
	}
	return result;
}

bool canBuildPalindromes(vector<vector<int>> &charMap, int left, int right)
{
	int oddChar = 0;
	bool oddLen = (right - left + 1) % 2;
	for (int c = 'A'; c <= 'Z'; c++)
	{
		int nChar = charMap[c - 'A'][right] -
					((left - 1 >= 0) ? charMap[c - 'A'][left - 1] : 0);
		//cout << (char)c << ": " << left << "-" << right << " " << nChar << endl;
		if (nChar % 2)
			oddChar++;

		if ((!oddLen && oddChar) || (oddLen && oddChar > 1))
			return false;
	}
	return true;
}

int main()
{
	int numOfCase;
	char c;
	cin >> numOfCase;
	for (int nCase = 0; nCase < numOfCase; nCase++)
	{
		int len, testCases, count = 0;
		cin >> len >> testCases;
		string str;
		cin >> str;
		auto charMap = buildMap(str, len);
		for (int nTest = 0; nTest < testCases; nTest++)
		{
			int L, R;
			bool result;
			cin >> L >> R;
			if ((result = canBuildPalindromes(charMap, L - 1, R - 1)))
				count++;
			//cout << L << " " << R << " " << result << endl;
		}
		cout << "Case #" << nCase + 1 << ": " << count << endl;
	}
	return 0;
}
