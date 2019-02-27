#include <vector>
#include <queue>
#include <set>
#include <iostream>
#include <utility>
using namespace std;

class Solution
{
public:
	void wallsAndGates(vector<vector<int>> &rooms)
	{
		queue<pair<int,int>> q_room;
        set<pair<int,int>> filled;
		int step = 0;
		int height = rooms.size();
		int width;
		if (height > 0)
			width = rooms[0].size();

		for(int i = 0; i != height; i++)
		{
			for(int j = 0; j != width; j++)
			{
				if(rooms[i][j] == 0)
                {
                    q_room.push(pair(i,j));
                    filled.insert(pair(i,j));
                }
			}
		}
		while (!q_room.empty())
		{
			for (int i = 0, e = q_room.size(); i != e; i++)
			{
				auto p = q_room.front();
				if (rooms[p.first][p.second] != -1)
				{
					fillAdjacentRoom(p, q_room, filled, width, height);
					rooms[p.first][p.second] = step;
				}
				q_room.pop();
			}
			step++;
		};
	}
	void fillAdjacentRoom(pair<int, int> p,
		queue<pair<int, int>> &q_room,
		set<pair<int,int>> &filled, int width, int height)
	{
		if (p.first - 1 >= 0)
		{
			p.first--;
			fillOnlyNewRoom(p, q_room, filled);
			p.first++;
		}
		if (p.first + 1 < height)
		{
			p.first++;
			fillOnlyNewRoom(p, q_room, filled);
			p.first--;
		}
		if (p.second - 1 >= 0)
		{
			p.second--;
			fillOnlyNewRoom(p, q_room, filled);
			p.second++;
		}
		if (p.second + 1 < width)
		{
			p.second++;
			fillOnlyNewRoom(p, q_room, filled);
			p.second--;
		}
	}
	void fillOnlyNewRoom(pair<int, int> p, queue<pair<int, int>> &q_room, set<pair<int,int>> &filled)
	{
		if (filled.find(p) == filled.end())
		{
			q_room.push(p);
			filled.insert(p);
		}
	}
};
