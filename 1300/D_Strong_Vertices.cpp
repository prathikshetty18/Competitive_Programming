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

void solve(vll &v, ll &n){

    ll maxi = LLONG_MIN;
    ll cnt = 0;
    vll ans;

    for(ll i = 0; i < n; i++){
    
        if(v[i] > maxi){

            maxi = v[i];
            cnt = 1;
            ans.clear();
            ans.pb(i+1);
        }
        else if(v[i] == maxi){

            cnt++;
            ans.pb(i+1);
        }
    }

    // sort(all(ans));

    cout << cnt << nl;

    print(ans);

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while(t--){

        ll n;
        
        cin >> n;

        vll a (n), b (n), c (n);

        for(ll i = 0; i < n; i++) cin >> a[i]; 
        for(ll i = 0; i < n; i++) cin >> b[i]; 
        for(ll i = 0; i < n; i++) c[i] = a[i] - b[i]; 

        solve(c, n);
    }
}

