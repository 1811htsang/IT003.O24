
#include <bits/stdc++.h>
using namespace std;

	
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  	
  	void preOrder(Node *root) {
		
      	if( root == NULL )
          	return;
      
      	std::cout << root->data << " ";
      	
      	preOrder(root->left);
      	preOrder(root->right);
	}

/* you only have to complete the function given below.  
Node is defined as  

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/

    Node * insert(Node * root, int data) {
        //Not using recursion
        Node *newNode = new Node(data);
        if(root == NULL) {
            root = newNode;
            return root;
        }
        Node *temp = root;
        while(true) {
            if(data < temp->data) {
                if(temp->left == NULL) {
                    temp->left = newNode;
                    break;
                }
                else {
                    temp = temp->left;
                }
            }
            else {
                if(temp->right == NULL) {
                    temp->right = newNode;
                    break;
                }
                else {
                    temp = temp->right;
                }
            }
        }
    }
}; 

int main() {
    
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
    myTree.preOrder(root);

    return 0;
}