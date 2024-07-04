/*---------------------------------------------------------------------------------------------------------------
    -Instruction to upload code to Github
        git init => git add -A => git commit -m => git push (-f) origin main
    -Instruction to commit code to Github
        feat: Add new feature
        fix: Fix bug
        refactor: Refactor code
        style: Style code
        test: Test code
        perf: Improve performance
        docs: Add documents
        chore: Add chore
        build: Change build process
        ci: Change CI process
        revert: Revert code
        note: Add or update notes
---------------------------------------------------------------------------------------------------------------*/
//Library space: Identify library 
#include <bits/stdc++.h> //Main library 
using namespace std; //Namespace
/*---------------------------------------------------------------------------------------------------------------*/
//Definiton space: Identify definiton 
#define num_MAX 300
#define MAXN 10000
typedef int* contro_int;
typedef int& thamchieu_int;
/*---------------------------------------------------------------------------------------------------------------*/
//Minor workspace 1: Identify template 
template <typename T> T* multiple_target_dynamic_allo(int num) {
    return new T[num];
}
template <typename T> T* single_targe_dynamic_allo() {
    return new T;
}
template <typename T> void erase_multiple_target_dynamic_allo(T* ptr) {
    delete[] ptr;
    ptr = nullptr;
}
template <typename T> void erase_single_target_dynamic_allo(T* ptr) {
    delete ptr;
    ptr = nullptr;
}
/*---------------------------------------------------------------------------------------------------------------*/
//Minor workspace 2: Identify struct, class
struct node {
    int data;
    node* next;
};
struct sslist {
    node* head;
    node* tail;
};
struct hashtable {
    int m;
    int n;
    float load;
    sslist *key_list;
};
int hash_func(hashtable hs, int x) {
    return x % hs.m;
}
void createlist(sslist& ls) {
    ls.head = ls.tail = NULL;
}
node* createnode(int x) {
    node *p = new node;
    if (p == NULL)
        exit(1);
    p->next = NULL;
    p->data = x;
    return p;
}
void createhashtable(hashtable &ht, int m) {
    ht.key_list = new sslist[m];
    for (int i = 0; i < m; i++)
        createlist(ht.key_list[i]);
    ht.m = m;
    ht.n = 0;
}

void AddTail(sslist &ls, int x) {
    node *p = createnode(x);
    if (ls.head == NULL)
        ls.head = ls.tail = p;
    else {
        ls.tail->next = p;
        ls.tail = p;
    }
}
int Insert(hashtable &hs, int x) {
    if (hs.n + 1 <= hs.m * hs.load) {
        int temp = hash_func(hs, temp);
        AddTail(hs.key_list[temp], x);
        hs.n++;
    }
}
/*---------------------------------------------------------------------------------------------------------------*/
//Minor workspace 3: Identify lower functions

/*---------------------------------------------------------------------------------------------------------------*/
//Minor workspace 4: Identify global variables

/*---------------------------------------------------------------------------------------------------------------*/
//Main workspace: Identify main function
int main() {
    //utilize cin|cout
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    /*---------------------------------------------------------------------------------------------------------------*/
    //Major workspace: Identify variables, Execute functions

    /*---------------------------------------------------------------------------------------------------------------*/
    return 0;
}
/*---------------------------------------------------------------------------------------------------------------*/
//Minor workspace 5: Identify functions usage
