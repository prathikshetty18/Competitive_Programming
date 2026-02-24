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

bool possible(vll &v, map<ll, ll> &cnt, ll &n, ll &m, ll &time){

    ll need = 0, extra = 0;

    for(auto [worker, count] : cnt){
    
        if(time >= count){

            extra += (time - count)/2;
        }
        else{

            need += (count - time);
        }
    }

    // cout << "need: " << need << " extra: " << extra << nl;

    if(extra >= need) return true;
    else return false;
}

void solve(vll &v, ll &n, ll &m){

    map<ll, ll> cnt;

    for(ll i = 0; i < m; i++){
    
        cnt[i+1] = 0;
    }

    for(ll i = 0; i < n; i++){
    
        cnt[v[i]]++;
    }

    ll l = 1, r = 2*n;

    while(l <= r){
        
        ll mid = l + (r-l)/2;
        
        // cout << "l: " << l << " r: " << r << " mid: " << mid << nl;

        if(possible(v, cnt, n, m, mid)) r = mid - 1;
        else l = mid + 1;


        // cout << "l: " << l << " r: " << r << " mid: " << mid << nl;
    }

    cout << l << nl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while(t--){

        ll m, n;    // n -> tasks, m -> workers
        
        cin >> m >> n;

        vll v (n);

        for(ll i = 0; i < n; i++) cin >> v[i]; 

        solve(v, n, m);
    }
}

