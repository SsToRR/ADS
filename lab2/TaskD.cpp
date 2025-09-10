#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(NULL){}
};
    
int main() {
    
    int n, x, mx = 0;
    map<int, int> mp;
    
    cin >> n;
    
    Node *head = NULL, *tail = NULL;
    
    for(int i = 1; i <= n; i++){
        cin >> x;
        mp[x]++, mx = max(mx, mp[x]);
        Node* node = new Node(x);
        if(head == NULL) head = tail = node;
        else {
            tail->next = node;
            tail = node;
        }
    }
    
    Node* cur = head;
    set<int> st;
    
    while(cur != NULL){
        if(mp[cur->val] == mx) st.insert(cur->val);
        cur = cur->next;
    }
    for(auto it = st.rbegin(); it != st.rend(); it++) cout << *it << ' ';
    
    
    return 0;
}