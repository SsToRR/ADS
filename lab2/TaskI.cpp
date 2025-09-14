#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node *prev;
    Node *next;
    string val;
    Node(string _val) {
        prev = NULL;
        next = NULL;
        val = _val;
    }
};

Node *head = NULL;
Node *tail = NULL;
int cnt = 0;

void add_back(string s) {
    Node *node = new Node(s);
    if (!head) {
        head = tail = node;
    } else {
        tail->next = node;
        node->prev = tail;
        tail = node;
    }
    cnt++;
}

void add_front(string s) {
    Node *node = new Node(s);
    if (!head) {
        head = tail = node;
    } else {
        node->next = head;
        head->prev = node;
        head = node;
    }
    cnt++;
}

bool empty() {
    return cnt == 0;
}

void erase_front() {
    if (empty()) return;
    Node *tmp = head;
    if (head == tail) {
        head = tail = NULL;
    } else {
        head = head->next;
        head->prev = NULL;
    }
    delete tmp;
    cnt--;
}

void erase_back() {
    if (empty()) return;
    Node *tmp = tail;
    if (head == tail) {
        head = tail = NULL;
    } else {
        tail = tail->prev;
        tail->next = NULL;
    }
    delete tmp;
    cnt--;
}

string front() {
    return head->val;
}

string back() {
    return tail->val;
}

void clear() {
    while (!empty()) {
        erase_front();
    }
}

int main() {
    string s;
    while (cin >> s) {
        if (s == "add_front") {
            string t;
            cin >> t;
            add_front(t);
            cout << "ok" << endl;
        }
        if (s == "add_back") {
            string t;
            cin >> t;
            add_back(t);
            cout << "ok" << endl;
        }
        if (s == "erase_front") {
            if (empty()) {
                cout << "error" << endl;
            } else {
                cout << front() << endl;
                erase_front();
            }
        }
        if (s == "erase_back") {
            if (empty()) {
                cout << "error" << endl;
            } else {
                cout << back() << endl;
                erase_back();
            }
        }
        if (s == "front") {
            if (empty()) {
                cout << "error" << endl;
            } else {
                cout << front() << endl;
            }
        }
        if (s == "back") {
            if (empty()) {
                cout << "error" << endl;
            } else {
                cout << back() << endl;
            }
        }
        if (s == "clear") {
            clear();
            cout << "ok" << endl;
        }
        if (s == "exit") {
            cout << "goodbye" << endl;
            break;
        }
    }
    return 0;
}