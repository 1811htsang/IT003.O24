#include <bits/stdc++.h>
using namespace std;

struct node {
    int val;
    node* left;
    node* right;
    node(int x) {
        val = x;
        left = right = nullptr;
    }
};

struct tree {
    node* root;
};

void createTree(tree &tr) {
    tr.root = nullptr;
}

void addNode(tree &tr, int x) { //1
    node* addNode = new node(x);
    if (tr.root == nullptr)  {
        tr.root = addNode;
    } else {
        node* cur = tr.root;
        node* pre = nullptr;
        while (cur != nullptr) {
            pre = cur;
            if (cur->val > x) cur = cur->left;
            else if (cur->val < x) cur = cur->right;
            else break;
        }
        if (pre->val > x) {
            pre->left = addNode;
        } else if (pre->val < x) {
            pre->right = addNode;
        } else return;
    }
}

int return_Height_Recursion(node* root) { //2
    if (root == nullptr) return -1;

    int left = return_Height_Recursion(root->left);
    int right = return_Height_Recursion(root->right);
    return max(left, right) + 1;
}

int return_Height_LOT_Queue(node* root) { //3
    if (root == nullptr) return 0;

    queue<node*> qu;
    qu.push(root);
    int height = -1;

    while (1) {
        int nodeCountAtLevel = qu.size();
        if (nodeCountAtLevel == 0) return height;

        height++;

        while (nodeCountAtLevel > 0) {
            node* top = qu.front();
            qu.pop();

            if (top->left != nullptr) qu.push(top->left);
            if (top->right != nullptr) qu.push(top->right);

            nodeCountAtLevel--;
        }

    }
}

void printNLR_Recursion(node* root) { //4
    if (root != nullptr) {
        cout << root->val << " ";
        printNLR_Recursion(root->left);
        printNLR_Recursion(root->right);
    }
}

void printNLR_Stack(node* root) { //5
    if (root == nullptr) return;

    stack<node*> st;
    st.push(root);

    while (st.empty() == false) {
        node* top = st.top();
        cout << top->val << " ";
        st.pop();

        if (top->right != nullptr) st.push(top->right);
        if (top->left != nullptr) st.push(top->left);
    }

}

void printNRL_Recursion(node* root) { //6
    if (root != nullptr) {
        cout << root->val << " ";
        printNRL_Recursion(root->right);
        printNRL_Recursion(root->left);
    }
}

void printNRL_Stack(node* root) { //7
    if (root == nullptr) return;

    stack<node*> st;
    st.push(root);

    while (st.empty() == false) {
        node* top = st.top();
        cout << top->val << " ";
        st.pop();

        if (top->left != nullptr) st.push(top->left);
        if (top->right != nullptr) st.push(top->right);
    }

}

void printLNR_Recursion(node* root) { //8
    if (root != nullptr) {
        printLNR_Recursion(root->left);
        cout << root->val << " ";
        printLNR_Recursion(root->right);
    }
}

void printLNR_Stack(node* root) { //9
    stack< node* > st;
    node* cur = root;

    while (cur != nullptr || st.empty() == false) {
        while(cur != nullptr) {
            st.push(cur);
            cur = cur->left;
        }

        cur = st.top();
        st.pop();
        cout << cur->val << " ";

        cur = cur->right;
    }
}


void printRNL_Recursion(node* root) { //10
    if (root != nullptr) {
        printRNL_Recursion(root->right);
        cout << root->val << " ";
        printRNL_Recursion(root->left);
    }
}

void printRNL_Stack(node* root) { //11
    stack<node*> st;
    node* cur = root;

    while (cur != nullptr || st.empty() == false) {
        while (cur != nullptr) {
            st.push(cur);
            cur = cur->right;
        }

        cur = st.top();
        st.pop();
        cout << cur->val << " ";

        cur = cur->left;
    }

}

void printLRN_Recursion(node* root) { //12
    if (root != nullptr) {
        printLRN_Recursion(root->left);
        printLRN_Recursion(root->right);
        cout << root->val << " ";
    }
}

void printLRN_2Stack(node* root) { //13
    stack<node*> NRL_sequence_st, LRN_sequence_st;
    NRL_sequence_st.push(root);

    while (NRL_sequence_st.empty() == false) {
        node* top = NRL_sequence_st.top();
        NRL_sequence_st.pop();
        LRN_sequence_st.push(top);

        if (top->left != nullptr) NRL_sequence_st.push(top->left);
        if (top->right != nullptr) NRL_sequence_st.push(top->right);
    }

    while (LRN_sequence_st.empty() == false) {
        cout << LRN_sequence_st.top()->val << " ";
        LRN_sequence_st.pop();
    }
}

void printRLN_Recursion(node* root) { //14
    if (root != nullptr) {
        printRLN_Recursion(root->right);
        printRLN_Recursion(root->left);
        cout << root->val << " ";
    }
}

void printRLN_2Stack(node* root) { //15
    stack<node*> NLR_sequence_st, RLN_sequence_st;
    NLR_sequence_st.push(root);

    while(NLR_sequence_st.empty() == false) {
        node* top = NLR_sequence_st.top();
        NLR_sequence_st.pop();
        RLN_sequence_st.push(top);

        if (top->right != nullptr) NLR_sequence_st.push(top->right);
        if (top->left != nullptr) NLR_sequence_st.push(top->left);
    }

    while (RLN_sequence_st.empty() == false) {
        cout << RLN_sequence_st.top()->val << " ";
        RLN_sequence_st.pop();
    }
}

