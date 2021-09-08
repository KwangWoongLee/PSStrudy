#include <iostream>
#include <stack>
#include <deque>
#include <string>
#include <algorithm>

using namespace std;


int main()
{
	string str;
	cin >> str;

	int M;
	cin >> M;

	stack<char> left;
	deque<char> right;

	for (auto& c : str)
		left.push(c);

	for (int i = 0; i < M; ++i)
	{
		string cmd;
		cin >> cmd;

		if (cmd == "P") // cmd가 "P"인 경우만 한번더 cin
		{
			char c;
			cin >> c;


			left.push(c);
		}

		else if (cmd == "L")
		{
			if (left.empty())
			{
				continue;
			}

			right.push_front(left.top());
			left.pop();
		}

		else if (cmd == "D")
		{
			if (right.empty())
			{
				continue;
			}

			left.push(right.front());
			right.pop_front();
		}

		else if (cmd == "B")
		{
			if (left.empty())
			{
				continue;
			}

			left.pop();

		}
	}

	string resultStr = "";

	while (!left.empty())
	{
		right.push_front(left.top());
		left.pop();
	}

	while (!right.empty())
	{
		resultStr += right.front();
		right.pop_front();
	}

	cout << resultStr;

	return 0;
}

