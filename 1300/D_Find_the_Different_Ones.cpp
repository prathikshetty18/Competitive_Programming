#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sp " "
#define nl  "\n"
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

void solve(vll &v, vll &nextDiff, ll &n){

    ll q;
    cin >> q;

    // for(auto it : nextDiff){

    //     cout << it << sp;
    // }

    // cout << nl;

    for(ll i = 0; i < q; i++){
    
        ll l, r;

        cin >> l >> r;

        // cout << "nextDiff[l]: " << nextDiff[l] << nl;

        if(nextDiff[l] == -1 || r < nextDiff[l]){

            cout << -1 << sp << -1 << nl;
        }
        else{

            cout << l << sp << nextDiff[l] << nl;
        }
    }

    cout << nl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while(t--){

        ll n;
        
        cin >> n;

        vll v (n), nextDiff (n+1);

        nextDiff[n] = -1;

        for(ll i = 0; i < n; i++) cin >> v[i];
        
        for(ll i = n-2; i >= 0; i--){
        
            if(v[i] == v[i+1]) nextDiff[i+1] = nextDiff[i+2];   // one based indexing
            else nextDiff[i+1] = i+2;
        }

        solve(v, nextDiff, n);
    }
}

