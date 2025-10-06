#include <bits/stdc++.h>
using namespace std;

struct date {
    int day;
    int month;
    int year;
};

bool cmp(date a, date b){
    if(a.year != b.year) return a.year < b.year;
    if(a.month != b.month) return a.month < b.month;
    return a.day < b.day;    
}

int main() {
    
    int n;
    date d[1005];
    string s;
    
    cin >> n;
    
    for(int i = 1; i <= n; i++){
        cin >> s;
        int _day = (s[0] - '0') * 10 + (s[1] - '0');
        int _month = (s[3] - '0') * 10 + (s[4] - '0');
        int _year = (s[6] - '0') * 1000 + (s[7] - '0') * 100 + (s[8] - '0') * 10 + (s[9] - '0');
        d[i].day = _day;
        d[i].month = _month;
        d[i].year = _year;
    }
    sort(d + 1, d + 1 + n, cmp);
    
    for(int i = 1; i <= n; i++){
        if(d[i].day < 10) cout << 0 << d[i].day << '-';
        else cout << d[i].day << '-';
        if(d[i].month < 10) cout << 0 << d[i].month << '-';
        else cout << d[i].month << '-';
        cout << d[i].year << '\n';
    }
    
    return 0;
}