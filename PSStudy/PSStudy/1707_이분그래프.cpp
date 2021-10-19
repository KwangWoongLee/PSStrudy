#include <iostream>
#include <vector>

using namespace std;

enum class Color
{
	RED,
	BLUE,
	NONE
};

struct Node
{
	int idx;
	Color color;
};

vector<vector<Node>> nodeList;
vector<bool> visit;
int K, N, M;

void DFS(int node)
{
	if (visit[node])
		return;

	visit[node] = true;

	for (int i = 0; i < nodeList[node].size(); ++i)
	{
		DFS(nodeList[node][i].idx);
	}

}

int main()
{
	cin >> K ;

	for(int k=0; k<K; ++k)
	{
		cin >> N >> M;

		nodeList = vector<vector<Node>>(N + 1);
		visit = vector<bool>(N + 1, false);
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

			nodeList[node].push_back({ node2 , Color::NONE });
			nodeList[node2].push_back({ node , Color::NONE });
		}

		for (int i = 1; i < N + 1; ++i)
		{
			if (!visit[i])
			{
				++result;
				DFS(i);
			}
		}


		if (result == 2)
			cout << "YES";
		else
			cout << "NO";

	}




	return 0;
}