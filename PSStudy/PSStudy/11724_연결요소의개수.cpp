#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> nodeList;
vector<bool> visit;
int N, M;

void DFS(int node) 
{
	if (visit[node])
		return;

	visit[node] = true;

	for (int i = 0; i < nodeList[node].size(); ++i)
	{
		DFS(nodeList[node][i]);
	}

}

int main()
{
	cin >> N >> M;

	nodeList = vector<vector<int>>(N+1);
	visit = vector<bool>(N+1, false);
	int result = 0;

	if (M == 0)
	{
		cout << result;
		return 0;
	}

	for (int i = 0; i < M; ++i)
	{
		int node, node2;
		cin >> node >> node2;
		nodeList[node].push_back(node2);
		nodeList[node2].push_back(node);
	}

	for (int i = 1; i < N+1; ++i)
	{
		if (!visit[i])
		{
			++result;
			DFS(i);
		}
	}

	cout << result;

	return 0;
}