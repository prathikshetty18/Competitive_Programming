#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sp " "
#define nl "\n"

void solve(ll &n){

    if(n == 2){

        cout << 3 << sp << 1 << nl;
        return;
    }

    if(n % 2 == 1){

        for(int i = 0; i < n; i++){
            
            cout << 1 << sp;
        }

        cout << nl;
        return;
    }

    cout << 2 << sp << 13 << sp << 8 << sp << 1 << sp;

    n -= 4;

    while(n > 0){

        cout << 6 << sp << 6 << sp;
        n -= 2;
    }

    cout << nl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t > 0){

        ll n;
        
        cin >> n;

        solve(n);

        t--;
    }
}

