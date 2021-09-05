#include <iostream>


using namespace std;

class Stack
{
public:
	struct Node
	{
		Node* next;
		int data;
	};

	Stack()
		: mHead(nullptr)
		, mTop(nullptr)
		, mSize(0)
	{}

	~Stack()
	{
		if (!IsEmpty())
		{
			Node* now = mHead;
			Node* next = mHead->next;

			while (next != nullptr)
			{
				delete now;
				now = next;
				next = next->next;
			}

			delete now;
		}

	}

	int IsEmpty()
	{
		if (mHead == nullptr)
			return 1;
		
		return 0;
	}

	void Push(int value)
	{
		auto newNode = new Node;
		newNode->data = value;
		newNode->next = nullptr;

		if (IsEmpty())
		{
			mHead = newNode;
			mTop = newNode;
		}

		else
		{
			mTop->next = newNode;
			mTop = newNode;
		}



		++mSize;
	}

	int Pop()
	{
		if (IsEmpty())
		{
			return -1;
		}	

		int returnValue = mTop->data;
		Node* prevTop = mHead;
		
		if (GetSize() == 1)
		{
			delete prevTop;
			mHead = nullptr;
			mTop = nullptr;
		}

		else
		{
			while (prevTop->next != mTop)
			{
				prevTop = prevTop->next;
			}

			delete mTop;

			mTop = prevTop;
			mTop->next = nullptr;
		}

		--mSize;

		return returnValue;
	}

	int Top()
	{
		if (IsEmpty())
			return -1;

		return mTop->data;
	}

	int GetSize()
	{
		return mSize;
	}

private:
	Node* mTop;
	Node* mHead;
	int mSize;

};

int main()
{
	int N;
	cin >> N;
	string cmd;
	Stack s;



	for (int i = 0; i < N; ++i)
	{
		cin >> cmd;

		if (cmd == "push")
		{
			int cmdValue;
			cin >> cmdValue;

			s.Push(cmdValue);
		}

		else if (cmd == "pop")
		{
			cout << s.Pop() << endl;
		}

		else if (cmd == "size")
		{
			cout << s.GetSize() << endl;
		}

		else if (cmd == "empty")
		{
			cout << s.IsEmpty() << endl;
		}

		else if (cmd == "top")
		{
			cout << s.Top() << endl;
		}



	}

	return 0;
}
