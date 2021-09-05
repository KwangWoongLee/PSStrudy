#include <iostream>
#include <string>
#include<sstream>>
#include <stack>
using namespace std;

int main()
{
	int N;
	cin >> N;
	cin.ignore();

	for (int i = 0; i < N; ++i)
	{

		stack<char> s;
		string resultString;

		string sentence;
		getline(cin, sentence);

		istringstream ss(sentence);
		string word;
		while (getline(ss, word, ' '))
		{
			for (int i = 0; i < word.size(); ++i)
			{
				s.push(word[i]);
			}

			for (int i = 0; i < word.size(); ++i)
			{
				resultString += s.top();
				s.pop();
			}

			resultString += ' ';
		}

		cout << resultString << endl;
	} 

	return 0;
}	