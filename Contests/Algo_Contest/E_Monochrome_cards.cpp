#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sp " "
#define nl "\n"

void solve(ll &n){

    ll W1 = 0, B1 = 0, W2 = 0, B2 = 0;

    ll i = 1;
    ll flag = 1;

    while(n > 0){

        if(flag){

            W1 += i/2 + (i % 2 != 0);
            B1 += i/2;
        }
        else{

            W2 += i/2;
            B2 += i/2 + (i % 2 != 0);
        }

        flag = !flag;

        n -= i;
        i = min(i + 4, n);
    }

    cout << W1 << sp << B1 << sp << W2 << sp << B2 << nl;
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

