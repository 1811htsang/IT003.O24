#include <bits/stdc++.h>
using namespace std;

struct node {
    int val;
    node* next;
};

struct llist {
    node* head;
};

void createList(llist &ls) {
    ls.head = nullptr;
}

node* createNode(int x) {
    node* temp = new node;
    temp->val = x;
    temp->next = nullptr;
    return temp;
}

void addNodeAtLast(llist &ls, int x) {
    node* adnode = createNode(x);
    if (ls.head == nullptr) {
        ls.head = adnode;
    } else {
        node* temp = ls.head;
        while (temp->next != nullptr) temp = temp->next;
        temp->next = adnode;
    }
}

void addNodeAtFirst(llist &ls, int x) {
    node* adnode = createNode(x);
    if (ls.head == nullptr) {
        ls.head = adnode;
    } else {
        adnode->next = ls.head;
        ls.head = adnode;
    }
}

void addNodeAtPos(llist &ls, int x, int pos) {
    node* adnode = createNode(x);
    if (ls.head == nullptr) return;
    else {
        if (pos == 0) {
            adnode->next = ls.head;
            ls.head = adnode;
        } else {
            node* temp = ls.head;
            while (temp->next != nullptr) {
                if (pos == 1) break;
                pos--;
                temp = temp->next;
            }
            if (pos == 1) {
                adnode->next = temp->next;
                temp->next = adnode;
            }
        }
    }
}

void deleteNodeAtFirst(llist &ls) {
    node* temp = ls.head;
    ls.head = ls.head->next;
    temp->next = nullptr;
    delete temp;
}

void deleteNodeAtLast(llist &ls) {
    node* temp = ls.head;
    while (temp->next->next != nullptr) temp = temp->next;
    node* deleteNode = temp->next;
    temp->next = nullptr;
    delete deleteNode;
}

node* findmid(node* root) {
    if (root == nullptr) return nullptr;
    node* slow = root;
    node* fast = root->next;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

node* merge(node* l1, node* l2) {
    if (!l1) return l2;
    if (!l2) return l1;

    if(l1->val <= l2->val) {
        l1->next = merge(l1->next, l2);
        return l1;
    } else {
        l2->next = merge(l1, l2->next);
        return l2;
    }
}

void mergell(node* &root) {
    if (root == nullptr || root->next == nullptr) return;

    node* mid = findmid(root);
    node* next_mid = mid->next;

    mid->next = nullptr;

    mergell(root);
    mergell(next_mid);

    root = merge(root, next_mid);
}

void printList(llist ls) {
    node* temp = ls.head;
    while (temp != nullptr) {
        cout << temp->val << " -> ";
        temp = temp->next;
        if (temp == nullptr) cout << "NULL\n";
    }
}

int main() {
    llist ls;
    createList(ls);
    addNodeAtLast(ls,4);
    addNodeAtLast(ls,2);
    addNodeAtLast(ls,3);
    addNodeAtLast(ls,1);
    addNodeAtLast(ls,15);
    addNodeAtLast(ls,0);
    mergell(ls.head);
    printList(ls);
}