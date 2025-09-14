#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *next;

    Node() {
        val = 0;
        next = NULL;
    }
};

int mx = INT_MIN, sum = 0;

int findMaxSum(int n, Node *head) {
	
	for(int i = 0; i < n; i++){
	    Node* cur = head;
	    head = head->next;
	    sum = 0;
            while(cur != NULL){
                sum += cur->val;
                cur = cur->next;
                mx = max(mx, sum);
            }
	}
	return mx;
	
}


int main() {
    int n;
    cin >> n;

    Node *head, *tail;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        Node *cur = new Node();
        cur -> val = x;
    
        if (i == 1) {
            head = tail = cur;
        } else {
            tail -> next = cur;
            tail = cur;
        }
    }
    
    cout << findMaxSum(n, head) << "\n";
    return 0;
}