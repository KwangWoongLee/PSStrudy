#include <map>
#include <iostream>

using namespace std;

int main()
{
	string str;
	cin >> str;
	int alphabet[26] = { 0, };

	for (auto& c : str)
		++alphabet[c - 97];

	for (int i=0; i<25; ++i)
	{
		cout << alphabet[i] << " ";
	}
	cout << alphabet[25];
}