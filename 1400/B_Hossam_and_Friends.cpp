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
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define print(v) for(auto ele : v) cout << ele << sp; cout << nl;
#define mod 1000000007
ll mod_add(ll a, ll b, ll m = mod) { return ((a % m) + (b % m)) % m; }
ll mod_mul(ll a, ll b, ll m = mod) { return ((a % m) * (b % m)) % m; }
ll ceil_div(ll a, ll b){ return a/b + (a%b != 0); }

void solve(vvll &v, ll &n, ll &m){

    vll mini (n, n-1);

    for(ll i = 0; i < m; i++){

        mini[v[i][0]] = min(mini[v[i][0]], v[i][1]-1);
    }

    for(ll i = n-2; i >= 0; i--){
    
        mini[i] = min(mini[i], mini[i+1]);
    }

    // print(mini);

    ll ans = 0;

    for(ll i = 0; i < n; i++){

        ans += mini[i] - i + 1;
    }

    cout << ans << nl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while(t--){

        ll n, m;
        
        cin >> n >> m;

        vvll v (m, vll (2));

        for(ll i = 0; i < m; i++){
            
            cin >> v[i][0] >> v[i][1]; 
            v[i][0]--;
            v[i][1]--;
            sort(all(v[i]));
        }

        solve(v, n, m);
    }
}

