#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(int a1, int a2, int a4, int a5){

    unordered_set<int> s;

    s.insert(a1 + a2);
    s.insert(a4 - a2);
    s.insert(a5 - a4);

    if(s.size() == 1) cout << 3 << endl;
    else if(s.size() == 2) cout << 2 << endl;
    else cout << 1 << endl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t > 0){

        int a1, a2, a4, a5;
        
        cin >> a1 >> a2 >> a4 >> a5;

        solve(a1, a2, a4, a5);

        t--;
    }
}

