#include <set>
#include <utility>
#include <vector>
using namespace std;
class Solution
{
  public:
	double minAreaFreeRect(vector<vector<int>> &points)
	{
		set<pair<int, pair<int, int>>> pset;
		for (int i = 0, e = points.size(); i < e; i++)
		{
			pset.insert(pair(points[i][0], pair(points[i][0], points[i][1])));
		}
		pair<int, pair<int, int>> p;
		double min = DBL_MAX;
		double area = DBL_MAX;
		for (int i = 0, e = points.size(); i < e; i++)
		{
			for (int j = i + 1; j < e; j++)
			{
				for (int k = j + 1; k < e; k++)
				{
					if (is90(points[i], points[j], points[k]))
					{
						p = getFourthPoint(points[i], points[j], points[k]);
						if (pset.find(p) != pset.end())
						{
							area = getArea(points[i], points[j], points[k]);
						}
					}
					else if (is90(points[i], points[k], points[j]))
					{
						p = getFourthPoint(points[i], points[k], points[j]);
						if (pset.find(p) != pset.end())
						{
							area = getArea(points[i], points[k], points[j]);
						}

					}
					else if (is90(points[k], points[i], points[j]))
					{
						p = getFourthPoint(points[k], points[i], points[j]);
						if (pset.find(p) != pset.end())
						{
							area = getArea(points[k], points[i], points[j]);
						}

					}
					if (area < min) {
						min = area;
                    }
				}
			}
		}
		return min == DBL_MAX ? 0 : min;
	}
	int is90(vector<int> &p1, vector<int> &p2, vector<int> &p3)
	{
		return (p2[0] - p1[0]) * (p2[0] - p3[0]) + (p2[1] - p1[1]) * (p2[1] - p3[1]) == 0;
	}
	double getArea(vector<int> &p1, vector<int> &p2, vector<int> &p3)
	{
        double x = abs(p2[0]-p1[0]) + abs(p2[0]-p3[0]);
        double y = abs(p2[1]-p1[1]) + abs(p2[1]-p3[1]);
        return x * y - abs(p2[0]-p1[0]) * abs(p2[1]-p1[1]) - abs(p2[0]-p3[0]) * abs(p2[1]-p3[1]);
	}
	pair<int, pair<int, int>> getFourthPoint(vector<int> &p1, vector<int> &p2, vector<int> &p3)
	{
		int x, y;
		x = p1[0] - p2[0] + p3[0];
		y = p1[1] - p2[1] + p3[1];
		return pair(x, pair(x, y));
	}
};
