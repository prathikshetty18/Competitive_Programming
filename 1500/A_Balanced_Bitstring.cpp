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
#define vvll vector<vll>
#define vvvll vector<vvll>
#define vpll vector<pair<ll, ll>>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define print(v) for(auto ele : v) cout << ele << sp; cout << nl;
#define mod 1000000007
ll mod_add(ll a, ll b, ll m = mod) { return ((a % m) + (b % m)) % m; }
ll mod_mul(ll a, ll b, ll m = mod) { return ((a % m) * (b % m)) % m; }
ll ceil_div(ll a, ll b){ return a/b + (a%b != 0); }

void solve(string &s, ll &n, ll &k){

    ll ones = 0, zeros = 0;

    for(ll i = 0; i < k; i++){

        ll temp = -1;
    
        for(ll j = i; j < n; j += k){
        
            if(s[j] == '?') continue;
            else if(s[j] == '0' && temp == -1) temp = 0;
            else if(s[j] == '1' && temp == -1) temp = 1;
            else if(s[j] - '0' != temp){

                cout << "NO" << nl;
                return;
            }
        }

        if(temp != -1){

            ones += (temp == 1);
            zeros += (temp == 0);
        }
    }

    if(ones > k/2 || zeros > k/2){

        cout << "NO" << nl;
        return;
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

        ll n, k;
        
        cin >> n >> k;

        string s;

        cin >> s;

        solve(s, n, k);
    }
}

