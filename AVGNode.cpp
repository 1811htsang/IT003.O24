#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct TNode {
    int key;
    TNode * left, * right;
};

typedef TNode * TREE;

TREE CreateTree(vector<int> pre, vector<int> in, int preB, int preE, int inB, int inE) {
	int i;
	TREE root;
	if (inE < inB) return NULL;
	root = new TNode;
	if (root != NULL) {
		root->key = pre[preB];
		for (i = inB; i <= inE; i++)
			if (in[i] == pre[preB]) break;
		root->left = CreateTree(pre, in, preB+1, preE, inB, i - 1);
		root->right = CreateTree(pre, in, preB+i-inB+1, preE, i+1,inE);
	} return root;
}


double AverageByLevel(TREE, int);

int main() {
    vector<int> nlr, lnr;
    int n, key, m, lvl;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> key;
        nlr.push_back(key);
    }

    for (int i = 0; i < n; i++) {
        cin >> key;
        lnr.push_back(key);
    }

    TREE r = CreateTree(nlr, lnr, 0, nlr.size()-1, 0, lnr.size()-1);

    cin >> m;

    cout << setprecision(2) << fixed;

    for (int i = 0; i < m; i++) {
        cin >> lvl;
        cout << AverageByLevel(r, lvl) << endl;
    }

    return 0;
}

double AverageByLevel(TREE t, int x) {
    if (t == nullptr) return 0;
    else {
        double ans = 0;
        vector<TREE> vec;
        vector<TREE> temp;
        vec.push_back(t);

        while(vec.empty() == false) {
            
            TREE top = vec.front();
            vec.erase(vec.begin());
            temp.push_back(top);
            if (top->left != nullptr) vec.push_back(top->left);
            if (top->right != nullptr) vec.push_back(top->right);
        }

        for (int i = x + 1; i < temp.size(); i++) {
            ans += temp[i]->key;
        }
        return ans / (temp.size() - x);
    }
}
