#include <bits/stdc++.h>
using namespace std;

struct item {
    int val;
    item* next;
};

struct llqueue {
    item* front;
    item* back;
};

void createQueue(llqueue &qu) {
    qu.front = qu.back = nullptr;
}

item* createItem(int x) {
    item* temp = new item;
    temp->val = x;
    temp->next = nullptr;
    return temp;
}

void __push(llqueue &qu, int x) {
    item* addItem = createItem(x);
    if (qu.front == nullptr && qu.back == nullptr) { // truong hop rong
        qu.front = qu.back = addItem;
    } else if (qu.front != nullptr && qu.back != nullptr && qu.front == qu.back) { //  truong hop 1 item
        qu.front->next = addItem;
        qu.back = qu.front;
    } else {
        qu.back->next = addItem;
        qu.back = qu.back->next;
    }
}

void __pop(llqueue &qu) {
    if (qu.front == nullptr && qu.back == nullptr) { // truong hop rong 
        return;
    } else if (qu.front != nullptr && qu.back != nullptr && qu.front == qu.back) { // truong hop 1 item
        qu.front = qu.back = nullptr;
    } else {
        item* deleteItem = qu.front;
        qu.front = qu.front->next;
        delete deleteItem;
    }
}

item* __front(llqueue qu) {
    return qu.front;
}

item* __back(llqueue qu) {
    return qu.back;
}

bool __empty(llqueue qu) {
    if (qu.front == qu.back && qu.front == nullptr) return true;
    return false;
}

int main() {

}