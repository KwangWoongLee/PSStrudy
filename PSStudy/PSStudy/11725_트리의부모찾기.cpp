#include <iostream>

#include <vector>

using namespace std;

vector<vector<int>> nodeList;
vector<bool> visit;
vector<int> result;

void DFS(int depth, int parentIdx)
{
	visit[parentIdx] = true;

	for (auto& node : nodeList[parentIdx])
	{
		if (!visit[node])
		{
			DFS(depth + 1, node);
			result[node] = parentIdx;
		}
		
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	nodeList = vector<vector<int>>(N + 1);
	visit = vector < bool >(N + 1, false);
	result = vector < int >(N + 1, 0);


	for (int i = 0; i < N-1; ++i)
	{
		int node, node2;
		cin >> node >> node2;

		nodeList[node].push_back(node2);
		nodeList[node2].push_back(node);
	}


	DFS(1, 1);

	for (int i = 2; i < N + 1; ++i)
		cout << result[i] << "\n";

	return 0;
}

