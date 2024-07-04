#include <bits/stdc++.h>
using namespace std;

struct item {
    int val;
    item* next;
};

struct llstack {
    item* top;
};

void createStack(llstack &st) {
    st.top = nullptr;
}

item* createItem(int x) {
    item* temp = new item;
    temp->val = x;
    temp->next = nullptr;
    return temp;
}

void __push(llstack &st, int x) {
    item* addItem = createItem(x);
    if (st.top == nullptr) {
        st.top = addItem;
    } else {
        addItem->next = st.top;
        st.top = addItem;
    }
}

void __pop(llstack &st) {
    if (st.top == nullptr) {
        return;
    } else {
        item* deleteItem = st.top;
        st.top = st.top->next;
        deleteItem->next = nullptr;
        delete deleteItem;
    }
}

bool __empty(llstack &st) {
    if (st.top == nullptr) {
        return true;
    } else {
        return false;
    }
}

item* __top(llstack &st) {
    return st.top;
}

int __size(llstack st) {
    item* cur = st.top;
    int count = 0;
    while (cur != nullptr) {
        count++;
        cur = cur->next;
    }
    return count;
}

void printStack(llstack &st) {
    while (__empty(st) == false) {
        cout << st.top->val << " <- ";
        __pop(st);
        if (st.top == nullptr) cout << "End Stack\n";
    }
}

int main() {
    llstack st;
    createStack(st);
    __push(st, 1);
    __push(st, 2);
    __push(st, 3);
    __push(st, 4);
    __push(st, 5);
    cout << __size(st) << endl;
    printStack(st);
}