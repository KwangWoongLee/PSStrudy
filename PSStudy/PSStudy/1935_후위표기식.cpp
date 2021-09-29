#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;
 
double Calculate(double a, double b, char oper)
{
	switch (oper)
	{
	case '+':
	{
		return a + b;
		break;
	}
	case '-':
	{
		return a - b;
		break;
	}
	case '*':
	{
		return a * b;
		break;
	}
	case '/':
	{
		return a / b;
		break;
	}
	default:
		break;
	}
}

int main()
{
	cout << fixed;
	cout.precision(2);


	int N;
	cin >> N;

	string str;
	cin >> str;

	string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	unordered_map<char, int> charMap;

	for (int i = 0; i < N; ++i)
	{
		int tmp;
		cin >> tmp;

		charMap[alphabet[i]] = tmp;
	}

	stack<double> s;
	
	for (auto& c : str)
	{
		if (charMap.find(c) != charMap.end()) // A , B , C, D, E
		{
			s.push(charMap[c]);
		}
		else // operator + - * /
		{
			double a, b;
			b= s.top();
			s.pop();
			a = s.top();
			s.pop();
		
			s.push(Calculate(a, b, c));
		}
		
	}

	cout << s.top();
	return 0;
}
