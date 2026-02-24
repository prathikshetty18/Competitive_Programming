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

void solve(vll &v, ll &n){

    vvll pre (n+1, vll (30, 0));

    for(ll i = 1; i <= n; i++){
    
        for(ll j = 0; j < 30; j++){
        
            if(v[i-1] & (1 << j)){

                pre[i][j] = 1 + pre[i-1][j];
            }
            else{

                pre[i][j] = pre[i-1][j];
            }
        }
    }

    ll q; cin >> q;

    for(ll i = 0; i < q; i++){
    
        ll l, k; cin >> l >> k;

        if(v[l-1] < k){

            cout << -1 << sp;
            continue;
        }

        ll low = l, high = n;

        while(low <= high){

            ll mid = low + (high - low)/2;


            // cout << "low: " << low << " high: " << high << " mid: " << mid << nl;

            // cout << "mid - low + 1: " << mid - low + 1 << nl;

            ll num = 0;

            for(ll j = 0; j < 30; j++){
            
                if(pre[mid][j] - pre[l-1][j] == mid - l + 1){

                    num += (1 << j);
                }
            }

            // cout << "num: " << num << nl;

            if(num >= k){
                
                low = mid + 1;
            }
            else high = mid - 1;
        }

        cout << high << sp;
    }

    cout << nl;

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while(t--){

        ll n;
        
        cin >> n;

        vll v (n);

        for(ll i = 0; i < n; i++) cin >> v[i]; 

        solve(v, n);
    }
}

