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

void solve(vll &v, vll &w, ll &n){

    ll p1 = 0, p2 = 0;

    set<ll> fined;

    while(p1 < n){

        // cout << "P1: " << v[p1] << " P2: " << v[p2] << nl;

        if(fined.count(v[p1])){

            p1++;
        }
        else if(v[p1] != w[p2]){


            fined.insert(w[p2]);
            p2++;
        }
        else{

            p1++;
            p2++;
        }
    }

    cout << fined.size() << nl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;

    while(t--){

        ll n;
        
        cin >> n;

        vll v (n), w (n);

        for(ll i = 0; i < n; i++) cin >> v[i]; 
        for(ll i = 0; i < n; i++) cin >> w[i]; 

        solve(v, w, n);
    }
}

