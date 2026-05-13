#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> 
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;    // find_by_order(x) -> Elements less than x, order_of_key(x) -> xth smallest element

#define ll long long
#define ld long double
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

bool isPossible(string &s, ll &n, ll &len, ll &k, vll &countA, vll &countB){

    // debug("IN HELPER");

    ll l = 0, r = len - 1;

    while(r < n){

        ll currA = countA[r];
        if(l > 0) currA -= countA[l-1];
        
        ll currB = countB[r];
        if(l > 0) currB -= countB[l-1];
        
        // debug(l, r, currA, currB);

        if(min(currA, currB) <= k){
            return true;
        }

        l++;
        r++;
    }

    return false;
}

void solve(string &s, ll &n, ll &k){

    vll countA (n), countB (n);

    countA[0] = (s[0] == 'a');
    countB[0] = (s[0] == 'b');

    for(ll i = 1; i < n; i++){
    
        countA[i] = countA[i-1] + (s[i] == 'a');
        countB[i] = countB[i-1] + (s[i] == 'b');
    }

    ll l = 1, r = n;

    while(l <= r){

        // debug(l, r);

        ll mid = l + (r - l) / 2;

        if(isPossible(s, n, mid, k, countA, countB)){

            l = mid + 1;
        }
        else r = mid - 1;
    }

    cout << r << nl;
    return;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;

    while(t--){

        ll n, k;
        
        cin >> n >> k;

        string s;

        cin >> s; 

        solve(s, n, k);
    }
}

