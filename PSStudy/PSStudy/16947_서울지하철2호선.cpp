#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int N;
vector<vector<int>> list;
vector<bool> visit;
vector<bool> complete;
vector<string> cycles;
queue<int> q;

void DFS(int node, string path)
{


	for (auto& n : list[node])
	{
		if (path.length() >= 3 && n == path[0]-48)
		{
			cycles.push_back(path);

			for (int i=0; i< path.length(); ++i)
			{
				complete[path[i] - 48] = true;
			}

			return;
		}

		if (!visit[n] && !complete[n])
		{
			visit[n] = true;
			DFS(n, path + to_string(n));
			visit[n] = false;
		}
	}
}


int main()
{
	cin >> N;

	list = vector<vector<int>>(N+1);
	visit = vector<bool>(N + 1, false);
	complete = vector<bool>(N + 1, false);

	for (int i = 0; i < N; ++i)
	{
		int st1, st2;
		cin >> st1 >> st2;

		list[st1].push_back(st2);
		list[st2].push_back(st1);
	}

	for (int i = 1; i < N + 1; ++i)
	{
		if (complete[i])
			continue;

		visit[i] = true;
		string str = "";
		str += (i+48);
		DFS(i, str);
		visit[i] = false;
	}

	for (int i = 1; i < N+1; ++i)
	{
		if (complete[i])
			cout << 0;
		else // ¼øÈ¯ X
		{
			q.push(i);
			visit = vector<bool>(N + 1, false);
			visit[i] = true;
			int depth = 1;

			while (!q.empty())
			{
				int tmp = q.front();
				q.pop();

				for (auto& node : list[tmp])
				{
					if (complete[node] && !visit[node])
					{
						cout << depth;
						while (!q.empty()) q.pop();
						break;
					}

					visit[node] = true;
					q.push(node);
				}
				++depth;
			}
		}

		if(i != N)
			cout << " ";
	}


	return 0;
}