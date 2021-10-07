#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> list;
vector<bool> visit;

int N, M;
bool result;

void DFS(int human, int depth)
{
	if (depth == 5)
	{
		result = true;
		return;
	}


	visit[human] = true;

	for (int i = 0; i < list[human].size(); ++i)
	{
		if(visit[list[human][i]] == false) // 아직 방문하지 않았다면
		{
			DFS(list[human][i], depth+1);

			if (result == true)
				return;
		}
	}

	visit[human] = false;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	result = false;

	list = vector<vector<int>>(N);
	visit = vector<bool>(N, false);

	for(int i=0; i<M; ++i)
	{
		int human1, human2;
		cin >> human1 >> human2;

		list[human1].push_back(human2);
		list[human2].push_back(human1);
	}


	
	for (int i = 0; i < N; ++i)
	{
		DFS(i, 1);

		if (result == true)
			break;
	}


	cout << result;

	return 0;
}
