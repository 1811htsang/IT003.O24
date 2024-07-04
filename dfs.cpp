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
int n, m; 
vector<int> adj[100];
bool visited[100];
void dfs(int u) {
    cout << u << " ";
    visited[u] = true;
    for (auto i: adj[u]) {
        if (!visited[i]) dfs(i);
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
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x,y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x); // neu la co huong thi bo dong nay 
    }
    memset(visited, false, sizeof(visited));
    dfs(1);

    /*---------------------------------------------------------------------------------------------------------------*/
    return 0;
}
/*---------------------------------------------------------------------------------------------------------------*/
//Minor workspace 5: Identify functions usage
