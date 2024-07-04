#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
};


node* createNode(int value) {
    node* node_block = new node;
    node_block->data = value;
    node_block->left = node_block->right = NULL;
    return node_block;
}

void addNode(node* &root, int value) {
    node* node_block = createNode(value);
    if (root == NULL) {
        root = node_block;
    } else {
        node* temp = root;
        node* parent_current_node = NULL;
        while (temp) {
            parent_current_node = temp;
            if (temp->data <= node_block->data) 
                temp = temp->right;
            else 
                temp = temp->left;
        }

        if (parent_current_node->data <= node_block->data) 
                parent_current_node->right = node_block;
            else 
                parent_current_node->left = node_block;
    }
}

void printNodeNLR(node* root) {
    if (root != NULL) {
        cout << root->data << " ";
        printNodeNLR(root->left);
        printNodeNLR(root->right);
    }
}

void printNodeLNR(node* root) {
    if (root != NULL) {
        printNodeNLR(root->left);
        printNodeNLR(root->right);
        cout << root->data << " ";
    }
}
void countNodesAtLevelDFS(node* root, int level, int& count, int currentLevel = 0) {
    if (root == NULL) return;

    if (currentLevel == level) {
        count++;
        return;
    }

    countNodesAtLevelDFS(root->left, level, count, currentLevel + 1);
    countNodesAtLevelDFS(root->right, level, count, currentLevel + 1);
}

int countNodesAtLevel(node* root, int level) {
    int count = 0;
    countNodesAtLevelDFS(root, level, count);
    return count;
}

int main() {
    node* root = NULL;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        addNode(root, temp);
    }
    int level; cin >> level;
    cout << countNodesAtLevel(root, level);
}