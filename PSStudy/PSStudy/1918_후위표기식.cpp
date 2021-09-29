#include <stack>
#include <iostream>

using namespace std;

bool IsOper(char c)
{
	if (c == '*'
		|| c == '/'
		|| c == '+'
		|| c == '-')
		return true;
	
	return false;
}



int main()
{
	string str;
	cin >> str;

	string resultStr = "";
	stack<char> s;

	for (auto& c : str)
	{
		if (!IsOper(c) && c != ')' && c != '(') // 알파벳인 경우
		{
			resultStr += c;
		}
		else
		{
			if (IsOper(c)) // 연산자 또는 (인 경우
			{
				if (c == '*' || c == '/')
				{
					while (!s.empty() && (s.top() == '*' || s.top() == '/'))
					{

						resultStr += s.top();
						s.pop();
					}
				}
				else if (c == '+' || c == '-')
				{
					while (!s.empty() && s.top() != '(')
					{
						resultStr += s.top();
						s.pop();
					}	
				}

				s.push(c);
			}
			else if (c == '(') // ( 인 경우
			{
				s.push(c);
			}

			else // ) 인 경우
			{
				while (!s.empty() && s.top() != '(')
				{
					resultStr += s.top();
					s.pop();
				}
				s.pop(); // (까지 빼줌
			}
		}
	}

	while (!s.empty())
	{
		resultStr += s.top();
		s.pop();
	}

	cout << resultStr;

	return 0;
}