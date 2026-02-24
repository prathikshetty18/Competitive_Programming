#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sp " "
#define nl "\n"

void solve(ll &a, ll &b){

    ll ans = INT_MAX;


    for(int i = 0; i <= 30; i++){

        if(b + i >= 2){

            ll steps = i;
            ll x = a;

            while(x){

                x = x/(b+i);
                steps++;
            }

            ans = min(ans, steps);
        }
    }

    cout << ans << nl;
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

