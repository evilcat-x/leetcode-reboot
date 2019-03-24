#include <iostream>
#include <vector>
#include <climits>
#include <utility>
using namespace std;

int solve(vector<int> &S, int P)
{
	int T[10001] = {0};
	vector<pair<int, int>> Skill;
	for (auto &s : S)
		T[s]++;
	for (int i = 1; i <= 10000; i++)
	{
		if (T[i] >= P)
			return 0;
		if (T[i] != 0)
			Skill.push_back(make_pair(i, T[i]));
	}

	int left = 0, right = 1, end = Skill.size();
	int sumOfT = Skill[left].second * Skill[left].first;
	int numOfP = Skill[left].second, minOfTrain = INT_MAX;
	int numOfRightP = 0;
	while (right < Skill.size())
	{
		if (numOfP < P)
		{
			if (numOfRightP < Skill[right].second)
			{
				numOfRightP++;
				numOfP++;
				sumOfT += Skill[right].first;
			}
			else if (numOfRightP == Skill[right].second)
			{
				right++;
				numOfRightP = 0;
			}
		}
		else if (numOfP == P)
		{
			if (Skill[left].second == 0)
				left++;
			else
			{
				minOfTrain = min(minOfTrain, P * Skill[right].first - sumOfT);
				numOfP--;
				Skill[left] = make_pair(Skill[left].first, Skill[left].second - 1);
				sumOfT -= Skill[left].first;
			}
		}
	}
	return minOfTrain;
}

int main()
{
	int numOfCase;
	cin >> numOfCase;
	for (int nCase = 0; nCase < numOfCase; nCase++)
	{
		int N, P;
		cin >> N >> P;
		vector<int> S(N);
		for (int i = 0; i < N; i++)
			cin >> S[i];
		int result = solve(S, P);
		cout << "Case #" << nCase + 1 << ": " << result << endl;
	}
	return 0;
}
