#include<bits/stdc++.h>
using namespace std;

struct Node{
	int key;
	Node *left;
	Node *right;
	Node(int item)
	{
		key = item;
		left = NULL;
		right = NULL;
	}
};

Node *insert(Node* node, int x)
{
    if(node == NULL)
        return new Node(x);
    if(node->key == x)
        return node;
    
    if(node->key < x)
        node->right = insert(node->right, x);
    else
        node->left = insert(node->left, x);
    return node;
}
