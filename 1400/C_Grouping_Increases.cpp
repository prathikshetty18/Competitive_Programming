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

void solve(vll &v, ll &n){

    // maintain the 2 new subsequences last elements and make t2 >= t1 without loosing generality as the 2 arrays can be swapped

    ll t1 = LLONG_MAX, t2 = LLONG_MAX;

    ll ans = 0;

    
    for(ll i = 0; i < n; i++){
    
        if(t1 > t2) swap(t1, t2);

        if(v[i] <= t1) t1 = v[i];
        else if(v[i] > t2){
            
            t1 = v[i];
            ans++;
        }
        else t2 = v[i];
    }

    cout << ans << nl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while(t--){

        ll n;
        
        cin >> n;

        vll v (n);

        for(ll i = 0; i < n; i++) cin >> v[i]; 

        solve(v, n);
    }
}

