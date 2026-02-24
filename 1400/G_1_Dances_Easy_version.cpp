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

void solve(vll &a, vll &b, ll &n){

    sort(all(a));
    sort(all(b));

    ll l1 = 0, l2 = 0, r1 = n-1, r2 = n-1, cnt = 0;

    while(l1 <= r1){

        if(a[l1] < b[l2]){

            l1++;
            l2++;
        }
        else{

            l2++;
            r1--;
            cnt++;
        }
    }

    cout << cnt << nl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while(t--){

        ll n, m;
        
        cin >> n >> m;

        vll a (n, 1), b (n);

        for(ll i = 1; i < n; i++) cin >> a[i]; 
        for(ll i = 0; i < n; i++) cin >> b[i]; 

        solve(a, b, n);
    }
}

