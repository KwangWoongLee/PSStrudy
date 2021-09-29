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
		if (!IsOper(c) && c != ')' && c != '(') // ���ĺ��� ���
		{
			resultStr += c;
		}
		else
		{
			if (IsOper(c)) // ������ �Ǵ� (�� ���
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
			else if (c == '(') // ( �� ���
			{
				s.push(c);
			}

			else // ) �� ���
			{
				while (!s.empty() && s.top() != '(')
				{
					resultStr += s.top();
					s.pop();
				}
				s.pop(); // (���� ����
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