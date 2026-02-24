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

void solve(ll &n){

    map<ll, ll> mp;

    vector<vector<ll>> mat (n);

    for(ll i = 0; i < n; i++){
    
        ll k; cin >> k;

        mat[i].resize(k);

        for(ll j = 0; j < k; j++){

            ll p; cin >> p;

            mp[p]++;
            mat[i][j] = p;
        }
    }

    for(ll i = 0; i < n; i++){

        bool flag = true;
    
        for(auto bit : mat[i]){

            if(mp[bit] == 1){

                flag = false;
                break;
            }
        }

        if(flag == true){

            cout << "YES" << nl;
            return;
        }
    }
    
    cout << "NO" << nl;
    return;
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

