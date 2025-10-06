#include <bits/stdc++.h>
using namespace std;

struct person{
    string name;
    string surname;
    double gpa;
};

bool cmp (person a, person b){
    if(a.gpa != b.gpa) return a.gpa < b.gpa;
    if(a.surname != b.surname) return a.surname < b.surname;
    return a.name < b.name;
}

int main() {
    
    int n, m;
    double x;
    string s;
    person p[100005];
    
    cin >> n;
    
    for(int i = 1; i <= n; i++){
        cin >> p[i].surname >> p[i].name >> m;
        int sum_of_credits = 0; double sum_of_gpa = 0;
        for(int j = 1; j <= m; j++){
            cin >> s >> x;
            if(s == "A+") sum_of_gpa += (4.0 * x);
            if(s == "A") sum_of_gpa += (3.75 * x);
            if(s == "B+") sum_of_gpa += (3.5 * x);
            if(s == "B") sum_of_gpa += (3.0 * x);
            if(s == "C+") sum_of_gpa += (2.5 * x);
            if(s == "C") sum_of_gpa += (2.0 * x);
            if(s == "D+") sum_of_gpa += (1.5 * x);
            if(s == "D") sum_of_gpa += (1.0 * x);
            if(s == "F") sum_of_gpa += (0 * x);
            
            sum_of_credits += x;
        }
        p[i].gpa = sum_of_gpa / double(sum_of_credits);
    }
    sort(p + 1, p + 1 + n, cmp);
    
    for(int i = 1; i <= n; i++){
        cout.precision(3);
        cout << p[i].surname << ' ' << p[i].name << ' ' << fixed << p[i].gpa << '\n';
    }
    
    return 0;
}