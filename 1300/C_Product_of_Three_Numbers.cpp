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
#define vpll vector<pair<ll, ll>>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define print(v) for(auto ele : v) cout << ele << sp; cout << nl;
#define mod 1000000007
ll mod_add(ll a, ll b, ll m = mod) { return ((a % m) + (b % m)) % m; }
ll mod_mul(ll a, ll b, ll m = mod) { return ((a % m) * (b % m)) % m; }
ll ceil_div(ll a, ll b){ return a/b + (a%b != 0); }

void solve(ll &n){

    vll ans;
    ll org = n;
    ll i = 2;

    for(; i*i <= n; i++){

        if(n % i == 0){

            ans.push_back(i);
            n /= i;
            i++;
            break;
        }
    }

    for(; i*i <= n; i++){

        if(n % i == 0){

            ans.push_back(i);
            n /= i;
            break;
        }
    }

    ll rem = 1;
    
    if(ans.size() == 2) rem  = org/(ans[0] * ans[1]);

    if(rem > 1 && rem != ans[0] && rem != ans[1]){

        cout << "YES\n";
        cout << ans[0] << sp << ans[1] << sp << rem << nl;
    }
    else{

        cout << "NO\n";
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

        solve(n);
    }
}