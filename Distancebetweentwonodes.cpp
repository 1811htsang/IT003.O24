
#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node *left;
    Node *right;
};

Node *newNode(int v)
{
    Node *newNode = new Node;
    newNode->value = v;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insertNode(Node *root, Node *newNode)
{
    if (!root)
        return;

    if (newNode->value < root->value)
    {
        if (!root->left)
        {
            root->left = newNode;
            return;
        }
        insertNode(root->left, newNode);
        return;
    }

    if (!root->right)
    {
        root->right = newNode;
        return;
    }
    insertNode(root->right, newNode);
}

bool isFind(Node* root, Node* find) {
    if (root->value == find->value) return true;
    else return false;
}

int distanceBetweenNodes(Node* root, int a, int b) {
    if (root != NULL) {
        
    }
}

int main()
{
    Node *tree = NULL;

    int n;
    cin >> n;

    for (auto i = 0; i < n; i++)
    {
        int val;
        cin >> val;

        if (!tree)
        {
            tree = newNode(val);
            continue;
        }

        insertNode(tree, newNode(val));
    }

    int a, b;
    cin >> a >> b;

    cout << distanceBetweenNodes(tree, a, b) << endl;

    return 0;
}
