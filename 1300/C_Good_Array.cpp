#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sp " "
#define nl "\n"
#define pb push_back
#define sz size
#define ff first
#define ss second
#define vll vector<ll>
#define vpll vector<pair<ll, ll>>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define print(v) for(auto ele : v) cout << ele << sp; cout << nl;
#define mod 1000000007
ll mod_add(ll a, ll b, ll m = mod) { return ((a % m) + (b % m)) % m; }
ll mod_mul(ll a, ll b, ll m = mod) { return ((a % m) * (b % m)) % m; }
ll ceil_div(ll a, ll b){ return a/b + (a%b != 0); }

void solve(vpll &v, ll &n, ll &sum){

    sort(all(v));

    vll ans;

    for(ll i = 0; i < n - 1; i++){

        if(sum - v[i].ff == 2 * v.back().ff) ans.pb(v[i].ss);
    }

    if(sum - v[n-1].ff == 2 * v[n-2].ff) ans.pb(v[n-1].ss);

    cout << ans.size() << nl;
    print(ans);
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;

    while(t--){

        ll n, sum = 0;
        
        cin >> n;

        vpll v (n);

        for(ll i = 0; i < n; i++){
            
            cin >> v[i].ff; 
            v[i].ss = i + 1;

            sum += v[i].ff;
        }

        solve(v, n, sum);
    }
}

