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

void solve(){

    ll name1 = 1, name2 = 2;
    string s = "yoo";
    bool yo = true;
    pair<ll, ll> p = {1, 2};

    map<ll, ll> mp;

    mp[1] = 1;
    mp[2] = 2;
    mp[3] = 3;
    mp[4] = 4;

    mp[5] = 5;
    mp[6] = 6;
    mp[7] = 7;
    mp[8] = 8;

    mp[9] = 9;
    mp[10] = 10;
    mp[11] = 11;
    mp[12] = 12;

    vvll newname (3, vll (3));
    newname[0][0] = 1;
    newname[0][1] = 2;
    newname[0][2] = 3;
    newname[1][0] = 4;
    newname[1][1] = 5;
    newname[1][2] = 6;
    newname[2][0] = 7;
    newname[2][1] = 8;
    newname[2][2] = 9;

    vector<ll> v = {1, 2, 3};
    vector<ll> v1;
    multiset<ll> stt = {1, 2, 34, 34};

    vvvll mat = {{{1, 2},{3, 4}}, {{5, 6},{7, 8}}};

    string s1 = "hello";

    // debug(s1, mat[1][1], name1, name2);
    debug(stt); 
    // print(v[0])
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while(t--){



        solve();
    }
}
