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

map<ll, ll> toAdd;

void solve(vll &v, ll &n, ll &flag, set<ll> &allowed){

    if(flag){

        for(ll i = 0; i < n; i++){
        
            if(!allowed.count(v[i])){

                cout << "No\n";
                return;
            }
        }

        cout << "Yes\n";
        return;
    }

    ll rem = (v[0] + toAdd[v[0] % 10]) % 20;

    for(ll i = 1; i < n; i++){
    
        ll curr = (v[i] + toAdd[v[i] % 10]) % 20;

        if(curr != rem){

            cout << "No\n";
            return;
        }
    }

    cout << "Yes\n";
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    toAdd[1] = 1;
    toAdd[2] = 0;
    toAdd[3] = 9;
    toAdd[4] = 18;
    toAdd[6] = 6;
    toAdd[7] = 25;
    toAdd[8] = 14;
    toAdd[9] = 23;

    while(t--){

        ll n, flag = 0;

        set<ll> allowed;
        
        cin >> n;

        vll v (n);

        for(ll i = 0; i < n; i++){
            
            cin >> v[i]; 

            if(!flag && v[i] % 10 == 0){

                flag = 1;
                allowed.insert(v[i]);
                allowed.insert(v[i]-5);
            }
            else if(!flag && v[i] % 5 == 0){

                flag = 1;
                allowed.insert(v[i]);
                allowed.insert(v[i]+5);
            }
        }

        solve(v, n, flag, allowed);
    }
}

