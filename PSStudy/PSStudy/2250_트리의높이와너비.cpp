#include <iostream>
#include <unordered_map>
#include "Tree.h"

using namespace std;

int main() {

	int N;
	cin >> N;

	vector<bool> nodeVector(N + 1, true);
	vector<pair<int, int>> depthVector(N + 1, {10001,-10001});
	pair<int, int> result = { 1,1 };

	struct cmd
	{
		int node;
		int left;
		int right;
	};

	vector<cmd> cmdVector;

	int node, left, right;

	for (int i = 0; i < N; ++i)
	{
		cin >> node >> left >> right;

		if(left != -1)
			nodeVector[left] = false;
		if(right != -1)
		nodeVector[right] = false;

		cmdVector.push_back({ node, left, right });
	}

	int root;

	for (int i=1; i< N+2; ++i)
	{
		if (nodeVector[i])
		{
			root = i;
			break;
		}
	}

	Tree<int> t(root);

	for (auto& cmd : cmdVector)
	{
		auto parent = t.FindNodeToValue(cmd.node);

		if (parent != nullptr)
		{
			if (cmd.left != -1)
				t.PushLeftChild(parent, cmd.left);

			if (cmd.right != -1)
				t.PushRightChild(parent, cmd.right);
		}
	}

	vector<Node<int>*> location(1);
	t.InOrderToMakeLocation(t.GetRoot(), location);

	for (int i=1; i<N+1; ++i)
	{
		auto node = location[i];
		if (depthVector[node->mDepth].first == 10001)
		{
			depthVector[node->mDepth].first = i;
		}
		else
		{
			depthVector[node->mDepth].second = i;
		}
	}

	for (int i = 1; i < N + 1; ++i)
	{
		int min = depthVector[i].first;
		int max = depthVector[i].second;

		if (result.second < max - min + 1)
		{
			result.second = max - min + 1;
			result.first = i;
		}
	}

	cout << result.first << " " << result.second;
	return 0;

}