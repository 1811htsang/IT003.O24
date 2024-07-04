
#include <iostream>
#include <limits>
using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }
    
};




// Complete the insertSortedLinkedList function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

void insert_node(SinglyLinkedList* ls, int node_data) {
    SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

    if (!ls->head) {
        ls->head = node;
    } else {
        ls->tail->next = node;
    }

    ls->tail = node;
}

void printLinkedList(SinglyLinkedList* ls) {
    while (ls->head != NULL){
        cout<< ls->head->data << ' ';
        ls->head = ls->head->next;
    }
}

void reverseLinkedList(SinglyLinkedList* ls) {
    if (ls->head == NULL || ls->head->next == NULL) {
        return;
    } else {
        SinglyLinkedListNode* currentNode = ls->head;
        SinglyLinkedListNode* previousNode = NULL;
        SinglyLinkedListNode* nextNode = NULL;
        while (currentNode != NULL) {
            nextNode = currentNode->next;
            currentNode->next = previousNode;
            if (nextNode == NULL) break;
            previousNode = currentNode;
            currentNode = nextNode;
        }
        ls->head = currentNode;        
    }
}

int main()
{
    SinglyLinkedList* llist = new SinglyLinkedList();
    int llist_count;


    cin >> llist_count;

    for (int i = 0; i < llist_count; i++) {
        int llist_item;
        cin >> llist_item;

        insert_node(llist,llist_item);
    }
    
    
    reverseLinkedList(llist);
    printLinkedList(llist);

    return 0;
}
