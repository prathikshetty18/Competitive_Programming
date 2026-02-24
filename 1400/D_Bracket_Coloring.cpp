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

void solve(string &s, ll &n){

    ll cnt = 0;
    vll ans;

    vector<bool> vis (3, false);
    vector<ll> col(3, 2);

    

    for(ll i = 0; i < n; i++){

        if(s[i] == '(') cnt++;
        else if(s[i] == ')') cnt--;

        if(cnt > 0){

            if(vis[1] == false && vis[2] == false){

                col[1] = 1;
            }
            vis[1] = true;

            ans.pb(col[1]);
        }
        else if(cnt < 0){

            if(vis[1] == false && vis[2] == false){

                col[2] = 1;
            }
            vis[2] = true;
            ans.pb(col[2]);
        }
        else if(cnt == 0) ans.pb(ans.back());
    }

    if(cnt != 0){

        cout << -1 << nl;
    }
    else if(vis[1] && vis[2]){

        cout << 2 << nl;
        print(ans);
    }
    else{

        cout << 1 << nl;
        print(ans);
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while(t--){

        ll n;
        
        cin >> n;

        string s;

        cin >> s;

        solve(s, n);
    }
}

