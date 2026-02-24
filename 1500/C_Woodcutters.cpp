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

void solve(vpll &v, ll &n){

    ll cover = v[0].ff;
    ll cnt = 1;

    for(ll i = 1; i < n; i++){

        // cout << "cover: " << cover << " cnt: " << cnt << nl;
    
        if(v[i].ff - cover - 1 >= v[i].ss){

            cover = v[i].ff;
            cnt++;
        }
        else if(i == n-1 || v[i+1].ff > v[i].ff + v[i].ss){

            cover = v[i].ff + v[i].ss;
            cnt++;
        }
        else cover = v[i].ff;

        // cout << "cover: " << cover << " FINcnt: " << cnt << nl;
    }

    cout << cnt << nl;
}   

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;

    while(t--){

        ll n;
        
        cin >> n;

        vpll v (n);

        for(ll i = 0; i < n; i++) cin >> v[i].ff >> v[i].ss; 

        solve(v, n);
    }
}

