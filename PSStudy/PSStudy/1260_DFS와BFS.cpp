#include <iostream>
#include <vector>

#include <stack>
#include <queue>

int N, M, V;

vector<vector<int>> graph;
vector<bool> visit;

using namespace std;

void BFS()
{
		
}

void DFS()
{
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M >> V;

	graph = vector<vector<int>>(N, vector<int>(N, 0));

	for (int i = 0; i < M; ++i)
	{
		int node, node2;
		cin >> node >> node2;

		graph[node][node2] = 1;
		graph[node2][node] = 1;
	}



	return 0;
}