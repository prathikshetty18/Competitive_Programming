#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sp " "
#define nl  "\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define print(v) for(auto ele : v) cout << ele << sp; cout << nl;
#define mod 1000000007

void solve(ll &n, ll &x, ll &y){

    ll ans = 0;

    ll c1 = n/x;
    ll c2 = n/y;
    ll LCM = lcm(x, y);
    ll c3 = n/LCM;

    ll posCount = c1 - c3;
    ll negCount = c2 - c3;

    ll negSum = (negCount)*(negCount+1)/2;

    ll posSum = (n*(n+1)/2) - (n - posCount)*(n - posCount + 1)/2;

    ans = posSum - negSum;

    cout << ans << nl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while(t--){

        ll n, x, y;
        
        cin >> n >> x >> y;

        solve(n, x, y);
    }
}

