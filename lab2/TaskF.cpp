#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(NULL){}
};
    
int main() {
    
    int n, x, pos, var;
    
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
    cin >> var >> pos;
    //NULL 16
    //16 13
    //13 7 -> 13 1
    //7 NULL
    //1, 2
    Node* new_node = new Node(var);
    
    if(pos == 0){
        new_node->next = head;
        head = new_node;
    } else {
        int cnt = 0;
        Node* cur = head;
        while(++cnt != pos)
            cur = cur->next;
        new_node->next = cur->next;
        cur->next = new_node;
    }
    Node* cur = head;
    while(cur != NULL){
        cout << cur->val << ' ';
        cur = cur->next;
    }
    
    return 0;
}