#include <bits/stdc++.h>
 
using namespace std;
 
struct Node{
    int val;
    Node* next;
    Node(): val(0), next(nullptr) {}
    Node(int x): val(x), next(nullptr) {}
    Node(Node* next): val(0), next(next) {}
    Node(int x, Node* next): val(x), next(next) {}
};
 
Node* insert(Node* head, Node* node, int p) {
    if (p == 0) {
        node->next = head;
        return node;
    }
    Node* cur = head;
    for(int i = 1; i <= p - 1 && cur != NULL; i++) cur = cur->next;
    node->next = cur->next;
    cur->next = node;
    return head;
}

Node* remove(Node* head, int p) {
    if (!head) return NULL;
    if (p == 0) {
        Node* tmp = head->next;
        delete head;
        return tmp;
    }
    Node* cur = head;
    for (int i = 1; i <= p - 1 && cur; i++) cur = cur->next;
    Node* tmp = cur->next;
    cur->next = tmp->next;
    delete tmp;
    return head;
}

Node* replace(Node* head, int p1, int p2) {
    if (!head || p1 == p2) return head;

    Node* prev = NULL;
    Node* cur1 = head;
    for (int i = 1; i <= p1; i++) {
        prev = cur1;
        cur1 = cur1->next;
    }

    if(prev != NULL) prev->next = cur1->next;
    else head = cur1->next;

    Node* node = cur1;

    if(p2 == 0){
        node->next = head;
        return node;
    }

    Node* cur2 = head;
    for (int i = 0; i < p2 - 1; i++) cur2 = cur2->next;
    node->next = cur2->next;
    cur2->next = node;

    return head;
}

Node* reverse(Node* head) {
    Node* prev = NULL;
    Node* cur = head;
    while(cur){
        Node* nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    return prev;
}

void print(Node* head) {
    if (!head) {
        cout << -1 << endl;
        return;
    }
    while (head) {
        cout << head->val;
        if (head->next) cout << " ";
        head = head->next;
    }
    cout << endl;
}

Node* cyclic_left(Node* head, int x) {
    if (!head || !head->next) return head;

    int len = 0;
    Node* tail = head;
    while (tail->next) {
        tail = tail->next;
        len++;
    }
    len++;

    x %= len;
    if (x == 0) return head;

    tail->next = head;
    Node* newTail = head;
    for (int i = 0; i < x - 1; i++) newTail = newTail->next;
    Node* newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}

Node* cyclic_right(Node* head, int x) {
    if (!head || !head->next) return head;

    int len = 0;
    Node* tail = head;
    while (tail->next) {
        tail = tail->next;
        len++;
    }
    len++;

    x %= len;
    if (x == 0) return head;

    return cyclic_left(head, len - x);
}

 
int main(){
    Node* head = NULL;
    while (true){
        int command; cin >> command;
        if (command == 0){
            break;
        }else if(command == 1){
            int x, p; cin >> x >> p;
            head = insert(head, new Node(x), p);
        }else if (command == 2){
            int p; cin >> p;
            head = remove(head, p);
        }else if (command == 3){
            print(head);
        }else if (command == 4){
            int p1, p2; cin >> p1 >> p2;
            head = replace(head, p1, p2);
        }else if (command == 5){
            head = reverse(head);
        }else if (command == 6){
            int x; cin >> x;
            head = cyclic_left(head, x);
        }else if (command == 7){
            int x; cin >> x;
            head = cyclic_right(head, x);
        }   
    }
    return 0;
}