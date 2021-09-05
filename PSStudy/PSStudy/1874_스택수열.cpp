#include <iostream>
#include <vector>
#include <stack>

using namespace std;


int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<int> sequence(N);
	string resultStr;

	for (int i = 0; i < N; ++i)
	{
		cin >> sequence[i];
	}

	stack<int> s;
	int insertedNumber = 1;

	for (int i = 0; i < N; ++i)
	{
		int thisNumber = sequence[i];

		while (thisNumber >= insertedNumber)
		{
			s.push(insertedNumber++);
			resultStr += '+';
		}

		s.pop();
		resultStr += '-';

		if (!s.empty() && s.top() > sequence[i + 1])
		{
			cout << "NO";
			return 0;
		}
	}

	for (auto& c : resultStr)
	{
		cout << c << "\n";
	}

	return 0;
}