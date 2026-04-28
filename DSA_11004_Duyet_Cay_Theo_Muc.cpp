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

Node* Search(Node* T, int x)
{
	Node* p;
	if(T == NULL)
		return NULL;
	if(T->key==x)
	{
		return T;
	}
	p = Search(T->left,x);
	if(p == NULL)
		p = Search(T->right, x);
	return p;
}

void AddLeft(Node* T, int x, int y)
{
	Node* p,* q;
	p = Search(T,x);
	if(p == NULL)
	{
		return;
	}
	else if((p->left)!= NULL)
		return;
	else
	{
		q = new Node(y);
		p->left = q;
	}
}

void AddRight(Node* T, int x, int y)
{
	Node* p,* q;
	p = Search(T,x);
	if(p == NULL)
	{
		return;
	}
	else if((p->right)!= NULL)
		return;
	else{
		q = new Node(y);
		p->right = q;
	}
}

void levelOrder(Node* root) {
    if (root == NULL) return;
    queue<Node*> q;
    q.push(root);
    bool first = true;
    while (!q.empty()) {
        Node* tmp = q.front(); q.pop();
        if (!first) cout << " ";
        cout << tmp->key;
        first = false;
        if (tmp->left)  q.push(tmp->left);
        if (tmp->right) q.push(tmp->right);
    }
    cout << "\n";
}

int main()
{
	int t;
	cin >>t;
	while(t--)
	{
		Node* root = NULL;
		int m;
		cin >> m;
		while(m--)
		{
			int x, y;
			char c;
			cin >> x >> y >> c;
			if(root == NULL)
			{
				root = new Node(x);
			}
			if(c == 'L')
			{
				AddLeft(root,x,y);
			}
			else
				AddRight(root,x,y);
		}
        levelOrder(root);
		cout << "\n";
	}
	return 0;
}

