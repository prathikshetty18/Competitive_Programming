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

void solve(vector<bool> &check, ll &n){

    if(check[n]) cout << "YES" << nl;
    else cout << "NO" << nl;

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    vector<bool> check (1e6+1, false);

    for(ll k = 2; k <= 1e6; k++){

        ll startVal = 1;
        startVal += k;
        startVal += k*k;

        ll toAdd = k*k;

        while(startVal <= 1e6){

            check[startVal] = true;
            toAdd *= k;
            startVal += toAdd;
        }
    }

    while(t--){

        ll n;
        
        cin >> n;

        solve(check, n);
    }
}

