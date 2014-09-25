#include <iostream>

using namespace std;

struct BiNode
{
	int value;
	BiNode *ptr1, *ptr2;
	BiNode(int v): value(v){}
};

void convert(BiNode *root, BiNode* &head, BiNode * &tail)
{
	if(root == NULL)
	{
		head = tail = NULL;
		return;
	}
	BiNode *lefthead, *lefttail;
	BiNode *righthead, *righttail;

	convert(root->ptr1, lefthead, lefttail);
	convert(root->ptr2, righthead, righttail);

	if(lefthead != NULL)
	{
		head = lefthead;
		lefttail->ptr2 = root;
		root->ptr1 = lefttail;
	}
	else
		head = root;

	if(righthead != NULL)
	{
		tail = righttail;
		righthead->ptr1 = root;
		root->ptr2 = righthead;
	}
	else
		tail = root;
}

BiNode *convertBST2DList(BiNode *root)
{
	BiNode *head, *tail;
	convert(root, head, tail);
	return tail;
}

int main()
{
	BiNode *root = NULL; //new BiNode(4);
	/*
	root->ptr1 = new BiNode(2);
	root->ptr1->ptr1 = new BiNode(1);
	root->ptr1->ptr2 = new BiNode(3);
	root->ptr1->ptr1->ptr1 = new BiNode(0);

	root->ptr2 = new BiNode(5);
	root->ptr2->ptr2 = new BiNode(6);
	*/
	BiNode* tail = convertBST2DList(root);

	while(tail != NULL)
	{
		cout << tail->value << endl;
		tail = tail->ptr1;
	}
	return 0;
}
