#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
    
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

void bt_insert(Node* &root, int val){
    if(root == nullptr) {
        root = new Node(val);
        return;
    }
    else {
        if(val < root->data) bt_insert(root->left, val);
        else bt_insert(root->right, val);
    }
}

int sum = 0;
vector<int> v;

int count(Node* cur){
    if(cur == nullptr) return 0;
    v.push_back(cur->data);
    return 1 + count(cur->left) + count(cur->right);
}

int search_subtree(Node* cur, int val){
    if(cur == nullptr) return 0;
    else if(cur->data == val) return count(cur);
    else if(val < cur->data) return search_subtree(cur->left, val);
    else return search_subtree(cur->right, val);
}


int main() {
    
    int n, x;
    Node* root = NULL;
    
    cin >> n;
    
    for(int i = 1; i <= n; i++){
        cin >> x;
        bt_insert(root, x);
    }
    
    cin >> x;
    
    Node* cur = root;
    
    search_subtree(cur, x);
    
    for(int i : v) cout << i << ' ';
    
    return 0;
}