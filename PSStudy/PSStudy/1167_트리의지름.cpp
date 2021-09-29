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
pair<int, int> result = { 1,1 };



void DFS(int nextNode, int distSum)
{
	if (result.second < distSum)
	{
		result.first = nextNode;
		result.second = distSum;
	}

	visit[nextNode] = true;


	for (auto& node : nodeList[nextNode])
	{
		if (!visit[node.idx])
		{

			DFS(node.idx, distSum + node.dist);
		}

	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);



	int N;
	cin >> N;

	nodeList = vector<vector<Node>>(N + 3);
	visit = vector < bool >(N + 1, false);

	for (int i = 0; i < N; ++i)
	{
		int node, node2, dist;
		cin >> node;

		while (true)
		{
			cin >> node2;
			if (node2 == -1)
				break;

			cin >> dist;

			nodeList[node].push_back({ node2 , dist });
			nodeList[node2].push_back({ node , dist });
		}



	}

	DFS(1, 0);

	visit = vector < bool >(N + 1, false);

	DFS(result.first, 0);

	cout << result.second;

	return 0;
}

