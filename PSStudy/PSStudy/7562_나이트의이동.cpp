#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Position
{
	int x;
	int y;
};

int N, L;
Position start, des; 
vector<vector<int>> dp;
vector<int> dx = {1,2,2,1,-1,-2,-2,-1};
vector<int> dy = {2,1,-1,-2,-2,-1,1,2};

bool IsInRange(int x, int y)
{
	if (0 <= x && x < L &&
		0 <= y && y < L)
		return true;
	return false;
}

int main()
{
	cin >> N;


	for (int i = 0; i < N; ++i)
	{
		cin >> L;
		cin >> start.x >> start.y;
		cin >> des.x >> des.y;

		if (start.x == des.x && start.y == des.y)
		{
			cout << 0 << endl;
			continue;
		}

		dp = vector<vector<int>>(L, vector<int>(L, -1));

		dp[start.x][start.y] = 0;
		queue<Position> q;
		q.push(start);

		//BFS·Î Ç®±â
		while (!q.empty())
		{
			auto tmp = q.front();
			q.pop();
			
			for (int i = 0; i < 8; ++i)
			{
				int nextX = tmp.x + dx[i];
				int nextY = tmp.y + dy[i];
				
				if (IsInRange(nextX, nextY) && dp[nextX][nextY] == -1)
				{
					dp[nextX][nextY] = dp[tmp.x][tmp.y] + 1;
					q.push({ nextX, nextY });
				}
			}
		}

		cout << dp[des.x][des.y] << endl;


	}
	

	return 0;
}