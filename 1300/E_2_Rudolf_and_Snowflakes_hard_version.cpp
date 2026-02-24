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

ll getVal(ll &k, ll &p){

    ll start = 1;
    ll toAdd = 1;

    for(ll i = 1; i <= p; i++){

        toAdd *= k;
        start += toAdd;
    }

    return start;
}

bool binarySearch(ll &n, ll &p){

    // n < k ^ (p+1) we know => uppoer bound on k is n ^ (1/p+1)

    double power = 1 / double(p);
    double k_bound = pow(n, power);

    ll l = 2, r = k_bound+1;

    while(l <= r){

        ll mid = l + (r - l)/2;
        
        if(getVal(mid, p) >= n){

            r = mid-1;
        }
        else{

            l = mid+1;
        }
    }

    return (getVal(l, p) == n);
}

void solve(ll &n){

    // max power can be 63;

    for(ll p = 2; p < 64; p++){
    
        if(binarySearch(n, p)){

            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while(t--){

        ll n;
        
        cin >> n;

        solve(n);
    }
}

