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

void solve(map<ll, ll> &cnt, ll &n, ll &k, ll &maxi, ll &diff){

    if(maxi == LLONG_MIN){

        cout << 0 << nl;
        return;
    }

    // cout << "maxi: " << maxi << " diff: " << diff << nl;

    cout << k * (maxi - 1) + diff + 1 << nl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while(t--){

        ll n, k;
        
        cin >> n >> k;

        map<ll ,ll> cnt;
        ll maxi = LLONG_MIN;
        ll diff = -1;

        for(ll i = 0; i < n; i++){
            
            ll temp; cin >> temp;
            
            if(temp % k != 0){
                
                cnt[temp % k]++;
                if(cnt[temp % k] > maxi){
                    
                    maxi = cnt[temp % k];
                    diff = k - (temp % k);
                }
                else if(cnt[temp % k] == maxi && (k - (temp % k)) > diff){

                    diff = k - (temp % k);
                }
            }
        }

        solve(cnt, n, k, maxi, diff);
    }
}

