#include <queue>
using namespace std;

class MovingAverage
{
  private:
	queue<int> cache;
	int limit;
	int nNum;
	int sum;

  public:
	/** Initialize your data structure here. */
	MovingAverage(int size) : limit(size), nNum(0), sum(0)
	{
	}

	double next(int val)
	{
		if (nNum == limit)
		{
			sum -= cache.front();
			cache.pop();
		}
		else
			nNum++;
		cache.push(val);
		sum += val;
		return sum / (double)nNum;
	}
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
