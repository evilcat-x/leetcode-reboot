class Solution
{
  public:
	int clumsy(int N)
	{
		queue<int> q;
		int sum = 0;
		int first = 1;
		for (int i = N; i > 0; i--)
			q.push(i);
		if (q.size() >= 4)
		{
			int a = q.front();
			q.pop();
			int b = q.front();
			q.pop();
			int c = q.front();
			q.pop();
			int d = q.front();
			q.pop();
			sum += a * b / c + d;
			first = -1;
		}
		while (q.size() >= 4)
		{
			int a = q.front();
			q.pop();
			int b = q.front();
			q.pop();
			int c = q.front();
			q.pop();
			int d = q.front();
			q.pop();
			sum = sum - a * b / c + d;
		}
		if (q.size() == 3)
		{
			int a = q.front();
			q.pop();
			int b = q.front();
			q.pop();
			int c = q.front();
			q.pop();
			sum = sum + first * (a * b / c);
		}
		if (q.size() == 2)
		{
			int a = q.front();
			q.pop();
			int b = q.front();
			q.pop();
			sum = sum + first * (a * b);
		}
		if (q.size() == 1)
		{
			int a = q.front();
			q.pop();
			sum = sum + first * a;
		}
		return sum;
	}
};
