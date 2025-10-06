#include <bits/stdc++.h>
using namespace std;

bool isVowel(char c) {
    return (c == 'a' || c == 'o' || c == 'i' || c == 'e' || c == 'u');
}

bool cmp(char a, char b) {
    bool ok1 = isVowel(a);
    bool ok2 = isVowel(b);

    if (ok1 != ok2) return ok1;
    return a < b;
}

int main() {
    int n;
    string s;

    cin >> n >> s;

    sort(s.begin(), s.end(), cmp);

    cout << s;

    return 0;
}