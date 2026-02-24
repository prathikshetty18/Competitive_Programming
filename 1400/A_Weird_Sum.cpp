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

bool comp1(pair<ll, ll> &a, pair<ll, ll> &b){

    return a.ff < b.ff;
}

bool comp2(pair<ll, ll> &a, pair<ll, ll> &b){

    return a.ss < b.ss;
}

void solve(map<ll, vpll> &mat, ll &n, ll &m){

    ll tot = 0;

    for(auto &[col, vec] : mat){

        sort(all(vec), comp1);

        ll pre = 0, ind = 1;

        for(auto &[fi, se] : vec){

            // cout << fi << ", " << se << nl;

            pre += fi;
            tot += ind * fi - pre;

            ind++;
        }  

        sort(all(vec), comp2);

        pre = 0, ind = 1;

        for(auto &[fi, se] : vec){

            pre += se;
            tot += ind * se - pre;

            ind++;
        }  

        // break;

    }

    cout << tot << nl;

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;

    while(t--){

        ll n, m;
        
        cin >> n >> m;

        map<ll, vpll> mat;

        for(ll i = 0; i < n; i++){

            for(ll j = 0; j < m; j++){
            
                ll col; cin >> col;

                mat[col].pb({i, j});
            }
        }   

        solve(mat, n, m);
    }
}

