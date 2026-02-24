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
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define print(v) for(auto ele : v) cout << ele << sp; cout << nl;
#define mod 1000000007
ll mod_add(ll a, ll b, ll m = mod) { return ((a % m) + (b % m)) % m; }
ll mod_mul(ll a, ll b, ll m = mod) { return ((a % m) * (b % m)) % m; }
ll ceil_div(ll a, ll b){ return a/b + (a%b != 0); }

void solve(ll &n, ll &k){

    if((k - 1) % 2 == 0){

        for(ll i = 0; i < n-2; i++){
        
            cout << n << sp;
        }

        cout << n << sp << n-1 << nl;
    }
    else{

        for(ll i = 0; i < n-2; i++){
        
            cout << n-1 << sp;
        }

        cout << n << sp << n-1 << nl;
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while(t--){

        ll n, k;
        
        cin >> n >> k;

        solve(n, k);
    }
}

