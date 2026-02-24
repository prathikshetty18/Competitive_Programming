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

void solve(vll &un, vll &st, map<ll, vll> &mp, map<ll, vll> &pre, ll &n){

    for(ll k = 1; k <= n; k++){

        // cout << mp.size() << nl;

        ll curr = 0;

        for(auto it = mp.begin(); it != mp.end(); ){
            
            ll uniName = it->first;
            vll &stu = it->second;

            ll m = stu.size();
            ll ex = m % k;

            curr += pre[uniName][m] - pre[uniName][ex];

            if(ex == m)
                it = mp.erase(it); // assign it back after erasing otherwise you get segfault, this is why for each loop fails and gives segfault
            else
                ++it;
        }

        // for(auto &[uniName, stu] : mp){

        //     ll m = stu.size();
        //     ll ex = m % k;

        //     curr += pre[uniName][m] - pre[uniName][ex];

        //     if(ex == m) mp.erase(uniName);
        // }

        cout << curr << sp;
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

        vll un (n), st (n);

        map<ll, vll> mp;
        map<ll, vll> pre;

        for(ll i = 0; i < n; i++) cin >> un[i];
        for(ll i = 0; i < n; i++) cin >> st[i];

        for(ll i = 0; i < n; i++){
        
            mp[un[i]].pb(st[i]);
        }

        for(auto uni : mp){

            sort(all(uni.second));

            ll m = uni.second.size();

            pre[uni.ff].resize(m+1, 0);

            for(ll i = 0; i < m; i++){
            
                pre[uni.ff][i+1] = uni.ss[i] + pre[uni.ff][i];
            }

            // cout << m << nl;

            // print(uni.ss);
            // print(pre[uni.ff]);
        }

        solve(un, st, mp, pre, n);
    }
}

