#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Position
{
	int x;
	int y;
};

int N, M;
vector<string> map;
vector<vector<int>> dp;
queue<Position> q;

vector<int> dx = { 0,0,1,-1 };
vector<int> dy = { 1,-1,0,0, };

bool IsInRange(int x, int y)
{
	if (0 <= x && x < N
		&& 0 <= y && y < M)
		return true;
	return false;
}

int main()
{
	cin >> N >> M;

	map = vector<string>(N);
	dp = vector<vector<int>>(N, vector<int>(M,false));

	for (int i = 0; i < N; i++)
	{
		cin >> map[i];
	}

	dp[0][0] = 1;
	q.push({ 0, 0 });
	
	while (!q.empty())
	{
		auto tmp = q.front();
		q.pop();

		for(int i=0; i<4; ++i)
		{ 
			int nextX = tmp.x + dx[i];
			int nextY = tmp.y + dy[i];

			if (IsInRange(nextX, nextY) && dp[nextX][nextY] == 0 && map[nextX][nextY] == '1')
			{
				q.push({ nextX, nextY });
				dp[nextX][nextY] = dp[tmp.x][tmp.y] + 1;
			}
		}
	}

	cout << dp[N - 1][M - 1];

	return 0;

}
