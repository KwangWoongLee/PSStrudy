#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
struct Node
{
	int idx;
	int dist;
};

unordered_map<int, list<Node>> l;
vector<bool> visit;
int maxDiameter = -1;


void DFS(int node, int sum)
{
	if (sum > maxDiameter)
		maxDiameter = sum;

	for (auto& element : l[node]) // 인접 노드들에 대하여 DFS
	{
		if (visit[element.idx])
			continue;

		visit[element.idx] = true;
		DFS(element.idx, sum + element.dist);
		visit[element.idx] = false;
	}
}

int main()
{
	int N;
	cin >> N;
	
	visit = vector<bool>(N+1, false);

	for (int i = 0; i < N-1; ++i)
	{
		int parent, child, dist;
		cin >> parent >> child >> dist;

		l[parent].push_back({ child,dist });
		l[child].push_back({ parent,dist });
	}


	for (auto& element : l)
	{
		visit[element.first] = true;
		DFS(element.first, 0);
		visit[element.first] = false;
	}
	
	
	cout << maxDiameter;

	return 0;
}