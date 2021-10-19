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
vector<vector<int>> map;
vector<vector<int>> dp;
queue<Position> q;

vector<int> dx = { 0, 0, 1, -1 };
vector<int> dy = { 1,-1,0,0 };

bool IsInRange(int x, int y)
{
	if (0 <= x && x < N
		&& 0 <= y && y < M)
		return true;
	return false;
}

int main()
{
	cin >> M >> N;
	int result = 0;
	bool all = true;
	bool notFinally = false;

	map = vector<vector<int>>(N, vector<int>(M));
	dp = vector<vector<int>>(N, vector<int>(M, -1));

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; ++j)
		{
			cin >> map[i][j];
			if (map[i][j] == 0) // 하나라도 안 익은게 있다면,
			{
				all = false;
			}
		}


	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; ++j)
		{
			if (map[i][j] == 1)
			{
				dp[i][j] = 0;
				q.push({ i, j });
			}
		}

	while (!q.empty())
	{
		auto tmp = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nextX = tmp.x + dx[i];
			int nextY = tmp.y + dy[i];

			if (IsInRange(nextX, nextY) && dp[nextX][nextY] == -1 && map[nextX][nextY] == 0)
			{
				q.push({ nextX, nextY });

				dp[nextX][nextY] = dp[tmp.x][tmp.y] + 1;
			}
		}
	}

	//모두 익은 경우
	if (all)
		result = 0;
	else
	{
		for(int i=0; i<N; ++i)
			for (int j = 0; j < M; ++j)
			{
				result = max(result, dp[i][j]);

				if (map[i][j] == 0 && dp[i][j] == 0) // 익지않은 토마토 하나라도 있으면
					notFinally = true;
			}
	}

	if (notFinally)
		result = -1;

	cout << result;

	return 0;

}
