#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> 
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;    // find_by_order(x) -> Elements less than x, order_of_key(x) -> xth smallest element

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

void solve(string &s1, ll &n){

    string s = "0";

    s = s.append(s1);

    ll ans = n;

    vll pre01 (n+1, 0), pre10 (n+1, 0);

    bool ifone = false; 

    for(ll i = 1; i <= n; i++){

        if(s[i] == '1') ifone = true;
    
        if(s[i] != s[i-1]) ans++;

        if(s[i-1] == '0' && s[i] == '1') pre01[i] = 1 + pre01[i-1];
        else pre01[i] = pre01[i-1];
        if(s[i-1] == '1' && s[i] == '0') pre10[i] = 1 + pre10[i-1];
        else pre10[i] = pre10[i-1];
    }

    // cout << ans << nl;

    bool red = false;

    for(ll i = 1; i < n; i++){

        if(pre01[i] >= 1 && (pre01[n] - pre01[i+1] >= 1)){

            // cout << "HEREF: " << " i: " << i << nl;

            ans -= 2;
            red = true;
            break;
        }
        else if(pre10[i] >= 1 && (pre10[n] - pre10[i+1] >= 1)){

            // cout << "HERES: " << " i: " << i << nl;


            ans -= 2;
            red = true;
            break;
        }
    }

    // print(pre01);
    // print(pre10);

    if(!red && ifone && s[n] == '0'){
        
        // cout << "here" << nl;
        ans -= 1;
    }

    cout << ans << nl;

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

