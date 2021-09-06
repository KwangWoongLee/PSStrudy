#include <string>
#include <iostream>

using namespace std;

template <typename T>
class Queue
{
public:
	struct Node
	{
		T data;
		Node* next;
	};

	Queue()
		: mHead(nullptr)
		, mRear(nullptr)
		, mSize(0)
	{};
	~Queue()
	{
		while (!IsEmpty())
		{
			Pop();
		}
	};

	int GetSize() { return mSize; }

	bool IsEmpty()
	{
		if (mSize == 0)
			return true;

		return false;
	}


	void Push(T data)
	{
		auto newNode = new Node;
		newNode->data = data;
		newNode->next = nullptr;

		if (IsEmpty())
		{
			mHead = newNode;
			mRear = newNode;
		}
		else
		{
			mRear->next = newNode;
			mRear = newNode;
		}

		++mSize;
	}

	T Pop()
	{
		if (IsEmpty())
		{
			return NULL;
		}

		T returnValue = mHead->data;

		if (GetSize() == 1)
		{
			delete mHead;
		}
		else
		{
			auto tmp = mHead->next;

			delete mHead;

			mHead = tmp;
		}



		--mSize;

		return returnValue;
	}

	T Front()
	{
		if (IsEmpty())
			return NULL;

		return mHead->data;
	}

	T Back()
	{
		if (IsEmpty())
			return NULL;

		return mRear->data;
	}

private:
	Node*	mHead;
	Node*	mRear;
	int		mSize;
};

int main()
{
	Queue<int> q;
	
	int N;
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		string cmd;
		int value;

		cin >> cmd;

		if (cmd == "push")
		{
			cin >> value;

			q.Push(value);

		}
		else if (cmd == "pop")
		{
			if (q.IsEmpty())
			{
				cout << -1 << endl;
				continue;
			}

			cout << q.Pop() << endl;

		}
		else if (cmd == "size")
		{
			cout << q.GetSize() << endl;
		}
		else if (cmd == "empty")
		{
			if (q.IsEmpty())
			{
				cout << 1 << endl;
				continue;
			}

			cout << 0 << endl;

		}
		else if (cmd == "front")
		{
			if (q.IsEmpty())
			{
				cout << -1 << endl;
				continue;
			}

			cout << q.Front() << endl;

		}
		else if (cmd == "back")
		{
			if (q.IsEmpty())
			{
				cout << -1 << endl;
				continue;
			}

			cout << q.Back() << endl;

		}


	}
}