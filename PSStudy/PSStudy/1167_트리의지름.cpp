#include <iostream>

#include <vector>

using namespace std;

struct Node
{
	int idx;
	int dist;
};

vector<vector<Node>> nodeList;
vector<bool> visit;
int result = 1;



void DFS(int nextNode, int distSum)
{
	if (result < distSum)
		result = distSum;
	

	for (auto& node : nodeList[nextNode])
	{
		if (!visit[node.idx])
		{
			visit[node.idx] = true;
			DFS(node.idx, distSum + node.dist);
			visit[node.idx] = false;
		}

	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	

	int N;
	cin >> N;

	nodeList = vector<vector<Node>>(N + 1);
	visit = vector < bool >(N + 1, false);

	for (int i = 0; i < N; ++i)
	{
		int node, node2, dist;
		cin >> node >> node2 >> dist;

		nodeList[node].push_back({ node2 , dist });
		nodeList[node2].push_back({ node , dist });
	}


	for (int i = 1; i < N + 1; ++i)
	{
		visit[i] = true;
		DFS(i, 0);
		visit[i] = false;
	}
		
	cout << result;

	return 0;
}

