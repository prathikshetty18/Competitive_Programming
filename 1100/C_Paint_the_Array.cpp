#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sp " "
#define nl  "\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define print(v) for(auto ele : v) cout << ele << sp; cout << nl;
#define mod 1000000007

void solve(vector<ll> &v, ll &n){

    ll hcf1 = 0;
    ll hcf2 = 0;

    for(ll i = 0; i < n; i++){
    
        if(i % 2){

            hcf2 = gcd(hcf2, v[i]);
        }
        else{
            
            hcf1 = gcd(hcf1, v[i]);
        }
    }

    bool bool1 = false, bool2 = false;

    for(ll i = 0; i < n; i++){
    
        if(i % 2){

            if(v[i] % hcf1 == 0) bool1 = true;
        }
        else{
            
            if(v[i] % hcf2 == 0) bool2 = true;
        }
    }

    if(!bool1){

        cout << hcf1 << nl;
    }
    else if(!bool2){
        
        cout << hcf2 << nl;
    }
    else{

        cout << 0 << nl;
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){

        ll n;
        
        cin >> n;

        vector<ll> v (n);

        for(ll i = 0; i < n; i++) cin >> v[i]; 

        solve(v, n);
    }
}

