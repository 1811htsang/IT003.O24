#include <bits/stdc++.h>
using namespace std;

struct node {
    int val;
    node* next;

    node(int x) {
        val = x;
        next = nullptr;
    }
};

struct llist {
    node* head;
};

void createList(llist &ls) {
    ls.head = nullptr;
}

void addNode(llist &ls, int x)  {
    node* addnode = new node(x);
    if (ls.head == nullptr) {
        ls.head = addnode;
    } else {
        node* cur = ls.head;
        node* pre = nullptr;
        while (cur != nullptr) {
            pre = cur;
            cur = cur->next;
        }
        pre->next = addnode;
    }
}

void printList(node* head) {
    if (head == nullptr) {
        cout << "N";
    } else {
        node* temp = head;
        while (temp != nullptr) {
            cout << temp->val << " -> ";
            temp = temp->next;
            if (temp == nullptr) cout << "N";
        }
    }
}

struct hashtable {
    int size;
    int quantity;
    llist table[100];
};

void createHashTable(hashtable &ht, int x) {
    ht.size = x;
    ht.quantity = 0;
    for (int i = 0; i < x; i++) {
        createList(ht.table[i]);
    }
}

int hash_func(int size, int key) {
    return key % size;
}

void addKey(hashtable &ht, int key) {
    if (ht.quantity < ht.size) {
        addNode(ht.table[hash_func(ht.size, key)], key);
        ht.quantity++;
    }
}

void printHash(hashtable ht) {
    for (int i = 0; i < ht.size; i++) {
        cout << i << ": ";
        printList(ht.table[i].head);
        cout << endl;
    }
}

void shrinkHashTable(hashtable ht) {
    
}

int main() {
    int size, quantity;
    cout << "Kich thuoc bang bam: ";
    cin >> size;
    cout << "So luong phan tu: ";
    cin >> quantity;

    hashtable ht;
    createHashTable(ht, size);

    queue<int> qu;
    cout << "Tap khoa: ";
    for (int i = 1; i <= quantity; i++) {
        int key = i + rand() % 100;
        cout << key << " ";
        qu.push(key);
    }
    cout << endl;
    while (qu.empty() == false) {
        int top = qu.front();
        qu.pop();
        addKey(ht,top);
    }

    printHash(ht);
    
}