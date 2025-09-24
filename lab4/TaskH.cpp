#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

void insert(Node* &root, int val) {
    if(root == NULL) {
        root = new Node(val);
        return;
    }
    if(val <= root->val) insert(root->left, val);
    else if(val > root->val) insert(root->right, val);
}

vector<int> v;

void print(Node* root){
    if(root == NULL) return;
    v.push_back(root->val);
    print(root->left);
    print(root->right);
}

int main() {
    int n, a[105], sum = 0, pref[105];
    cin >> n;
    
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    
    pref[0] = 0;
    for(int i = 1; i <= n; i++) pref[i] = pref[i-1] + a[i];
    
    Node* root = NULL;
    for(int i = 1; i <= n; i++) insert(root, pref[n] - pref[i-1]);
    
    print(root);
    for(int i = v.size() -1; i >= 0; i--) cout << v[i] <<  ' ';
    return 0;
}