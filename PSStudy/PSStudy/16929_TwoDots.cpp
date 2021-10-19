#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<string> map;

vector<int> dx = { 0,0,1,-1 };
vector<int> dy = { 1,-1,0,0 };
vector<vector<bool>> visit;
pair<int, int> start;
char color;
bool result = false;


bool IsInRange(int x, int y)
{
	if (0 <= x && x < N &&
		0 <= y && y < M)
		return true;
	return false;
}

void DFS(int x, int y, int k)
{
	if (result)
		return;

	if(k >= 4)
		for (int i = 0; i < 4; ++i)
		{
			int nextX = x + dx[i];
			int nextY = y + dy[i];
		
			if (nextX == start.first && nextY == start.second)
				result = true;
		}

	for (int i = 0; i < 4; ++i)
	{
		int nextX = x + dx[i];
		int nextY = y + dy[i];

		if (IsInRange(nextX, nextY) && !visit[nextX][nextY] && map[nextX][nextY] == color) 
		{
			visit[nextX][nextY] = true;
			DFS(nextX, nextY, k + 1);
			visit[nextX][nextY] = false;
		}
	}


}

int main()
{
	cin >> N >> M;
	
	map = vector<string>(N);
	visit = vector<vector<bool>>(N, vector<bool>(M, false));
	
	for (int i = 0; i < N; ++i)
	{
		cin >> map[i];
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (result)
			{
				cout << "Yes";
				return 0;
			}

			visit[i][j] = true;
			start = { i,j };
			color = map[i][j];
			DFS(i, j, 1);
			visit[i][j] = false;
		}
	}


	cout << "No";
	return 0;
}