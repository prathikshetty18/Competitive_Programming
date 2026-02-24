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

bool isPossible(ll &x, ll &m, ll &k){

    ll tot = 0;

    if(m <= k){
        
        tot = m * (m + 1) / 2;
    }
    else{

        tot = k * (k + 1) / 2;

        ll diff = m - k;

        tot += diff * (k - 1 + (k - diff)) / 2;

        // cout << "diff: " << diff << " add: " << diff/2 * (k - 1 + (k - diff)) << nl;
    }

    // cout << "mid: " << m << " tot: " << tot << nl;

    return tot >= x;
}

void solve(ll &k, ll &x){

    ll l = 1, r = 2*k-1;

    while(l <= r){

        ll mid = l + (r-l)/2;

        // cout << "l: " << l << " r: " << r << nl;

        if(isPossible(x, mid, k)) r = mid-1;
        else l = mid+1;
    }

    if(l > 2*k - 1) l = 2*k - 1;
    
    cout << l  << nl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while(t--){

        ll k, x;
        
        cin >> k >> x; 

        solve(k, x);
    }
}

