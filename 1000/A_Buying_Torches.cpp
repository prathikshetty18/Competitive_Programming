#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sp " "
#define nl "\n"

void solve(ll &x, ll &y, ll &k){

    // trades to reach req stick

    ll ans = (k*(y+1) - 1)/(x-1) +  ((k*(y+1) - 1) % (x-1) != 0);

    ans += k;   // trades to get req coat

    cout << ans << nl;

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t > 0){

        ll x, y, k;
        
        cin >> x >> y >> k;

        solve(x, y, k);

        t--;
    }
}

