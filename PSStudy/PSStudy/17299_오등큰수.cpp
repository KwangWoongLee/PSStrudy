<<<<<<< HEAD
#include <unordered_map>
#include <stack>
#include <iostream>
#include <vector>
#include <algorithm>

=======
#include <map>
#include <iostream>
#include <vector>
>>>>>>> c1e390be1a390c0ed2b303fa701f3c3e83909262
using namespace std;

int main()
{
<<<<<<< HEAD
	stack<int> s;

	int N;
	cin >> N;

	vector<int> arr(N);
	vector<int> result(N);
	vector<int> map(N+1);

	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
		++map[arr[i]];
	}

	reverse(arr.begin(), arr.end());

	int idx = N - 1;

	for (auto& value : arr)
	{
		while (!s.empty() && map[value] >= map[s.top()])
			s.pop();

		if (s.empty())
			result[idx] = -1;
		else
		{
			result[idx] = s.top();
		}

		s.push(value);

		idx--;
	}

	for (int i = 0; i < N - 1; ++i)
	{
		cout << result[i] << " ";
	}
	cout << result[N - 1];
=======
	int N;
	cin >> N;
	vector<int> a(N);
	

	for (int i = 0; i < N; ++i)
		cin >> a[i];


>>>>>>> c1e390be1a390c0ed2b303fa701f3c3e83909262

	return 0;
}