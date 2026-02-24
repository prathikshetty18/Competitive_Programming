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

void solve(vll &v, ll &n, ll &x){

    sort(all(v));

    ll r = n-1;
    ll teams = 0;
    ll prevNotUsed = -1;

    while(r >= 0){

        // cout << "prevNotUsed: " << prevNotUsed << nl;

        if(v[r] >= x){

            teams++;
            r--;
            continue;
        }

        if(prevNotUsed == -1){
            
            prevNotUsed = r;
            r--;
            continue;
        }

        ll currStrength = v[r] * (prevNotUsed - r + 1);

        if(currStrength >= x){

            teams++;
            prevNotUsed = -1;
            r--;
            continue;
        }

        r--;
    }

    cout << teams << nl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while(t--){

        ll n, x;
        
        cin >> n >> x;

        vll v (n);

        for(ll i = 0; i < n; i++) cin >> v[i]; 

        solve(v, n, x);
    }
}

