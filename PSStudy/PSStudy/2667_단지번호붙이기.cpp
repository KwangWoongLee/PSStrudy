#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int N;
int dangi;
vector<vector<bool>> visited;
vector<vector<int>> map;
vector<int> result;

vector<int> dx = { 0,0,1,-1 };
vector<int> dy = { 1,-1,0,0 };

bool IsInRange(int x, int y)
{
	if (0 <= x && x < N
		&& 0 <= y && y < N)
		return true;
	return false;
}

void DFS(int x, int y)
{
	++result[dangi];

	visited[x][y] = true;

	for (int i = 0; i < 4; ++i)
	{
		int nextX = x + dx[i];
		int nextY = y + dy[i];

		if(IsInRange(nextX, nextY) && !visited[nextX][nextY] && map[nextX][nextY] == 49)
			DFS(nextX, nextY);
	}
}

int main()
{
	cin >> N;
	
	dangi = 0;

	visited = vector<vector<bool>>(N, vector<bool>(N, false));
	map = vector<vector<int>>(N, vector<int>(N));

	for (int i = 0; i < N; ++i)
	{
		string s;
		cin >> s;
		for (int j = 0; j < N; ++j)
		{
			map[i][j] = s[j];
		}
	}


	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (!visited[i][j] && map[i][j] == 49)
			{
				result.push_back(0);
				DFS(i, j);
				++dangi;
			}
		}
	}

	cout << result.size() << "\n";

	sort(result.begin(), result.end());

	for (auto& r : result)
		cout << r << "\n";
		

	return 0;
}
