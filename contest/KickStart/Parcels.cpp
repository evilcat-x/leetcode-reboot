#include <iostream>
#include <vector>
#include <climits>
#include <utility>
#include <queue>
#include <set>
using namespace std;

int solve(vector<vector<int>> &G, int R, int C)
{
	queue<pair<int, int>> q;
	set<pair<int, int>> v;
	for (int row = 0; row < R; row++)
	{
		for (int col = 0; col < C; col++)
		{
			if (G[row][col] == 1)
			{
				auto p = make_pair(row, col);
				q.push(p);
				v.insert(p);
			}
		}
	}
	if (q.size() == R * C)
		return 0;
	int fill = 0;
	while (q.size() != 0)
	{
		int round = q.size();
		while (round--)
		{
			auto p = q.front();
			q.pop();
			G[p.first][p.second] = fill;
			p.first--;
			if (p.first >= 0 && v.find(p) == v.end())
			{
				q.push(p);
				v.insert(p);
			}
			p.first++;
			p.first++;
			if (p.first < R && v.find(p) == v.end())
			{
				q.push(p);
				v.insert(p);
			}
			p.first--;
			p.second--;
			if (p.second >= 0 && v.find(p) == v.end())
			{
				q.push(p);
				v.insert(p);
			}
			p.second++;
			p.second++;
			if (p.second < C && v.find(p) == v.end())
			{
				q.push(p);
				v.insert(p);
			}
		}
		fill++;
	}
	for (int row = 0; row < R; row++)
	{
		for (int col = 0; col < C; col++)
		{
			cout << G[row][col] << " ";
		}
		cout << endl;
	}
	return 0;
}

int main()
{
	int numOfCase;
	char c;
	cin >> numOfCase;
	for (int nCase = 0; nCase < numOfCase; nCase++)
	{
		int Row, Col;
		cin >> Row >> Col;
		vector<vector<int>> Grid;
		for (int row = 0; row < Row; row++)
		{
			cin.ignore();
			vector<int> r(Col);
			for (int col = 0; col < Col; col++)
			{
				cin.get(c);
				r[col] = c - '0';
			}
			Grid.push_back(r);
		}
		int result = solve(Grid, Row, Col);
		cout << "Case #" << nCase + 1 << ": " << result << endl;
	}
	return 0;
}
