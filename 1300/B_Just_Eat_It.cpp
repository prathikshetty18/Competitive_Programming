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

void solve(vll &v, ll &n){

    vll pre (1, 0);
    ll curr = 0;

    for(ll i = 0; i < n; i++){
    
        curr += v[i];
        pre.pb(curr);
    }

    // only NO if there is a preSum <= 0 from i = 0 -> i or postsum from i -> i = n-1 <= 0

    for(ll i = 0; i < n; i++){

        if(pre[i+1] - pre[0] <= 0){

            cout << "NO" << nl;
            return;
        }
        else if(pre[n] - pre[i] <= 0){

            cout << "NO" << nl;
            return;  
        }

    }

    cout << "YES\n";
    return;
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

