#include <bits/stdc++.h>
using namespace std;

bool cmp(string a, string b){
    return a.size() < b.size();
}

int main() {
    int T;
    cin >> T;
    cin.ignore();

    while (T--) {
        string line;
        getline(cin, line);
        if(line.empty()) getline(cin, line);

        stringstream ss(line);
        vector<string> v;
        string s;

        while (ss >> s) v.push_back(s);
        
        stable_sort(v.begin(), v.end(), cmp);

        for (int i = 0; i < v.size(); ++i)
            cout << v[i] << ' ';
        
        cout << '\n';
    }

    return 0;
}