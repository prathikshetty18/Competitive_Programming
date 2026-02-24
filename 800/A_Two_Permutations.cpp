#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(int n, int a , int b){

    if(a == n && b == n) cout << "Yes\n";
    else{

        if(b > n - a - 2) cout << "No\n";
        else cout << "Yes\n";
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t > 0){

        int n, a, b;

        cin >> n >> a >> b;

        solve(n, a, b);

        t--;
    }
}

// n, (x, n - x - 2) because atleast a pair will need to be wrong always
// => if b > n - a - 2 => invalid
// if a or b = n-1 => invalid (taken care by above condition)
// however a = b = n is valid 