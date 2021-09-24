#pragma once
#include <iostream>

template <typename T>
class Node {
public:
	Node(T data);
	~Node();

	T	mData;
	Node<T>* mLeftChild;
	Node<T>* mRightChild;
};


template<typename T>
inline Node<T>::Node(T data)
{	
	mData = data;
	mLeftChild = nullptr;
	mRightChild = nullptr;
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

	Node<T>* FindNodeToValue(Node<T>* node, T& key);

	void PrintPreOrder(Node<T>* node);
	void PrintInOrder(Node<T>* node);
	void PrintPostOrder(Node<T>* node);

private:
	Node<T>*	mRoot;
	
};

template<typename T>
inline Tree<T>::Tree(T data)
{
	mRoot = new Node<T>(data);
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

	//검증 코드는 따로 작성X
}

template<typename T>
inline void Tree<T>::PushRightChild(Node<T>* parentNode, T& data)
{
	auto newNode = new Node<T>(data);
	parentNode->mRightChild = newNode;

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
inline Node<T>* Tree<T>::FindNodeToValue(Node<T>* node, T& key)
{
	if (node == nullptr)
		return nullptr;

	if (node->mData == key)
		return node;

	FindNodeToValue(node->mLeftChild, key);
	FindNodeToValue(node->mRightChild, key);
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
}

template<typename T>
inline void Tree<T>::PrintPostOrder(Node<T>* node)
{
}
