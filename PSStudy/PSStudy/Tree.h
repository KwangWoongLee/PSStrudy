#pragma once
#include <iostream>
#include <queue>


template <typename T>
class Node {
public:
	Node(T data);
	~Node();

	T	mData;
	Node<T>* mLeftChild;
	Node<T>* mRightChild;
	Node<T>* mParent;
	int mDepth;
};


template<typename T>
inline Node<T>::Node(T data)
{	
	mData = data;
	mLeftChild = nullptr;
	mRightChild = nullptr;
	mParent = nullptr;
}

template<typename T>
inline Node<T>::~Node()
{
	if (mLeftChild != nullptr)
		delete mLeftChild;

	if (mRightChild != nullptr)
		delete mRightChild;
}


template <typename T>
class Tree
{
public:
	Tree(T data);
	~Tree();

	Node<T>* GetRoot() { return mRoot; }

	void PushLeftChild(Node<T>* parentNode, T& data);
	void PushRightChild(Node<T>* parentNode, T& data);

	T PopLeftChild(Node<T>* parentNode);
	T PopRightChild(Node<T>* parentNode);

	Node<T>* FindNodeToValue(T& key);

	void PrintPreOrder(Node<T>* node);
	void PrintInOrder(Node<T>* node);
	void PrintPostOrder(Node<T>* node);

	void InOrderToMakeLocation(Node<T>* node, std::vector<Node<T>*>& location);

private:
	Node<T>*	mRoot;
	
};

template<typename T>
inline Tree<T>::Tree(T data)
{
	mRoot = new Node<T>(data);
	mRoot->mDepth = 1;
}

template<typename T>
inline Tree<T>::~Tree()
{
	delete mRoot;
}

template<typename T>
inline void Tree<T>::PushLeftChild(Node<T>* parentNode ,T& data)
{
	auto newNode = new Node<T>(data);
	parentNode->mLeftChild = newNode;
	newNode->mParent = parentNode;

	newNode->mDepth = parentNode->mDepth + 1;

	//검증 코드는 따로 작성X
}

template<typename T>
inline void Tree<T>::PushRightChild(Node<T>* parentNode, T& data)
{
	auto newNode = new Node<T>(data);
	parentNode->mRightChild = newNode;
	newNode->mParent = parentNode;

	newNode->mDepth = parentNode->mDepth + 1;

	//검증 코드는 따로 작성X

}

template<typename T>
inline T Tree<T>::PopLeftChild(Node<T>* parentNode)
{
	auto data = parentNode->mLeftChild->mData;

	delete parentNode->mLeftChild;

	return data;
}

template<typename T>
inline T Tree<T>::PopRightChild(Node<T>* parentNode)
{
	auto data = parentNode->mRightChild->mData;

	delete parentNode->mRightChild;

	return data;
}

template<typename T>
inline Node<T>* Tree<T>::FindNodeToValue(T& key)
{
	std::queue<Node<T>*> q;
	q.push(mRoot);

	while (!q.empty())
	{
		auto tmp = q.front();
		q.pop();
		
		if (tmp->mData == key)
			return tmp;

		if (tmp->mLeftChild != nullptr)
			q.push(tmp->mLeftChild);

		if (tmp->mRightChild != nullptr)
			q.push(tmp->mRightChild);

	}

	return nullptr;
}

template<typename T>
inline void Tree<T>::PrintPreOrder(Node<T>* node)
{
	if (node == nullptr)
		return;

	std::cout << node->mData;
	PrintPreOrder(node->mLeftChild);
	PrintPreOrder(node->mRightChild);
}

template<typename T>
inline void Tree<T>::PrintInOrder(Node<T>* node)
{
	if (node == nullptr)
		return;

	PrintInOrder(node->mLeftChild);
	std::cout << node->mData;
	PrintInOrder(node->mRightChild);
}

template<typename T>
inline void Tree<T>::PrintPostOrder(Node<T>* node)
{
	if (node == nullptr)
		return;

	PrintPostOrder(node->mLeftChild);
	PrintPostOrder(node->mRightChild);
	std::cout << node->mData;
}

template<typename T>
inline void Tree<T>::InOrderToMakeLocation(Node<T>* node, std::vector<Node<T>*>& location)
{
	if (node == nullptr)
		return;

	InOrderToMakeLocation(node->mLeftChild, location);
	location.push_back(node);
	InOrderToMakeLocation(node->mRightChild, location);
}
