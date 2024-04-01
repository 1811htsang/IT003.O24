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
struct point {
    long long int x, y;
};
struct list_point {
    point* data;
    long long int size;
};
/*---------------------------------------------------------------------------------------------------------------*/
//Minor workspace 3: Identify lower functions
void input(list_point& l) {
    cin >> l.size;
    l.data = multiple_target_dynamic_allo<point>(l.size);
    for (int i = 0; i < l.size; i++) {
        cin >> l.data[i].x >> l.data[i].y;
    }
}
void output(list_point l) {
    for (int i = 0; i < l.size; i++) {
        cout << l.data[i].x << " " << l.data[i].y << '\n';
    }
}

// void arrange(list_point& l) {
//     //selection sort
//     int i,j,min_idx;
//     for (i = 0; i < l.size-1; i++) {
//         min_idx = i;
//         for (j = i+1; j < l.size; j++) {
//             if (l.data[j].x < l.data[min_idx].x) min_idx = j;
//             if (l.data[j].x == l.data[min_idx].x) {
//                 if (l.data[j].y > l.data[min_idx].y) min_idx = j;
//             }
//         }
//         swap(l.data[min_idx], l.data[i]);
//     }
// }
// int partition(list_point& l, int left, int right) {
//     int pivot = left + (rand() % (right - left + 1));
//     int i = -1;
//     for (int j = 0; j < l.size - 1; j++) {
//         if (l.data[j].x < l.data[pivot].x) {
//             i++;
//             swap(l.data[i], l.data[j]);
//         }
//         if (l.data[j].x == l.data[pivot].x) {
//             if (l.data[j].y > l.data[pivot].y) {
//                 i++;
//                 swap(l.data[i], l.data[j]);
//             }
//         }
//     }
//     swap(l.data[i + 1], l.data[pivot]);
//     return i + 1;
// }
// void quick_arrange_recursion(list_point& l, int left, int right) {
//     if (left < right) {
//         int pivot = partition(l, left, right);
//         quick_arrange_recursion(l, left, pivot - 1);
//         quick_arrange_recursion(l, pivot + 1, right);
//     }
// }
// void quick_arrange(list_point& l) {
//     srand(time(NULL));
//     quick_arrange_recursion(l, 0, l.size - 1);
// }

void heapify(list_point& l, int n, int i) {
    int largest = i;
    int l_child = 2 * i + 1;
    int r_child = 2 * i + 2;
    if (l_child < n && l.data[l_child].x > l.data[largest].x) largest = l_child;
    if (l_child < n && l.data[l_child].x == l.data[largest].x) {
        if (l.data[l_child].y < l.data[largest].y) largest = l_child;
    }
    if (r_child < n && l.data[r_child].x > l.data[largest].x) largest = r_child;
    if (r_child < n && l.data[r_child].x == l.data[largest].x) {
        if (l.data[r_child].y < l.data[largest].y) largest = r_child;
    }
    if (largest != i) {
        swap(l.data[i], l.data[largest]);
        heapify(l, n, largest);
    }
}
void heap_sort(list_point& l) {
    for (int i = l.size / 2 - 1; i >= 0; i--) {
        heapify(l, l.size, i);
    }
    for (int i = l.size - 1; i > 0; i--) {
        swap(l.data[0], l.data[i]);
        heapify(l, i, 0);
    }
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
    list_point l;
    input(l);
    // quick_arrange(l);
    heap_sort(l);   
    output(l);
    /*---------------------------------------------------------------------------------------------------------------*/
    return 0;
}
/*---------------------------------------------------------------------------------------------------------------*/
//Minor workspace 5: Identify functions usage