void printLOT_Queue(node* root) { //16
    queue<node*> qu;
    qu.push(root);
    while (qu.empty() == false) {
        node* top = qu.front();
        qu.pop();
        cout << top->val << " ";

        if (top->left != nullptr) qu.push(top->left);
        if (top->right != nullptr) qu.push(top->right);
    }
}

void printLOT_Vector(node* root) { //17
    vector<node*> vec;
    vec.push_back(root);
    while (vec.empty() == false) {
        node* top = vec.front();
        vec.erase(vec.begin());
        cout << top->val << " ";

        if (top->left != nullptr) vec.push_back(top->left);
        if (top->right != nullptr) vec.push_back(top->right);
    }
}

void printLOT_2Stack(node* root) { //18
    stack<node*> currentLevel, nextLevel;
    currentLevel.push(root);

    while (currentLevel.empty() == false) {
        node* top = currentLevel.top();
        currentLevel.pop();
        cout << top->val << " ";

        if (top->left != nullptr) nextLevel.push(top->left);
        if (top->right != nullptr) nextLevel.push(top->right);

        if (currentLevel.empty() == true) {
            swap(currentLevel, nextLevel);
        }
    }
}

void deleteNode(node* &root, int x) {
    if (root == nullptr) return;
    else {
        node* cur = root;
        node*
    }
}

int main() {
    tree tr;
    createTree(tr);
    addNode(tr,8);
    addNode(tr,5);
    addNode(tr,1);
    addNode(tr,6);
    addNode(tr,15);
    addNode(tr,10);
    addNode(tr,20);
    addNode(tr,21);
    // cout << "Heigt of tree using recursion: " << return_Height_Recursion(tr.root);
    // cout << endl;
    // cout << "Heigt of tree using LOT Queue: " << return_Height_LOT_Queue(tr.root);
    // cout << endl;
    // cout << "NLR recursion: ";
    // printNLR_Recursion(tr.root);
    // cout << endl;
    // cout << "NLR using stack: ";
    // printNLR_Stack(tr.root);
    // cout << endl;
    // cout << "NRL recursion: ";
    // printNRL_Recursion(tr.root);
    // cout << endl;
    // cout << "NRL using stack: ";
    // printNRL_Stack(tr.root);
    // cout << endl;
    cout << "LNR recursion: ";
    printLNR_Recursion(tr.root);
    deleteNode(tr.root, 15  );
    cout << endl;
    cout << "LNR recursion: ";
    printLNR_Recursion(tr.root);
    // cout << endl;
    // cout << "LNR using stack: ";
    // printLNR_Stack(tr.root);
    // cout << endl;
    // cout << "RNL recursion: ";
    // printRNL_Recursion(tr.root);
    // cout << endl;
    // cout << "RNL using stack: ";
    // printRNL_Stack(tr.root);
    // cout << endl;
    // cout << "LRN recursion: ";
    // printLRN_Recursion(tr.root);
    // cout << endl;
    // cout << "LRN using 2 stack: ";
    // printLRN_2Stack(tr.root);
    // cout << endl;
    // cout << "RLN recursion: ";
    // printRLN_Recursion(tr.root);
    // cout << endl;
    // cout << "RLN using 2 stack: ";
    // printRLN_2Stack(tr.root);
    // cout << endl;
    // cout << "LOT using queue: ";
    // printLOT_Queue(tr.root);
    // cout << endl;
    // cout << "LOT using vector: ";
    // printLOT_Vector(tr.root);
    // cout << endl;
    // cout << "LOT using 2 stacks: ";
    // printLOT_2Stack(tr.root);

    // cout << return_Height_LOT_Queue(tr.root) << "\n";

    // printLRN_Recursion(tr.root);

    // printNLR_Stack(tr.root);

    // printNRL_Stack(tr.root);

    // printRNL_Recursion(tr.root);

    // printLNR_Recursion(tr.root);
}

/*---------------------------------------------------------------------------------------------------------------
Note:
cai dat ham so
Dapan:

Heigt of tree using recursion: 3
Heigt of tree using LOT Queue: 3
NLR recursion: 8 5 1 6 15 10 20 21
NLR using stack: 8 5 1 6 15 10 20 21
NRL recursion: 8 15 20 21 10 5 6 1
NRL using stack: 8 15 20 21 10 5 6 1
LNR recursion: 1 5 6 8 10 15 20 21
LNR using stack: 1 5 6 8 10 15 20 21
RNL recursion: 21 20 15 10 8 6 5 1
RNL using stack: 21 20 15 10 8 6 5 1
LRN recursion: 1 6 5 10 21 20 15 8
LRN using 2 stack: 1 6 5 10 21 20 15 8
RLN recursion: 21 20 10 15 6 1 5 8
RLN using 2 stack: 21 20 10 15 6 1 5 8
LOT using queue: 8 5 15 1 6 10 20 21
LOT using vector: 8 5 15 1 6 10 20 21
LOT using 2 stacks: 8 15 5 6 1 20 10 21

---------------------------------------------------------------------------------------------------------------*/

