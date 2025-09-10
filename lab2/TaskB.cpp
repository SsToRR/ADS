#include <bits/stdc++.h>

using namespace std;

struct Node {
    string data;
    Node* next;
    Node(string x) : data(x), next(NULL){}
};
    
int main() {
    
    int n, k, cnt = 0;
    string s;
    
    cin >> n >> k;
    
    Node *head = NULL, *tail = NULL;
    
    for(int i = 1; i <= n; i++){
        cin >> s;
        Node* node = new Node(s);
        if(head == NULL) head = tail = node;
        else {
            tail->next = node;
            tail = node;
        }
    }
    Node* cur = head;
    while(cur != NULL){
        if(cnt >= k) cout << cur->data << ' ';
        cur = cur->next;
        cnt++;
    }
    cnt = 0; cur = head;
    while(cnt < k) {
        cout << cur->data << ' ';
        cur = cur->next;
        cnt++;
    }
    
    return 0;
}