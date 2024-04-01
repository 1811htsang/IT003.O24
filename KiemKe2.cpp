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
struct good {
    string prod_id;
    int prod_quantity;
};
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
    long long int n; cin >> n;
    long long int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<good> vec;
    //import distinct elements with property string prod_id into vector vec but not import prod_quantity
    for (int i = 0; i < n; i++) {
        bool check = true;
        for (int j = 0; j < vec.size(); j++) {
            if (vec[j].prod_id == to_string(a[i])) {
                check = false;
                break;
            }
        }
        if (check) {
            good temp;
            temp.prod_id = to_string(a[i]);
            temp.prod_quantity = 0;
            vec.push_back(temp);
        }
    }
    //count quantity of each element in vector vec
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < vec.size(); j++) {
            if (vec[j].prod_id == to_string(a[i])) {
                vec[j].prod_quantity++;
                break;
            }
        }
    }
    //sort vector vec by prod_quantity in descending order, if prod_quantity is equal then sort by prod_id in ascending order, not using sort keyword
    for (int i = 0; i < vec.size() - 1; i++) {
        for (int j = i + 1; j < vec.size(); j++) {
            if (vec[i].prod_quantity < vec[j].prod_quantity) {
                swap(vec[i], vec[j]);
            }
            else if (vec[i].prod_quantity == vec[j].prod_quantity) {
                if (vec[i].prod_id >= vec[j].prod_id) {
                    swap(vec[i], vec[j]);
                }
            }
        }
    }
    //output prod_id and prod_quantity of each element in vector vec
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i].prod_id << " " << vec[i].prod_quantity << endl;
    }
    /*---------------------------------------------------------------------------------------------------------------*/
    return 0;
}
/*---------------------------------------------------------------------------------------------------------------*/
//Minor workspace 5: Identify functions usage
