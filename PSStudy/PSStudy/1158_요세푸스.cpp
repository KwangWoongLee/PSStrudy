#include <queue>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	string resultStr = "<";
	queue<int> q;

	int N , K;
	cin >> N >> K;


	for (int i = 1; i < N + 1; ++i)
		q.push(i);


	int idx = 1;

	while (q.size() > 1)
	{	
		int thisNumber = q.front();
		
		if (idx != K)
		{
			q.push(thisNumber);
		}
		else
		{
			idx = 0;
			resultStr += to_string(thisNumber) + ", ";
		}

		q.pop(); ;
		
		++idx;
	}


	resultStr += to_string(q.front()) + ">";

	cout << resultStr;



	return 0;
}