#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;
struct Node
{
	int idx;
	int dist;
};

unordered_map<int, list<Node>> l;
vector<bool> visit;
pair<int, int> result = { 1,1 };


void DFS(int node, int sum)
{
	if (sum > result.second)
	{
		result.first = node;
		result.second = sum;
	}

	visit[node] = true;

	for (auto& element : l[node]) // 인접 노드들에 대하여 DFS
	{
		if (visit[element.idx])
			continue;

		DFS(element.idx, sum + element.dist);
	}
}

int main()
{
	int N;
	cin >> N;

	visit = vector<bool>(N + 1, false);

	for (int i = 0; i < N - 1; ++i)
	{
		int parent, child, dist;
		cin >> parent >> child >> dist;


		l[parent].push_back({ child,dist });
		l[child].push_back({ parent,dist });
	}


	DFS(1, 0);

	visit = vector<bool>(N + 1, false);

	DFS(result.first, 0);

	for (int i = 0; i < N; ++i)
		DFS(i, 0);

	cout << result.second;

	return 0;
}