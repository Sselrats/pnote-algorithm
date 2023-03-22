#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;
 
int n, shifted[50001];
int A[50001];
 
typedef int KeyType;
 
 
struct Node
{
    KeyType key;
 
    int priority, size;
 
    Node *left, *right;
 
    Node(const KeyType& _key) : key(_key), priority(rand()),
        size(1), left(NULL), right(NULL) {}
    void setLeft(Node* newLeft) { left = newLeft; calcSize(); }
    void setRight(Node* newRight) { right = newRight; calcSize(); }
    void calcSize()
    {
        size = 1;
        if (left) size += left->size;
        if (right) size += right->size;
    }
};
 
Node* kth(Node* root, int k)
{
    int ls = (root->left ? root->left->size : 0);
    int rs = (root->right ? root->right->size : 0);
    if (k <= ls) return kth(root->left, k);
    if (k == ls + 1) return root;
    return kth(root->right, k - ls - 1);
}
 
typedef pair<Node*, Node*> NodePair;
 
 
NodePair split(Node* root, KeyType key)
{
    if (root == NULL) return NodePair(NULL, NULL);
 
    if (root->key < key)
    {
        NodePair rs = split(root->right, key);
        root->setRight(rs.first);
        return NodePair(root, rs.second);
    }
 
    NodePair ls = split(root->left, key);
    root->setLeft(ls.second);
    return NodePair(ls.first, root);
}
 
Node* insert(Node* root, Node* node)
{
    if (root == NULL) return node;
    if (root->priority < node->priority)
    {
        NodePair splitted = split(root, node->key);
        node->setLeft(splitted.first);
        node->setRight(splitted.second);
        return node;
    }
    else if (node->key < root->key)
        root->setLeft(insert(root->left, node));
    else
        root->setRight(insert(root->right, node));
    return root;
}
 
Node* merge(Node* a, Node* b)
{
    if (a == NULL) return b;
    if (b == NULL) return a;
 
    if (a->priority < b->priority)
    {
        b->setLeft(merge(a, b->left));
        return b;
    }
    a->setRight(merge(a->right, b));
    return a;
}
 
Node* erase(Node* root, KeyType key)
{
    if (root == NULL) return root;
    if (root->key == key)
    {
        Node* ret = merge(root->left, root->right);
        delete root;
        return ret;
    }
    if (key < root->key)
        root->setLeft(erase(root->left, key));
    else
        root->setRight(erase(root->right, key));
    return root;
}

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> shifted[i];
    Node* nodes = NULL;
    for (int i = 0; i < n; i++)
        nodes = insert(nodes, new Node(i + 1));
    for (int i = n - 1; i >= 0; --i)
    {
        int larger = shifted[i];
        Node*k = kth(nodes, i + 1 - larger);
        A[i] = k->key;
        nodes = erase(nodes, k->key);
    }
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << "\n";
}
 
int main(void)
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int C;
    cin >> C;
    while (C--)
    {
        solve();
    }
}