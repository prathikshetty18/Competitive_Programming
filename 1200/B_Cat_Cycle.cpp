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

void solve(ll &n, ll &k){

    ll base = k % n == 0 ? n : k % n;

    if(n % 2 == 0){

        cout << base << nl;
        return;
    }

    ll ex = (k-1)/(n/2);

    base += ex;

    base = base % n == 0 ? n : base % n;

    cout << base << nl;
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

