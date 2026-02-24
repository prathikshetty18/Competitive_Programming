#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(int x1, int y1, int x2, int y2){

    if(y2 < y1){

        cout << -1 << endl;
        return;
    }

    int steps = y2 - y1;

    if(x1 + steps < x2){

        cout << -1 << endl;
        return;
    }

    cout << steps + (x1 + steps - x2) << endl;
}

int main(){

    int t;
    cin >> t;

    while(t > 0){

        int a, b, c, d;

        cin >> a >> b >> c >> d;

        solve(a, b, c, d);

        t--;
    }
}