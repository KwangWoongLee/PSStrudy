#include <iostream>

#include "Tree.h"

using namespace std;

int main() {
	
	Tree<char> t('A');

	int N;
	cin >> N;

	char node, left, right;

	for (int i = 0; i < N; ++i)
	{
		cin >> node >> left >> right;
		
		auto parent = t.FindNodeToValue(t.GetRoot(), node);
		
		if (left != '.')
			t.PushLeftChild(parent, left);

		if (right != '.')
			t.PushRightChild(parent, right);

	}
	

	return 0;
}
