#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sp " "
#define nl  "\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define print(v) for(auto ele : v) cout << ele << sp; cout << nl;
#define mod 1000000007

void solve(vector<ll> &v, ll &n, ll &s){

    ll l = 0;
    ll r = 0;

    ll mini = LLONG_MAX;

    ll sum = 0;

    while(r < n){

        // handle invalid

        while(sum > s){

            if(v[l] == 1) sum--;
            l++;
        }


        if(v[r] == 1) sum++;
        
        if(sum == s){
            
            // cout << "INSIDE l: " << l << " r: " << r << nl;
            
            ll left = l;
            ll right = n - 1 - r;
            
            mini = min(mini, left + right);
        }

        r++;
    }

    while(sum > s){

        if(v[l] == 1) sum--;
        l++;
    }

    if(sum == s){
            
        // cout << "INSIDE l: " << l << " r: " << r << nl;
        
        ll left = l;
        ll right = n - r;
        
        mini = min(mini, left + right);
    }

    if(mini == LLONG_MAX) cout << -1 << nl;
    else cout << mini << nl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while(t--){

        ll n, s;
        
        cin >> n >> s;

        vector<ll> v (n);

        for(ll i = 0; i < n; i++) cin >> v[i]; 

        solve(v, n, s);
    }
}

