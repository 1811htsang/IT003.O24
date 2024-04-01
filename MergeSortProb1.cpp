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
void merge(int a[], int left, int mid, int right) {
    int b[100];
    for (int i = 0; i < right; i++) b[i] = a[i];
    int l_length = mid - left + 1;
    int r_length = right - mid;
    int l_array[l_length], r_array[r_length];
    for (int i = 0; i < l_length; i++) {
        l_array[i] = a[left + i];
        cout << l_array[i] << " ";
        
    }
    for (int j = 0; j < right; j++) cout << b[j] << " ";
    cout << endl;
    for (int i = 0; i < r_length; i++) {
        r_array[i] = a[mid + 1 + i];
        cout << r_array[i] << " ";
        //for (int j = i; j < right; j++) cout << a[j] << " ";
    }
    cout << endl;
    int i = 0, j = 0, k = left;
    for(k = left; k <= right; k++) {
		if ( (i < l_length) && (j >= r_length || l_array[i] <= r_array[j]) ) {
			a[k] = l_array[i];
			i++;
		} else {
			a[k] = r_array[j];
			j++;
		}
	}
}

void mergesort_recursion(int a[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergesort_recursion(a, left, mid);
        mergesort_recursion(a, mid + 1, right);
        merge(a, left, mid, right);
    }
}

void merge_sort(int a[], int n) {
    mergesort_recursion(a, 0, n - 1);
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
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n ; i++) cin >> a[i];
    merge_sort(a, n);
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    /*---------------------------------------------------------------------------------------------------------------*/
    return 0;
}
/*---------------------------------------------------------------------------------------------------------------*/
//Minor workspace 5: Identify functions usage
