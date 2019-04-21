#include <iostream>
#include <vector>
#include <climits>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Stone
{
	int S;
	int E;
	int L;
};

int getCostOfEating(vector<Stone> &stones, int index)
{
	int S = stones[index].S;
	int cost = 0;
	for (int i = 0, e = stones.size(); i < e; i++)
	{
		if (i == index)
			continue;
		cost += min(stones[i].L * S, stones[i].E);
	}
	return cost;
}

void eatStone(vector<Stone> &stones, int index)
{
	int S = stones[index].S;
	for (int i = 0, e = stones.size(); i < e; i++)
	{
		if (i != index)
			stones[i].E = max(0, stones[i].E - stones[i].L * S);
		else
		{
			stones[i].S = 0;
			stones[i].E = 0;
		}
	}
}

int getMaxEnergy(vector<Stone> &stones, int nStones)
{
	int minNetCost = INT_MAX;
	int minIndex = 0;
	int energy = 0;
	for (int i = 0, e = stones.size(); i < e; i++)
	{
		if (stones[i].S == 0)
			continue;
		int cost = getCostOfEating(stones, i);
		int saved = max(stones[i].E, stones[i].L * stones[i].S);
		if (cost - saved < minNetCost)
		{
			minNetCost = cost;
			minIndex = i;
			energy = stones[i].E;
		}
	}
	//cout << "min cost index:" << minIndex << endl;
	eatStone(stones, minIndex);
	return energy;
}

int main()
{
	int numOfCase;
	char c;
	cin >> numOfCase;
	for (int nCase = 0; nCase < numOfCase; nCase++)
	{
		int N;
		cin >> N;
		vector<struct Stone> stones;
		for (int i = 0; i < N; i++)
		{
			struct Stone s;
			cin >> s.S >> s.E >> s.L;
			stones.push_back(s);
		}
		int maxEnergy = 0;
		for (int i = 0; i < N; i++)
		{
			int energy = getMaxEnergy(stones, N);
			maxEnergy += energy;
			//	cout << "eating : " << energy << endl;
		}
		cout << "Case #" << nCase + 1 << ": " << maxEnergy << endl;
	}
	return 0;
}
