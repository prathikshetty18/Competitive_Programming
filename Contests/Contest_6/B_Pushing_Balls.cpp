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

void solve(vector<string> &mat, ll &n, ll &m){

    int seenZero = 0;

    vector<vector<ll>> vis (n, vector<ll> (m, 0));

    for(ll i = 0; i < m; i++){

        seenZero = 0;

        for(ll j = 0; j < n; j++){
            

            if(mat[j][i] == '0'){

                seenZero = 1;
                vis[j][i] += seenZero;
            }
            else{

                vis[j][i] += seenZero;
            }
        }
    }

    for(ll i = 0; i < n; i++){

        seenZero = 0;

        for(ll j = 0; j < m; j++){
            

            if(mat[i][j] == '0'){

                seenZero = 1;
                vis[i][j] += seenZero;
            }
            else{

                vis[i][j] += seenZero;
            }

            if(vis[i][j] == 2 && mat[i][j] == '1'){

                cout << "NO" << nl;
                return;
            }
        }
    }


    cout << "YES" << nl;
    return;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while(t--){

        ll n, m;
        
        cin >> n >> m;

        vector<string> mat (n);

        for(ll i = 0; i < n; i++) cin >> mat[i]; 

        solve(mat, n, m);
    }
}

