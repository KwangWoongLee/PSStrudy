#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int>	dp(1000001, 0);

	for (int i = 2; i < N + 1; ++i)
	{
		dp[i] = dp[i - 1] + 1;

		if (i % 2 == 0 && dp[i / 2] + 1 < dp[i])
			dp[i] = dp[i / 2] + 1;

		if (i % 3 == 0 && dp[i / 3] + 1 < dp[i])
			dp[i] = dp[i / 3] + 1;

	}

	cout << dp[N];


	return 0;
}