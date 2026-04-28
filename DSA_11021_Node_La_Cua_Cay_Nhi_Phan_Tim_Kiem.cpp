#include<bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    Node *left, *right;
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

void tim_kiem_nut_la(Node* root)
{
    if(!root) return;

    queue<Node*> q;
    q.push(root);
    vector<int> la;

    while(!q.empty())
    {
        Node* tmp = q.front();
        q.pop();

        if(!tmp->left && !tmp->right)
        {
            la.push_back(tmp->key);
        }
        if(tmp->left) q.push(tmp->left);
        if(tmp->right) q.push(tmp->right);
    }

    sort(la.begin(), la.end());

    for(int i = 0; i< la.size(); i++)
    {
        if(i>0) cout << ' ';
        cout << la[i];
    }
}

int main()
{
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        Node* root = NULL;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            root = insert(root, x); 
        }
        
        tim_kiem_nut_la(root);
        cout << '\n';
    }
    return 0;
}