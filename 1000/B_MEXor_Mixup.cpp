#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sp " "
#define nl "\n"

void solve(ll &a, ll &b){

    ll miniXOR = 0;

    ll n = a - 1;

    if(n % 4 == 0) miniXOR = n;
    if(n % 4 == 1) miniXOR = 1;
    if(n % 4 == 2) miniXOR = n+1;
    if(n % 4 == 3) miniXOR = 0;

    if(miniXOR == b){

        cout << a << nl;
        return;
    }
    else if((miniXOR ^ a) == b){    // have to generate a using xor of 2 other numbers 

        cout << a + 2 << nl;
        return;
    }
    else{   // use the final number needed to get b as minXOR ^ b

        cout << a + 1 << nl;
        return;
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t > 0){

        ll a, b;
        
        cin >> a >> b;

        solve(a, b);

        t--;
    }
}

