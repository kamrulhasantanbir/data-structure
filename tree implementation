//tree


#include<bits/stdc++.h>
using namespace std;

class tree
{
public:
    int val;
    tree *left;
    tree *right;

    tree(int v)
    {
        val = v;
        left = NULL;
        right = NULL;
    }
};

tree* input()
{
    tree *node;
    int i;
    cin >> i;
    if (i == -1)
    {
        node = NULL;
        return node;
    }

    node = new tree(i);
    queue<tree*> q;
    q.push(node);

    while (!q.empty())
    {
        tree *temp = q.front();
        q.pop();

        int a, b;
        cin >> a >> b;

        tree *l = NULL;
        tree *r = NULL;

        if (a != -1)
        {
            l = new tree(a);
        }
        if (b != -1)
        {
            r = new tree(b);
        }

        temp->left = l;
        temp->right = r;

        if (l)
        {
            q.push(l);
        }
        if (r)
        {
            q.push(r);
        }
    }

    return node;
}

void preorder(tree *node)
{
    if (node == NULL)
    {
        return;
    }
    cout << node->val << " ";
    preorder(node->left);
    preorder(node->right);
}

void postorder(tree *node)
{
    if (node == NULL)
    {
        return;
    }
    postorder(node->left);
    postorder(node->right);
    cout << node->val << " ";
}

void inorder(tree *node)
{
    if (node == NULL)
    {
        return;
    }
    inorder(node->left);
    cout << node->val << " ";
    inorder(node->right);
}

void levelorder(tree *node)
{
    if (node == NULL)
    {
        return;
    }
    queue<tree*> q;
    q.push(node);
    while (!q.empty())
    {
        tree* temp = q.front();
        q.pop();
        cout << temp->val << " ";
        if (temp->left)
        {
            q.push(temp->left);
        }
        if (temp->right)
        {
            q.push(temp->right);
        }
    }
}

int leafCount(tree *node)
{
    if (node == NULL)
    {
        return 0;
    }
    if (node->left == NULL && node->right == NULL)
    {
        return 1;
    }
    int l = leafCount(node->left);
    int r = leafCount(node->right);
    return l + r;
}

int nodeCount(tree *node)
{
    if (node == NULL)
    {
        return 0;
    }
    int l = nodeCount(node->left);
    int r = nodeCount(node->right);
    return l + r + 1;
}

int maxHeight(tree *node)
{
    if (node == NULL)
    {
        return 0;
    }
    int l = maxHeight(node->left);
    int r = maxHeight(node->right);
    return max(l, r) + 1;
}

int main()
{
    tree *node = input();

    cout << "Preorder: ";
    preorder(node);
    cout << endl;

    cout << "Inorder: ";
    inorder(node);
    cout << endl;

    cout << "Postorder: ";
    postorder(node);
    cout << endl;

    cout << "Levelorder: ";
    levelorder(node);
    cout << endl;

    cout << "Total leafs: " << leafCount(node) << endl;
    cout << "Total nodes: " << nodeCount(node) << endl;
    cout << "Max height: " << maxHeight(node) << endl;

    return 0;
}
