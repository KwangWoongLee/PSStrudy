#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int W,H;
int land;
vector<vector<bool>> visited;
vector<vector<int>> map;
vector<int> result;

vector<int> dx = { 0,0,1,1,1,-1,-1,-1 };
vector<int> dy = { 1,-1,1,0,-1,1,0,-1  };

bool IsInRange(int x, int y)
{
	if (0 <= x && x < H
		&& 0 <= y && y < W)
		return true;
	return false;
}

void DFS(int x, int y)
{
	visited[x][y] = true;

	for (int i = 0; i < 8; ++i)
	{
		int nextX = x + dx[i];
		int nextY = y + dy[i];

		if (IsInRange(nextX, nextY) && !visited[nextX][nextY] && map[nextX][nextY] == 1)
			DFS(nextX, nextY);
	}
}

int main()
{
	while (true)
	{
		cin >> W >> H;
		if (W == 0 && H == 0)
			break;

		land = 0;

		visited = vector<vector<bool>>(H, vector<bool>(W, false));
		map = vector<vector<int>>(H, vector<int>(W));

		for (int i = 0; i < H; ++i)
		{
			for (int j = 0; j < W; ++j)
			{
				cin >> map[i][j];
			}
		}


		for (int i = 0; i < H; ++i)
		{
			for (int j = 0; j < W; ++j)
			{
				if (!visited[i][j] && map[i][j] == 1)
				{
					DFS(i, j);
					++land;
				}
			}
		}

		cout << land << "\n";

	}
	

	return 0;
}
