#include <bits/stdc++.h>
using namespace std;

struct Node {
    char val;
    Node* next;
    Node(char x) : val(x), next(NULL){} 
};

int cnt = 0;

int main() {
    
    int tt;
    
    cin >> tt;
    
    while(tt--){
        int n; char c;
        map<char, int> mp;
        cin >> n;
        
        Node *head = NULL, *tail = NULL;
        
        for(int i = 1; i <= n; i++){
            cin >> c;
            Node* node = new Node(c);
            if(head == NULL) head = tail = node;
            else {
                    tail->next = node;
                    tail = node;
                
            }
            Node* cur = head;
            mp[c]++;
            while(cur != NULL && mp[cur->val] > 1) {
                cur = cur->next;
            }
            if(cur == NULL) cout << -1 << ' ';
            else cout << cur->val << ' ';
                }
                
            cout << endl;
    }
    
    return 0;
}
