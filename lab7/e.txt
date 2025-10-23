#include <bits/stdc++.h>
using namespace std;

int n, m, x;

struct row{
    int sum;
    int elements[502];
};

bool cmp(row a, row b){
    if(a.sum != b.sum) return a.sum > b.sum;
    
    for (int i = 1; i <= m; i++) {
        if (a.elements[i] != b.elements[i])
            return a.elements[i] < b.elements[i];
    }
    return false;
}

int main() {
    
    row rows[502];

    cin >> n >> m;
    
    for(int i = 1; i <= n; i++){
        rows[i].sum = 0;
        for(int j = 1; j <= m; j++){
            cin >> rows[i].elements[j];
            rows[i].sum += rows[i].elements[j];
        }
    }
    sort(rows + 1, rows + 1 + n, cmp);
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cout << rows[i].elements[j] << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}