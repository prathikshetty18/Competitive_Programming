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

void solve(vll &v, ll &n, ll &k){

    vll pre (1, 0);
    ll curr = 0;

    for(ll i = 0; i < n; i++){
    
        curr += v[i];
        pre.pb(curr);
    }

    double av = 0;

    for(ll i = k-1; i < n; i++){

        av += (double)(pre[i+1] - pre[i-k+1])/(n-k+1);
    }

    cout << fixed << setprecision(10) << av << nl;

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;

    while(t--){

        ll n, k;
        
        cin >> n >> k;

        vll v (n);

        for(ll i = 0; i < n; i++) cin >> v[i]; 

        solve(v, n, k);
    }
}

