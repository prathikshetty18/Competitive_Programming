#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sp " "
#define nl  "\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define print(v) for(auto ele : v) cout << ele << sp; cout << nl;
#define mod 1000000007

void solve(ll &n){

    // 1*1, 1*2, 2*2, 2*3, 3*3  .... n*n

    ll ans = 2022/6;

    ans = (ans*n)%mod;
    ans = (ans *(n+1))%mod;
    ans = (ans *(4*n-1))%mod;

    cout << ans << nl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){

        ll n;
        
        cin >> n;

        solve(n);
    }
}