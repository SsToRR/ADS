#include <bits/stdc++.h>

using namespace std;

struct Node {
    string val;
    Node* next;
    Node* prev;
    Node(string x) : val(x), next(NULL), prev(NULL){}
};
    
int main() {
    
    int n, cnt = 1;
    string s;
    
    cin >> n;
    
    Node *head = NULL, *tail = NULL;
    
    for(int i = 1; i <= n; i++){
        cin >> s;
        Node* node = new Node(s);
        if(head == NULL) head = tail = node;
        else {
            if(s != tail->val) cnt++;
            //NULL Miras
            //Miras Miras
            //Miras A
            //A NULL
            //Miras Miras A
            //damn bro ts is not easy bruh
            tail->next = node;
            node->prev = tail;
            tail = node;
            
        }
    }
    cout << "All in all: " << cnt << '\n' << "Students:\n";
    Node* cur = tail;
    while(cur != NULL){
        cout << cur->val << '\n';
        while(cur->prev != NULL && cur->val == cur->prev->val){
            cur = cur->prev;
        }
        cur = cur->prev;
    }
    
    return 0;
}