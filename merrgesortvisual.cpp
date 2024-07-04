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

/*---------------------------------------------------------------------------------------------------------------*/
//Minor workspace 3: Identify lower functions
void mergeSort_array(int a[], int l, int m, int r) {
    int left_len = m - l + 1;
    int right_len = r - m;

    std::vector<int> temp_left(left_len);
    std::vector<int> temp_right(right_len);

    for (int i = 0; i < left_len; i++) {
        temp_left[i] = a[l + i];
    }
    for (int i = 0; i < right_len; i++) {
        temp_right[i] = a[(m + i) + 1];
    }
    int i = 0, j = 0, k;
    for (k = l; k <= r; k++) {
        if ( (i < left_len) && (j >= right_len || temp_left[i] <= temp_right[j]) ) {
            a[k] = temp_left[i];
            i++;
        } else {
            a[k] = temp_right[j];
            j++;
        }
    }
}

void mergeSort_recursion(int a[], int l, int r) {
    if (l < r) {
        int m = l + (r - l)/2;
        mergeSort_recursion(a, l, m);
        mergeSort_recursion(a, m + 1, r);
        mergeSort_array(a,l,m,r);
    }
}

void mergeSort(int a[], int n) {
    mergeSort_recursion(a, 0, n - 1);
}
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
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    mergeSort(a, n);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    /*---------------------------------------------------------------------------------------------------------------*/
    return 0;
}
/*---------------------------------------------------------------------------------------------------------------*/
//Minor workspace 5: Identify functions usage
