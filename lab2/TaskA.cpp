#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL){}
};
    
int main() {
    
    int n, k, pos, mn = INT_MAX, cnt = 0, x;
    
    cin >> n;
    
    Node *head = NULL, *tail = NULL;
    
    for(int i = 1; i <= n; i++){
        cin >> x;
        Node* node = new Node(x);
        if(head == NULL) head = tail = node;
        else {
            tail->next = node;
            tail = node;
        }
    }
    
    Node* cur = head;
    
    cin >> k;
    
    while(cur != NULL){
        if(abs(cur->data - k) < mn){
            mn = abs(cur->data - k);
            pos = cnt;
        }
        cur = cur->next;
        cnt++;
    }
    cout << pos;
    
    return 0;
}